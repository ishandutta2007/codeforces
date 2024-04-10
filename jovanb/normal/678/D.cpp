#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long fp(long long  x, long long  y){
    long long res=1;
    while(y>0){
        if(y&1){res*=x;res%=mod;}
        y>>=1;
        x*=x;
        x%=mod;
    }
    return res;
}

int main(){
    unsigned long long a,b,n,x;
    cin >> a >> b >> n >> x;
    if(a==1){
        cout<<(((b*(n%mod))%mod)+x)%mod;
        return 0;
    }
    if(n == 1){
        cout << (a * x + b) % mod << endl;
        return 0;
    }
    unsigned long long br1 = fp(a,n);
    unsigned long long br2 = br1;
    unsigned long long x1 = x % mod;
    br1 = (br1 * x1) % mod;
    unsigned long long voja = fp(a,n);
    voja--;
    unsigned long long h = (a-1);
    br2 = voja % mod;
    br2*=b%mod;
    br2%=mod;
    voja=fp(a-1,mod-2);
    br2*=voja%mod;
    cout << (br1+br2) % mod << endl;
}