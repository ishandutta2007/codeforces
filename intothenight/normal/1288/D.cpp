#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
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
    return out << "(" << arr.first << ", " << arr.second << ")";
}
template<class ...Args, template<class...> class T>
ostream &operator<<(enable_if_t<!is_same_v<T<Args...>, string>, ostream> &out, const T<Args...> &arr){
	for(auto &x: arr) out << x << " "; return out << "\n";
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rngll(chrono::steady_clock::now().time_since_epoch().count());
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
typedef long long ll;
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<double> vd; typedef vector<string> vs;
typedef pair<int, int> pii; typedef pair<ll, ll> pll; typedef pair<int, ll> pil; typedef pair<ll, int> pli;
typedef vector<pii> vpii; typedef vector<pil> vpil; typedef vector<pli> vpli; typedef vector<pll> vpll;
template<class T> T ctmax(T &x, const T &y){ return x = max(x, y);}
template<class T> T ctmin(T &x, const T &y){ return x = min(x, y);}
template<class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef tuple<int, int, int> tpl; typedef vector<tpl> vtpl;

template<class Pred>
ll custom_binary_search(ll low, ll high, Pred p, bool is_left = true){
	assert(low < high);
	if(is_left){
		while(high - low > 1){
			ll mid = low + (high - low >> 1);
			p(mid) ? low = mid : high = mid;
		}
		return low;
	}
	else{
		while(high - low > 1){
			ll mid = low + (high - low >> 1);
			p(mid) ? high = mid : low = mid;
		}
		return high;
	}
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vector<vi> a(n, vi(m));
	cin >> a;
	pii ans;
	auto p = [&](ll x){
		vi flag(1 << m, -1);
		for(int i = 0; i < n; ++ i){
			int val = 0;
			for(int j = 0; j < m; ++ j){
				if(a[i][j] >= x){
					val += (1 << j);
				}
			}
			flag[val] = i;
		}
		for(int i = 0; i < 1 << m; ++ i){
			if(flag[i] != -1){
				for(int j = i; j < 1 << m; ++ j){
					if(flag[j] != -1 && (i | j) == (1 << m) - 1){
						ans = {flag[i], flag[j]};
						return true;
					}
				}
			}
		}
		return false;
	};
	ll x = custom_binary_search(0, 1e9 + 1, p);
	p(x);
	cout << ans.first + 1 << " " << ans.second + 1;
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////