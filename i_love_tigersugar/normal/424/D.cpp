#include<bits/stdc++.h>
#define MAX   333
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define FORD(i,b,a) for (int i=(b);i>=(a);i=i-1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define fi   first
#define se   second
using namespace std;
const int INF=(int)1e9+7;
typedef pair<int,int> ii;
int a[MAX][MAX];
int m,n,t,res,tp,tu,td;
int st[MAX],sb[MAX],su[MAX],sd[MAX];
ii top,bot;
inline void update(int k,ii t,ii b) {
    if (res<=k) return;
    res=k;
    top=t;
    bot=b;
}
inline int cost(int x,int y) {
    return ((x>y)*td+(x==y)*tp+(x<y)*tu);
}
void init(void) {
    scanf("%d%d%d%d%d%d",&m,&n,&t,&tp,&tu,&td);
    FOR(i,1,m) FOR(j,1,n) scanf("%d",&a[i][j]);
    res=INF;
}
void chooserow(int x,int y) {
    if (y==x+2) {
        FOR(i,1,n) sd[i]=cost(a[x][i],a[x+1][i]);
        FOR(i,1,n) su[i]=cost(a[x+1][i],a[x][i]);
    }
    FOR(i,1,n-1) {
        st[i]=st[i-1]+cost(a[x][i],a[x][i+1]);
        sb[i]=sb[i-1]+cost(a[y][i+1],a[y][i]);
    }
    FOR(i,1,n) {
        sd[i]+=cost(a[y-1][i],a[y][i]);
        su[i]+=cost(a[y][i],a[y-1][i]);
    }
    set<ii> can;
    FORD(i,n,1) {
        if (!can.empty()) {
            int tmp=st[i-1]+sb[i-1]-su[i];
            set<ii>::iterator it=can.lower_bound(ii(t+tmp,-1));
            if (it!=can.end()) update(it->fi-tmp-t,ii(x,i),ii(y,it->se));
            if (it!=can.begin()) {
                it--;
                update(t-it->fi+tmp,ii(x,i),ii(y,it->se));
            }
        }
        if (i<n) can.insert(ii(st[i]+sb[i]+sd[i+1],i+1));
    }
}
void process(void) {
    FOR(i,1,m-2) FOR(j,i+2,m) chooserow(i,j);
    assert(res<INF);
    printf("%d %d %d %d",top.fi,top.se,bot.fi,bot.se);
}
int main(void) {
#ifndef ONLINE_JUDGE
    freopen("tmp.txt","r",stdin);
#endif
    init();
    process();
    return 0;
}