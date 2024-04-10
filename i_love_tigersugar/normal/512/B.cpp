#include<bits/stdc++.h>
#define MAX   333
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
map<int,int> dp[MAX];
pair<int,int> a[MAX];
int n;
void minimize(int &x,const int &y) {
    if (x>y) x=y;
}
int gcd(int a,int b) {
    while (true) {
        if (a==0) return (b);
        if (b==0) return (a);
        if (a>b) a%=b; else b%=a;
    }
}
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i].fi);
    FOR(i,1,n) scanf("%d",&a[i].se);
    sort(a+1,a+n+1);
}
void update(map<int,int> &mp,int key,int val) {
    if (mp.find(key)==mp.end()) mp[key]=val;
    else minimize(mp[key],val);
}
void optimize(void) {
    dp[0][0]=0;
    REP(i,n) FORE(it,dp[i]) {
        int cur=it->fi;
        int cost=it->se;
        update(dp[i+1],cur,cost);
        update(dp[i+1],gcd(cur,a[i+1].fi),cost+a[i+1].se);
    }
    printf("%d\n",dp[n].find(1)==dp[n].end()?-1:dp[n][1]);
}
int main(void) {
    init();
    optimize();
    return 0;
}