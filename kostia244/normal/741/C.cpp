#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
using ll = long long;
using namespace std;
const int maxn = 1<<18;
int n, to[maxn], F[maxn], vis[maxn], T[maxn];
void dfs(int v,int col = 1) {
	if(vis[v]) return;
	vis[v] = col;
	dfs(v^1, col^3);
	dfs(to[v], col^3);
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int f, t, i = 0; i < n; i++) {
		cin >> F[i] >> T[i];
		to[F[i]] = T[i], to[T[i]] = F[i];
	}
	for(int i = 1; i <= 2*n; i++) dfs(i);
	for(int i = 0; i < n; i++)
		cout << vis[F[i]] << " " << vis[T[i]] << endl;

}
//?VK
//??V
//K?