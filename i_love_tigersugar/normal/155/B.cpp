#include<cstdio>
#include<queue>
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define fi   first
#define se   second
using namespace std;
typedef pair<int,int> ii;
inline int nextint(void) {
    int x;
    scanf("%d",&x);
    return (x);
}
void process(void) {
    priority_queue<ii> q;
    REP(zz,nextint()) {
        ii t;
        t.se=nextint();
        t.fi=nextint();
        q.push(t);
    }
    int left=1;
    int res=0;
    while (!q.empty()) {
        if (left==0) break;
        ii u=q.top();q.pop();
        res+=u.se;
        left+=u.fi-1;
    }
    printf("%d",res);
}
int main(void) {
    process();
    return 0;
}