#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("C.inp","r",stdin)
#define OUTPUT freopen("C.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=1e5+10;

int n,m,w[N],rw[N],v[N][2],h[2][N],q[N],q2[N],g[N],way[2];
vector <int> e[N];

template <class T>
bool minimize(T &x,T y){
    if (x>y) x=y;else return 0;
    return 1;
}
int BFS(int st){
    int top=1,bot=1;
    q[1]=st;
    g[st]=1;
    while (top<=bot){
        int x=q[top++];
        for(auto i:e[x]){
            int y=v[i][0]+v[i][1]-x;
            if (g[y]) continue;
            g[y]=1;
            q[++bot]=y;
        }
    }
    return bot;
}
int BFS2(int st,int type){
    int top=1,bot=1;
    q2[1]=st;
    h[type][st]=type;
    int ans=0;
    while (top<=bot){
        int x=q2[top++];
        ans+=h[type][x];
        for(auto i:e[x]){
            int y=v[i][0]+v[i][1]-x;
            if (h[type][y]==-1){
                h[type][y]=(h[type][x]^rw[i]);
                q2[++bot]=y;
            }
            if ((h[type][x]^rw[i])!=h[type][y]) return n+1;
        }
    }
    return ans;
}
void prepare(){
    scanf("%d%d",&n,&m);
    FOR(i,1,m){
        int x,y;
        char ch;
        scanf("%d%d %c",&x,&y,&ch);
        w[i]=(ch=='R');
        v[i][0]=x;v[i][1]=y;
        e[x].push_back(i);
        e[y].push_back(i);
    }
}
int solve(int type,int pha){
    FOR(i,1,m) rw[i]=w[i]!=pha;
    memset(h,-1,sizeof(h));
    memset(g,0,sizeof(g));
    vector <int> ans;
    FOR(st,1,n) if (!g[st]){
        int n1=BFS(st);
        FOR(i,0,1) way[i]=BFS2(st,i);
        int idx=way[1]<way[0];
        if (way[idx]==n+1) return n+1;
        FOR(i,1,n1) if (h[idx][q[i]]) ans.push_back(q[i]);
    }
    if (type){
        printf("%d\n",ans.size());
        for(auto i:ans) printf("%d ",i);
    }
    return int(ans.size());
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    int ans=solve(0,0),sel=0;
    if (minimize(ans,solve(0,1))) sel=1;
    if (ans==n+1){
        printf("-1");
        return 0;
    }
    solve(1,sel);
}