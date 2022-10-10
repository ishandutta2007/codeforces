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
typedef tuple<int, int, int> tpl; typedef vector<tpl> vtpl;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vi p(n);
	cin >> p;
	vi check(n);
	for(auto &x: p){
		if(x){
			check[x - 1] = true;
		}
		x --;
	}
	vi a(2);
	for(int i = 0; i < n; ++ i){
		if(!check[i]){
			a[i % 2] ++;
		}
	}
	int res = 0;
	vector<vector<vi>> e(n + 1, vector<vi>(a[0] + 1, vi(a[1] + 1, 1e9))), o(e);
	if(p[0] == -1){
		if(a[0]){
			e[1][1][0] = 0;
		}
		if(a[1]){
			o[1][0][1] = 0;
		}
	}
	else{
		if(p[0] % 2){
			o[1][0][0] = 0;
		}
		else{
			e[1][0][0] = 0;
		}
	}
	for(int i = 1; i < n; ++ i){
		for(int j = 0; j <= a[0]; ++ j){
			for(int k = 0; k <= a[1]; ++ k){
				if(p[i] == -1){
					if(j < a[0]){
						e[i + 1][j + 1][k] = min(e[i][j][k], o[i][j][k] + 1);
					}
					if(k < a[1]){
						o[i + 1][j][k + 1] = min(e[i][j][k] + 1, o[i][j][k]);
					}
				}
				else if(p[i] % 2){
					o[i + 1][j][k] = min(e[i][j][k] + 1, o[i][j][k]);
				}
				else{
					e[i + 1][j][k] = min(e[i][j][k], o[i][j][k] + 1);
				}
			}
		}
	}
	cout << min(e[n][a[0]][a[1]], o[n][a[0]][a[1]]);
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////