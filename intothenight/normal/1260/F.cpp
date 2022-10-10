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
    return out << arr.first << " " << arr.second << "\n";
}
template<class ...Args, template<class...> class T>
ostream &operator<<(enable_if_t<!is_same_v<T<Args...>, string>, ostream> &out, const T<Args...> &arr){
	for(auto &x: arr) out << x << " "; return out << "\n";
}
#define all(a) a.begin(), a.end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef tuple<ll, ll, ll, ll, ll> tpl;
template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T>
using Ftn = function<T(T, T)>;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

struct CD: vector<vi>{
	int N, root;
	vi dead, sz, par, cpar;
	vector<vi> cchild, dist;
	CD(int N): N(N), dead(N), sz(N), par(N), cchild(N), cpar(N), dist(N){
		this->resize(N);
	}
	void insert(int u, int v){
		(*this)[u].push_back(v);
		(*this)[v].push_back(u);
	}
	void dfs_sz(int u){
		sz[u] = 1;
		for(auto v: (*this)[u]) if(!dead[v] && v != par[u]){
			par[v] = u;
			dfs_sz(v);
			sz[u] += sz[v];
		}
	}
	int centroid(int u){
		par[u] = -1;
		dfs_sz(u);
		int size = sz[u];
		while(1){
			int w = 0, msz = 0;
			for(auto v: (*this)[u]) if(!dead[v] && v != par[u] && msz < sz[v]){
				w = v, msz = sz[v];
			}
			if(msz * 2 <= size) return u;
			u = w;
		}
	}
	void dfs_dist(int u, int p){
		dist[u].push_back(dist[p].back() + 1);
		for(auto v: (*this)[u]) if(!dead[v] && v != p) dfs_dist(v, u);
	}
	void dfs_centroid(int u, int p){
		dead[u = centroid(u)] = true;
		cpar[u] = p;
		if(p != -1) cchild[p].push_back(u);
		else root = u;
		dist[u].push_back(0);
		int d = 0;
		for(auto v: (*this)[u]) if(!dead[v]) dfs_dist(v, u);
		for(auto v: (*this)[u]) if(!dead[v]) dfs_centroid(v, u);
	}
	void init(){
		dfs_centroid(0, -1);
	}
};

struct combi{
	const ll N, mod;
	vl inv, fact, invfact;
	combi(ll N, ll mod):
		N(N), mod(mod), inv(N + 1), fact(N + 1), invfact(N + 1){
		inv[1] = 1, fact[0] = fact[1] = invfact[0] = invfact[1] = 1;
		for(ll i = 2; i <= N; i ++){
			inv[i] = (mod - mod / i * inv[mod % i] % mod) % mod;
			fact[i] = fact[i - 1] * i % mod;
			invfact[i] = invfact[i - 1] * inv[i] % mod;
		}
	}
	ll c(int n, int r){
		return n < r ? 0 : fact[n] * invfact[r] % mod * invfact[n - r] % mod;
	}
	ll p(int n, int r){
		return n < r ? 0 : fact[n] * invfact[n - r] % mod;
	}
	ll h(int n, int r){
		return c(n + r - 1, r);
	}
	ll cat(int n, int k, int m){
		if(m <= 0) return 0;
		else if(k >= 0 && k < m) return c(n + k, k);
		else if(k < n + m) return (c(n + k, k) - c(n + k, k - m) + mod) % mod;
		else return 0;
	}
};

