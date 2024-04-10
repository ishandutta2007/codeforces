#include<bits/stdc++.h>
#define MAX   200200
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
long long a[MAX],sl[MAX],sr[MAX];
int n,k,x;
void init(void) {
    cin>>n>>k>>x;
    FOR(i,1,n) cin>>a[i];
    FOR(i,1,n) sl[i]=sl[i-1]|a[i];
    FORD(i,n,1) sr[i]=sr[i+1]|a[i];
}
void process(void) {
    long long res=0;
    long long mul=1;
    REP(love,k) mul*=x;
    FOR(i,1,n) res=max(res,sl[i-1]|sr[i+1]|(a[i]*mul));
    cout<<res<<endl;
}
int main(void) {
    init();
    process();
    return 0;
}