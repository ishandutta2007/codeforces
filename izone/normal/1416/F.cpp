#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#define N_ 101000
#define pii pair<int,int>
using namespace std;

int n, m, sum;

namespace MaxFlow{
	const int MV = 100200;
	const int ME = 2000400;
	const int INF = 1e9;
	int dis[MV];
	int st[MV], en[ME<<1], nxt[ME<<1], flow[ME<<1], ce;
	int start[MV];

    int TS, TT;
    
	void init() {
		memset(st, 0, sizeof st);
		ce = 1;
        sum=0;
	}
	void addE(int s, int e, int f) {
        if(s==TS)sum+=f;
        if(!f)return;
		++ce; nxt[ce] = st[s]; st[s] = ce; en[ce] = e; flow[ce] = f;
		++ce; nxt[ce] = st[e]; st[e] = ce; en[ce] = s; flow[ce] = 0;
	}
	void addLRE(int s, int e, int l, int r) {
        addE(TS, e, l);
        addE(s, TT, l);
        addE(s, e, r-l);
	}
	int que[MV];
	int bfs(int N, int S, int E) {
		for(int i=1;i<=N;i++) dis[i] = -1;
		dis[S] = 0;
		int *fr = que, *re = que;
		*fr++ = S;
		while(fr != re) {
			int t = *re++;
			for(int i=st[t];i;i=nxt[i]) if(flow[i] > 0 && dis[en[i]] == -1) {
				dis[en[i]] = dis[t] + 1;
				*fr++ = en[i];
			}
		}
		return dis[E] != -1;
	}
	
	int dfs(int x, int E, int f) {
		if(x == E) return f;
		for(int &i=start[x],t;i;i=nxt[i]) if(flow[i] > 0 && dis[en[i]] == dis[x] + 1 && (t = dfs(en[i], E, min(f, flow[i]))) > 0){
			flow[i] -= t;
			flow[i^1] += t;
			return t;
		}
		return 0;
	}
	
	int Get(int N, int S, int E) {
		int res = 0;
		while(bfs(N, S, E)) {
			for(int i=1;i<=N;i++) start[i] = st[i];
			while(1) {
				int t = dfs(S, E, INF);
				if(t == 0) break;
				res += t;
			}
		}
		return res;
	}
    vector<pii> trace(){
        int i, j;
        vector<pii>V;
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                if((i+j)%2)continue;
                int x=  (i-1)*m+j;
                for(int y = st[x];y;y=nxt[y]){
                    if(flow[y]==0 && en[y] <= n*m){
                        V.push_back({x,en[y]});
                    }
                }
            }
        }
        return V;
    }
}


int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1}, cnt;
vector<vector<int>>w, Num, Res, Ans, chk;
bool Valid(int x, int y){
    return 1<=x&&x<=n&&1<=y&&y<=m;
}
void DFS(int x, int y){
    int i;
    Num[x][y]=cnt;
    for(i=0;i<4;i++){
        int tx=x+dx[i],ty=y+dy[i];
        if(Valid(tx,ty)&&Num[tx][ty]==0&&w[x][y]==w[tx][ty]){
            DFS(tx,ty);
        }
    }
}
int ord(int x, int y){
    return (x-1)*m+y;
}
pii reord(int a){
    a--;
    return pii(a/m+1,a%m+1);
}
void Solve(){
    int i, j;
    scanf("%d%d",&n,&m);
    w.resize(n+1);
    for(i=0;i<=n;i++){
        w[i].resize(m+1);
    }
    for(i=0;i<=n;i++)for(j=0;j<=m;j++)w[i][j]=0;
    Num = w;
    Res = w;
    Ans = w;
    chk = w;
    int ckk=0;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%d",&w[i][j]);
            if(w[i][j]==1)ckk=1;
        }
    }
    if(ckk){
        puts("NO");
        return;
    }
    cnt=0;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(!Num[i][j]){
                cnt++;
                DFS(i,j);
            }
        }
    }
    //puts("?!");
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            for(int k=0;k<4;k++){
                int x = i+dx[k], y = j+dy[k];
                if(Valid(x,y) && w[i][j]>w[x][y]){
                    chk[i][j]=1;
                    Res[i][j]=k;
                    Ans[i][j]=w[i][j]-w[x][y];
                }
            }
        }
    }
    MaxFlow::init();
    MaxFlow::TS = n*m+3, MaxFlow::TT = n*m+4;
    int source = n*m+1, sink = n*m+2, ss = 0;

    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            int low = 0;
            if(!chk[i][j]){
                low = 1;
            }
            if((i+j)%2==0){
                MaxFlow::addLRE(source, ord(i,j), low, 1);
            }
            else{
                MaxFlow::addLRE(ord(i,j), sink, low, 1);
            }
            if(j<m && Num[i][j]==Num[i][j+1]){
                int a = ord(i,j), b = ord(i,j+1);
                if((i+j)%2==1)swap(a,b);
                MaxFlow::addLRE(a,b,0,1);
            }
            if(i<n && Num[i][j]==Num[i+1][j]){
                int a = ord(i,j), b = ord(i+1,j);
                if((i+j)%2==1)swap(a,b);
                MaxFlow::addLRE(a,b,0,1);
            }
        }
    }
    MaxFlow::addE(sink,source,9999999);
    int f = MaxFlow::Get(MaxFlow::TT,MaxFlow::TS,MaxFlow::TT);
    if(sum != f){
        puts("NO");
        return;
    }
    vector<pii>tp = MaxFlow::trace();

    for(auto &t : tp){
        pii t1 = reord(t.first), t2 =reord(t.second);
        int tx = t2.first-t1.first, ty = t2.second-t1.second;
        for(int k=0;k<4;k++){
            if(dx[k]==tx && dy[k]==ty){
                Res[t1.first][t1.second] = k;
            }
            if(dx[k]==-tx && dy[k]==-ty){
                Res[t2.first][t2.second] = k;
            }
        }
        Ans[t1.first][t1.second] = w[t1.first][t1.second]/2;
        Ans[t2.first][t2.second] = (w[t1.first][t1.second]+1)/2;
    }
    puts("YES");
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            printf("%d ",Ans[i][j]);
        }
        puts("");
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            printf("%c ","DRUL"[Res[i][j]]);
        }
        puts("");
    }

}
int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}