ll modexp(ll b, ll e, const ll &mod){
	ll res = 1;
	for(; e; b = b * b % mod, e /= 2){
		if(e & 1){
			res = res * b % mod;
		}
	}
	return res;
}
ll modinv(ll b, const ll &mod){
	return modexp(b, mod - 2, mod);
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	const ll mod = 1e9 + 7;
	combi c(100000, mod);
	int n;
	cin >> n;
	vector<pii> col(n);
	cin >> col;
	ll TOT = 1;
	for(auto &[l, r]: col){
		l --;
		TOT = TOT * (r - l) % mod;
	}
	CD cd(n);
	for(int i = 1; i < n; i ++){
		int u, v;
		cin >> u >> v, u --, v --;
		cd.insert(u, v);
	}
	cd.init();
	ll ans = 0;
	vector<vector<tpl>> event(n);
	auto dfs = [&](int u, auto &dfs)->void{
		event[u].emplace_back(col[u].first, u, cd.dist[u].size() - 1, c.inv[col[u].second - col[u].first], 1);
		event[u].emplace_back(col[u].second, u, cd.dist[u].size() - 1, c.inv[col[u].second - col[u].first], 0);
		for(auto v: cd.cchild[u]){
			dfs(v, dfs);
			ll sdw = 0, sw = 0, sum = 0;
			for(int i = 1; i < event[v].size(); i ++){
				auto [p1, u1, ind1, w1, t1] = event[v][i - 1];
				auto [p2, u2, ind2, w2, t2] = event[v][i];
				ll d1 = cd.dist[u1][ind1 - 1];
				if(t1){
					sum = (sum + sdw * w1 + sw * d1 % mod * w1) % mod;
					sdw = (sdw + d1 * w1) % mod;
					sw = (sw + w1) % mod;
				}
				else{
					sdw = (sdw + mod - d1 * w1 % mod) % mod;
					sw = (sw + mod - w1) % mod;
					sum = (sum + 2 * mod - sdw * w1 % mod - sw * d1 % mod * w1 % mod) % mod;
				}
				ans = (ans + mod - sum * (p2 - p1) % mod) % mod;
			}
			for(auto [pos, node, ind, weight, type]: event[v]){
				event[u].emplace_back(pos, node, ind - 1, weight, type);
			}
		}
		sort(all(event[u]));
		ll sdw = 0, sw = 0, sum = 0;
		for(int i = 1; i < event[u].size(); i ++){
			auto [p1, u1, ind1, w1, t1] = event[u][i - 1];
			auto [p2, u2, ind2, w2, t2] = event[u][i];
			ll d1 = cd.dist[u1][ind1];
			if(t1){
				sum = (sum + sdw * w1 + sw * d1 % mod * w1) % mod;
				sdw = (sdw + d1 * w1) % mod;
				sw = (sw + w1) % mod;
			}
			else{
				sdw = (sdw + mod - d1 * w1 % mod) % mod;
				sw = (sw + mod - w1) % mod;
				sum = (sum + 2 * mod - sdw * w1 % mod - sw * d1 % mod * w1 % mod) % mod;
			}
			ans = (ans + sum * (p2 - p1)) % mod;
		}
	};
	dfs(cd.root, dfs);
	cout << ans * TOT % mod;
	return 0;
}
/*
6
2 2
1 4
3 3
3 5
1 4
2 5
1 6
5 3
4 2
4 3
1 5
good: 1324
mine: 1516
0[1,2)-5[1,5)
|
4[0,4)-2[2,3)-3[2,5)-1[0,4)
*/
 
//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
//                                                                                                  //
//                                              _____________                                       //
//             ++++++++++                ___------------------\                                     //
//           +++`+``+`+`++++        ///`````````````````````````````\                               //
//           ++`+`+``+++`++++  /////```````````````````````````````````\                            //
//           +++`++`+`+``+++/////`````````````````````````````````````````\                         //
//             +++`++`+``+///```````````|```````````````````````````````````\                       //
//          ____++++/++++/`````````````/````````|````````|```````````````````\                      //
//        /  /  / |    //``````````````|````````|```````|````````|````````````\                     //
//       /  /  /  | ///````````/```````|```````||```````|````````|``````\```````\                   //
//       | /  /   |///`````````|``````/````````|````````|````````|```````|```````\                  //
//       |/   |   |//``|```````|``````|````````|`````````|```````|```````|````````\                 //
//       /\___|__//`|``|```````|`    |      ``:|````````|:```````|```````|```|`````|                //
//      /     /  /``|``|``````|/     |        :|     ```:|```````|```````|``++````++                //
//     /     / //```|``|``````|      |        |:        :|    ```|```````|```++``++`\               //
//     |    /  /````|``|``````/    _.::::.    |          |      |    ````|```|`++`\`|               //
//     |   /   |````|``|`````|            `                    |       ``|```++``++`|               //
//     |  /    |````|``|`````|                                 :         |``++````++|               //
//     | /     /````|``|`````|                              _.-:::.      |..`|``.`|.|               //
//     |/     /`````|``|`````|                                     `     |```|````|`|               //
//    /|      |`````|``|`````|                    :'                    .|```|````|.|               //
//   / |      |`````|``|`````|                                         /|-|``|````|`|               //
//  /  |      |`````|```\````|                                        / ||```|````|``\              //
// /   |      |`````|````|```|::                                    /_| ||```|````|``|              //
//            |`````|````|```|:|:.        `.._                    .\___/:|```|````|``|              //
//            |`````\````|```|:|::-          ``:::....           -:|:|:::|```|````|``|              //
//            |``````|```|```|:|::`|.                          .:::|:|:::|```|````|``|              //
//             \`````|```|```|:|::/|--.                     .`:|:::|:|:::/```|````|``|              //
//              |````|```|```\:|:|:|-----             _..-:|:|:|:::|:|::|````|````|`/               //
//              |````|```|````\|:|:|-------.____.....------|/::|:::|:|::|````|````|`|               //
//              |````|```|\````\:|/\___________    ________/\--\:::|:|::|````/````|`|               //
//              |````\```| \```|:/-------------\  /----------\``\::|:|::|```/`````|`|               //
//              |`````|``|  \``|/---------------\/------------\_________|```|`````|`|               //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
//                                        Created by Aeren                                          //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////