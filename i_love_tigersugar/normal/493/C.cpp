#include<bits/stdc++.h>
#define MAX   200200
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define fi   first
#define se   second
using namespace std;
const int INF=(int)2e9+7;
int a[MAX],b[MAX];
int m,n;
void init(void) {
    scanf("%d",&m);
    REP(i,m) scanf("%d",&a[i]);
    scanf("%d",&n);
    REP(i,n) scanf("%d",&b[i]);
    sort(a,a+m);
    sort(b,b+n);
}
int score(int a[],int n,int x) {
    int id=upper_bound(a,a+n,x)-a;
    return (2*id+3*(n-id));
}
pair<int,int> choose(int x) {
    int sa=score(a,m,x);
    int sb=score(b,n,x);
    return (make_pair(sa-sb,sa));
}
void process(void) {
    pair<int,int> res(-INF,-INF);
    REP(i,m) res=max(res,choose(a[i]));
    REP(i,n) res=max(res,choose(b[i]));
    res=max(res,choose(0));
    res=max(res,choose(INF));
    printf("%d:%d",res.se,res.se-res.fi);
}
int main(void) {
    init();
    process();
    return 0;
}