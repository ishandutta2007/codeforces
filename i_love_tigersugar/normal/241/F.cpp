//This solution is based on rng_58's solution
#include<cstdio>
#include<cstring>
#include<vector>
#define MAX   111
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
typedef pair<int,int> ii;
inline int nextint(void) {
    int x;
    scanf("%d",&x);
    return (x);
}
inline ii nextii(void) {
    int x=nextint();
    int y=nextint();
    return (ii(x,y));
}
char a[MAX][MAX];
int m,n,q,l;
ii add[MAX],sta,fin;
char way[MAX*MAX];
void init(void) {
    m=nextint();
    n=nextint();
    q=nextint();
    FOR(i,1,m) scanf("%s",a[i]+1);
    FOR(i,1,m) FOR(j,1,n) if ('a'<=a[i][j] && a[i][j]<='z') add[a[i][j]-'a']=ii(i,j);
    sta=nextii();
    scanf("%s",way+1);
    l=strlen(way+1);
    fin=nextii();
}
inline int togo(int x,int y) {
    if ('0'<=a[x][y] && a[x][y]<='9') return (a[x][y]-'0');
    return (1);
}
void process(void) {
    ii cur,next;
    cur=sta;
    vector<ii> v;
    FOR(i,1,l+1) {
        next=i>l?fin:add[way[i]-'a'];
        if (cur.fi==next.fi) {
            FOR(y,cur.se+1,next.se) v.push_back(ii(cur.fi,y));
            FORD(y,cur.se-1,next.se) v.push_back(ii(cur.fi,y));
        }
        else {
            FOR(x,cur.fi+1,next.fi) v.push_back(ii(x,cur.se));
            FORD(x,cur.fi-1,next.fi) v.push_back(ii(x,cur.se));
        }
        cur=next;
    }
    cur=sta;
    FORE(it,v) {
        if (togo(cur.fi,cur.se)>q) {
            printf("%d %d",cur.fi,cur.se);
            return;
        }
        q-=togo(cur.fi,cur.se);
        cur=*it;
    }
    printf("%d %d",fin.fi,fin.se);
}
int main(void) {
#ifndef ONLINE_JUDGE
    freopen("tmp.txt","r",stdin);
#endif
    init();
    process();
    return 0;
}