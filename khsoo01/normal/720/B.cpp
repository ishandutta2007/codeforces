#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

const int N = 100005;

int n, m, dfn[N], low[N], op[N], cc, bc, ans;
bool vis[N];

vector<int> bcc[N], mat[N];
vector<pii> adj[N];

void calc (int C, int P) {
	dfn[C] = low[C] = ++cc;
	for(auto &T : adj[C]) {
		int A, B;
		tie(A, B) = T;
		if(A == P) continue;
		if(!dfn[A]) {
			calc(A, C);
			low[C] = min(low[C], low[A]);
		}
		else {
			low[C] = min(low[C], dfn[A]);
		}
	}
}

void getbcc (int C, int X) {
	if(X) bcc[X].push_back(C);
	vis[C] = true;
	for(auto &T : adj[C]) {
		int A, B;
		tie(A, B) = T;
		if(vis[A]) continue;
		if(low[A] >= dfn[C]) {
			bcc[++bc].push_back(C);
			getbcc(A, bc);
		}
		else getbcc(A, X);
	}
}

bool match (int I) {
	vis[I] = true;
	for(auto &T : mat[I]) {
		if(!op[T] || (!vis[op[T]] && match(op[T]))) {
			op[T] = I;
			return true;
		}
	}
	return false;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) {
		int A, B, C;
		scanf("%d%d%d",&A,&B,&C);
		adj[A].push_back({B, C});
		adj[B].push_back({A, C});
	}
	calc(1, 0);
	getbcc(1, 0);
	for(int i=1;i<=bc;i++) {
		int S = (int)bcc[i].size();
		for(int j=0;j<S;j++) {
			for(auto &T : adj[bcc[i][j]]) {
				int A, B;
				tie(A, B) = T;
				if(A == bcc[i][(j+1)%S]) {
					mat[i].push_back(B);
					break;
				}
			}
		}
	}
	for(int i=1;i<=bc;i++) {
		int S = (int)bcc[i].size();
		for(int j=0;j<S-1;j++) {
			fill(vis+1, vis+1+bc, false);
			ans += match(i);
		}
	}
	printf("%d\n",ans);
}