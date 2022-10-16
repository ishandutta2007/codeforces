#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
using namespace std;
int main(void) {
    ios::sync_with_stdio(true);
    int k,n,w;
    cin>>k>>n>>w;
    long long sum=0;
    FOR(i,1,w) sum+=i*k;
    cout<<max(0LL,sum-n)<<endl;
    return 0;
}