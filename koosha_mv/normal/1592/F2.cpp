#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) builtin_popcount(x)
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=510;

int n,m,ans,res,a[N][N],r[N][N],c[N][N],mark[N][N];

int n1,n2,edges,last[N*N],Prev[N*N],head[N*N],l[N][N],u[N][N];
int matching[N*N], dist[N*N], Q[N*N];
bool used[N*N],vis[N*N];
string s[N];
 
void init(int _n1, int _n2) {
    n1 = _n1;
    n2 = _n2;
    edges = 0;
    fill(last, last + n1, -1);
}
 
void addEdge(int u, int v) {
    head[edges] = v;
    Prev[edges] = last[u];
    last[u] = edges++;
}
 
void bfs() {
    fill(dist, dist + n1, -1);
    int sizeQ = 0;
    for (int u = 0; u < n1; ++u) {
        if (!used[u]) {
            Q[sizeQ++] = u;
            dist[u] = 0;
        }
    }
    for (int i = 0; i < sizeQ; i++) {
        int u1 = Q[i];
        for (int e = last[u1]; e >= 0; e = Prev[e]) {
            int u2 = matching[head[e]];
            if (u2 >= 0 && dist[u2] < 0) {
                dist[u2] = dist[u1] + 1;
                Q[sizeQ++] = u2;
            }
        }
    }
}
 
bool dfs(int u1) {
    vis[u1] = true;
    for (int e = last[u1]; e >= 0; e = Prev[e]) {
        int v = head[e];
        int u2 = matching[v];
        if (u2 < 0 || !vis[u2] && dist[u2] == dist[u1] + 1 && dfs(u2)) {
            matching[v] = u1;
            used[u1] = true;
            return true;
        }
    }
    return false;
}
 
int maxMatching() {
    fill(used, used + n1, false);
    fill(matching, matching + n2, -1);
    for (int res = 0;;) {
        bfs();
        fill(vis, vis + n1, false);
        int f = 0;
        for (int u = 0; u < n1; ++u)
            if (!used[u] && dfs(u))
                ++f;
        if (!f)
            return res;
        res += f;
    }
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	init(N-2,N-2);
	f(i,1,n+1){
		string s;
		cin>>s;
		s=' '+s;
		f(j,1,m+1){
			a[i][j]=(s[j]=='B');
		}
	}
	f_(i,n,1){
		f_(j,m,1){
			a[i][j]^=c[i][j];
			if(a[i][j]){
				mark[i][j]=1;
				c[i][j]^=1;
				ans++;
			}
			c[i][j-1]^=c[i][j];
			c[i-1][j]^=c[i][j];
			c[i-1][j-1]^=c[i][j];
		}
	}
	f(i,1,n){
		f(j,1,m){
			if(mark[i][j] && mark[i][m] && mark[n][j]){
				addEdge(i,j);
			}			
		}
	}
	res=maxMatching();
	ans-=res;
	if(res&1){
		if(mark[n][m]) ans--;
		else ans++;
	}
	cout<<ans;
}