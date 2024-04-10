#include <bits/stdc++.h>
using namespace std;

long long powf(long long k, long long x){
    if(x==0)return 1;
    long long r=1;
    while(x>0){
        if(x&1){
            r=(r*k)%1000000007;
        }
        k= (k*k)%1000000007;
        x>>=1;
    }
    return r;
}
int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    long long n,y=2;
    cin>>n;
    if(n==0)cout<<1;
    else
    cout<<((powf(y,2*n-1)+powf(y,n-1)))%1000000007;
    return 0;
}