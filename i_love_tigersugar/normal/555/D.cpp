#include<bits/stdc++.h>
#define MAX   200200
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define fi   first
#define se   second
using namespace std;
pair<int,int> point[MAX];
int n,q,pos[MAX];
void init(void) {
    scanf("%d%d",&n,&q);
    FOR(i,1,n) scanf("%d",&point[i].fi);
    FOR(i,1,n) point[i].se=i;
    sort(point+1,point+n+1);
    FOR(i,1,n) pos[point[i].se]=i;
}
int answer(int x,int len,int dir) {
    //printf("Answer %d %d %d\n",x,len,dir);
    if (len==0) return (x);
    if (n==1) return (n);
    if (dir==1 && x==n) return (answer(x,len,0));
    if (dir==0 && x==1) return (answer(x,len,1));
    if (dir==1) {
        if (point[x+1].fi-point[x].fi>len) {
            if (x==1 || point[x].fi-point[x-1].fi>len) return (x);
            return (answer(x-1,len-(point[x].fi-point[x-1].fi),0));
        }
        int next=upper_bound(point+1,point+n+1,make_pair(point[x].fi+len,MAX))-point-1;
        if (len<2LL*(point[next].fi-point[x].fi)) return (answer(next,len-(point[next].fi-point[x].fi),0));
        int prev=lower_bound(point+1,point+n+1,make_pair(point[next].fi-(len-(point[next].fi-point[x].fi)),-1))-point;
        if (len<2LL*(point[next].fi-point[prev].fi))
            return (answer(prev,len-(2LL*point[next].fi-point[x].fi-point[prev].fi),1));
        return (answer(x,len%(2LL*point[next].fi-2LL*point[prev].fi),dir));
    } else {
        if (point[x].fi-point[x-1].fi>len) {
            if (x==n || point[x+1].fi-point[x].fi>len) return (x);
            return (answer(x+1,len-(point[x+1].fi-point[x].fi),1));
        }
        int prev=lower_bound(point+1,point+n+1,make_pair(point[x].fi-len,-1))-point;
        if (len<2LL*(point[x].fi-point[prev].fi)) return (answer(prev,len-(point[x].fi-point[prev].fi),1));
        int next=upper_bound(point+1,point+n+1,make_pair(point[prev].fi+(len-(point[x].fi-point[prev].fi)),MAX))-point-1;
        if (len<2LL*(point[next].fi-point[prev].fi))
            return (answer(next,len-(point[next].fi+point[x].fi-2LL*point[prev].fi),0));
        return (answer(x,len%(2LL*point[next].fi-2LL*point[prev].fi),dir));
    }
}
void process(void) {
    REP(love,q) {
        int x,l;
        scanf("%d%d",&x,&l);
        int t=answer(pos[x],l,1);
        printf("%d\n",point[t].se);
    }
}
int main(void) {
    init();
    process();
    return 0;
}