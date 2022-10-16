#include<bits/stdc++.h>
#define MAX   222
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
const int INF=(int)1e9+7;
int a[MAX];
int n,k;
void init(void) {
    scanf("%d%d",&n,&k);
    FOR(i,1,n) scanf("%d",&a[i]);
}
int best(int l,int r) {
    priority_queue<int> oth;
    priority_queue<int,vector<int>,greater<int> > chs;
    FOR(i,1,n) {
        if (l<=i && i<=r) chs.push(a[i]);
        else oth.push(a[i]);
    }
    REP(zz,k) if (!chs.empty() && !oth.empty()) {
        int vc=chs.top();
        int vo=oth.top();
        if (vc>=vo) break;
        chs.pop();
        oth.pop();
        chs.push(vo);
        oth.push(vc);
    }
    int ret=0;
    while (!chs.empty()) {
        ret+=chs.top();
        chs.pop();
    }
    return (ret);
}
void process(void) {
    int res=-INF;
    FOR(i,1,n) FOR(j,i,n) res=max(res,best(i,j));
    printf("%d",res);
}
int main(void) {
    init();
    process();
    return 0;
}