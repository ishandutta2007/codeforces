//#pragma GCC optimize("trapv")
//#pragma GCC optimize("O2")
//#pragma GCC target("avx,avx2,sse,sse2,tune=native,fma")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
using vpi = vector<pi>;
const int maxn = 2e5 + 30;
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
int n, a[maxn];
vector<vi> g;
int vis[maxn];
int ans = 0;
int r = -1, c = 1;
void dfs(int v) {
	int hui = c;
	vis[v] = hui;
//	cout << v << " " << c << " " << (vis[v]=c) << "aslkdfdasjf\n";
	for(auto i : g[v]) {
		if(!vis[i])
			 dfs(i);
		else if(vis[i]==c){
			if(r==-1) r = i;
			if(a[i]!=r)a[i] = r, ans++;//, cout << v << "-> BAD" << i << "\n";
		}
//		 cout << v << "->>"<<i<<"("<<vis[i]<<'\n';
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	g.resize(n+1);
	for(int t, i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i]==i) r = i;
	}
	for(int i = 1; i <= n; i++){
		if(i!=r)
		g[a[i]].pb(i);
//		cout << a[i] << "->" << i << "\n";
	}
	for(int i = 1; i <= n; i++)
		if(!vis[i]) {
			dfs(i);
			c++;
		}
	for(int i = 1; i <= n; i++) if(i!=r&&a[i]==i) a[i]=r, ans++;
	cout << ans << "\n";
	for(int i = 1; i <= n; i++) cout << a[i] << " ";

}