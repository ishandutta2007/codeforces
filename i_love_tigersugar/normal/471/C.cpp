#include<bits/stdc++.h>
#define MAX   1000100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
using namespace std;
typedef long long ll;
int main(void) {
    ios::sync_with_stdio(true);
    ll n;
    cin>>n;
    int res=0;
    FOR(k,1,MAX) if ((n+k)%3==0 && 2*n>=3LL*k*k+k) res++;
    cout<<res;
    return 0;
}