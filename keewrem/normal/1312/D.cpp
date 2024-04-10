#include <bits/stdc++.h>
using namespace std;
int N,M;
const long long MOD = 998244353;
long long p2(int a){
    if(a == 0)return 1;
    long long k = p2(a/2);
    if(a&1)return (2*k*k)%MOD;
    else return (k*k)%MOD;
}

long long fexp(int a, long long b){
    if (a==0)return 1;
    long long k = fexp(a/2,b);
    if(a&1)return (((b*k)%MOD)*k)%MOD;
    else return (k*k)%MOD;
}

long long inv(long long a){
    return fexp((int)MOD-2, a);
}

long long fact[200010];
long long bin(int a, int b){
    return ((fact[a]*inv(fact[a-b]))%MOD*inv(fact[b]))%MOD;
}

int main(){
    cin >>N >> M;
    fact[0]=1;
    for(long long i = 1;i < 200010; i++)fact[i]=(fact[i-1]*i)%MOD;
    if(N==2|| M < N-1){cout << "0\n"; return 0;}
    cout << (((bin(M, N-1)*(N-2))%MOD)*p2(N-3))%MOD;
    return 0;
}