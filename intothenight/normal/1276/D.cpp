#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class L, class R>
istream &operator>>(istream &in, pair<L, R> &arr){
    return in >> arr.first >> arr.second;
}
template<class ...Args, template<class...> class T>
istream &operator>>(enable_if_t<!is_same_v<T<Args...>, string>, istream> &in, T<Args...> &arr){
	for(auto &x: arr) in >> x; return in;
}
template<class L, class R>
ostream &operator<<(ostream &out, const pair<L, R> &arr){
    return out << "(" << arr.first << ", " << arr.second << ") ";
}
template<class ...Args, template<class...> class T>
ostream &operator<<(enable_if_t<!is_same_v<T<Args...>, string>, ostream> &out, const T<Args...> &arr){
	for(auto &x: arr) out << x << " "; return out << "\n";
}
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
typedef long long ll;
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<double> vd; typedef vector<string> vs;
typedef pair<int, int> pii; typedef pair<ll, ll> pll; typedef pair<int, ll> pil; typedef pair<ll, int> pli;
typedef vector<pii> vpii; typedef vector<pil> vpil; typedef vector<pli> vpli; typedef vector<pll> vpll;
template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef tuple<ll, ll, ll, ll> tpl; typedef vector<tpl> vtpl;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<vi> adj(n);
	for(int i = 1; i < n; i ++){
		int u, v;
		cin >> u >> v, u --, v --;
		adj[u].push_back(v), adj[v].push_back(u);
	}
	const ll mod = 998244353;
	vl pded(n), talive(n, 1), aded(n), alive(n, 1);
	talive[0] = 0;
	function<void(int, int)> dfs = [&](int u, int p){
		int flag = true;
		for(auto v: adj[u]){
			if(v != p){
				dfs(v, u);
				if(flag){
					tie(pded[u], talive[u], aded[u], alive[u]) = tpl{
						(pded[u] * (pded[v] + aded[v] + alive[v]) + alive[u] * (aded[v] + alive[v])) % mod,
						(talive[u] * (pded[v] + talive[v])) % mod,
						(aded[u] * (pded[v] + talive[v])) % mod,
						(alive[u] * (pded[v] + talive[v])) % mod
					};
				}
				else{
					tie(pded[u], talive[u], aded[u], alive[u]) = tpl{
						(pded[u] * (pded[v] + aded[v] + alive[v])) % mod,
						(talive[u] * (pded[v] + aded[v] + alive[v])) % mod,
						(aded[u] * (pded[v] + aded[v] + alive[v]) + alive[u] * (aded[v] + alive[v])) % mod,
						(alive[u] * (pded[v] + talive[v])) % mod
					};
				}
			}
			else flag = false;
		}
	};
	dfs(0, -1);
	cout << (pded[0] + talive[0] + aded[0] + alive[0]) % mod;
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////