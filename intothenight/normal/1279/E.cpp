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
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef vector<pii> vpii;
template<class T>
using Ftn = function<T(T, T)>;
template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef tuple<int, int, int> tpl;
typedef vector<tpl> vtpl;

struct disjoint: vi{
	int N;
	// vector<pii> Log; // For persistency
	disjoint(int N): N(N){
		this->resize(N);
		iota(all((*this)), 0);
	}
	int root(int u){
		// Log.emplace_back(u, (*this)[u]);
		return (*this)[u] == u ? u : ((*this)[u] = root((*this)[u]));
	}
	void merge(int u, int v){
		(*this)[root(v)] = root(u);
	}
	int share(int u, int v){
		return root((*this)[u]) == root((*this)[v]);
	}
	/*void reverse(){
		auto [u, p] = Log.back();
		Log.pop_back();
		(*this)[u] = p;
	}*/
};
 
int main(){
	cin.tie(0)->sync_with_stdio(0);
	vl fact(21);
	fact[0] = 1;
	for(int i = 1; i < 21; ++ i){
		fact[i] = fact[i - 1] * i;
	}
	const int lim = 23;
	vl block(lim);
	block[0] = block[1] = 1;
	for(int i = 2; i < lim; ++ i){
		block[i] = fact[i - 2];
	}
	vl good(lim);
	good[0] = 1;
	for(int i = 1; i < lim; ++ i){
		for(int j = 1; j <= i; ++ j){
			good[i] += block[j] * good[i - j];
		}
	}
	auto kth = [&](int ST, int n, ll k){
		assert(n == 1 && k == 1 || n > 22 || fact[n - 2] >= k);
		if(n == 1){
			cout << ST + 1 << " ";
			return;
		}
		disjoint dsu(n);
		dsu.merge(0, n - 1);
		cout << ST + n << " ";
		vi pool(n - 1);
		iota(all(pool), 0);
		for(int i = 1; i < n - 1; ++ i){
			int rem = n - (i + 2);
			for(auto j: pool){
				if(!dsu.share(i, j)){
					if(rem > 20 || fact[rem] >= k){
						cout << ST + j + 1 << " ";
						dsu.merge(i, j);
						pool.erase(find(all(pool), j));
						break;
					}
					k -= fact[rem];
				}
			}
		}
		cout << ST + pool[0] + 1 << " ";
	};
	int tt;
	cin >> tt;
	while(tt --){
		int n;
		ll k;
		cin >> n >> k;
		if(n < lim && good[n] < k){
			cout << "-1\n";
			continue;
		}
		function<void(int, ll)> solve = [&](int l, ll k){
			if(l == n) return;
			for(int size = 1; ; ++ size){
				int rem = n - (l + size);
				if(rem >= lim || size >= lim || (k + good[rem] - 1) / good[rem] <= block[size]){
					if(rem >= lim){
						kth(l, size, 1);
						solve(l + size, k);
					}
					else{
						kth(l, size, (k + good[rem] - 1) / good[rem]);
						solve(l + size, k - (k - 1) / good[rem] * good[rem]);
					}
					return;
				}
				k -= block[size] * good[rem];
			}
		};
		solve(0, k);
		cout << "\n";
	}
	return 0;
}
 
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