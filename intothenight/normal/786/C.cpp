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
	vi a(n);
	cin >> a;
	for(auto &x: a){
		x --;
	}
	vi res(n + 1);
	auto calc = [&](int x){
		vi flag(n, true);
		int ans = 0;
		for(int i = 0, cur = 0; i < n; ){
			ans ++;
			int j = i;
			while(j < n && cur + flag[a[j]] <= x){
				cur += flag[a[j]];
				flag[a[j ++]] = false;
			}
			for(int k = i; k < j; ++ k){
				flag[a[k]] = true;
			}
			cur = 0;
			i = j;
		}
		return ans;
	};
	function<void(int, int)> solve = [&](int l, int r){
		if(l >= r) return;
		int m = l + r >> 1;
		if(res[l - 1] == res[r]){
			for(int i = l; i < r; ++ i){
				res[i] = res[r];
			}
			return;
		}
		res[m] = calc(m);
		solve(l, m), solve(m + 1, r);
	};
	res[1] = calc(1), res[n] = calc(n);
	solve(2, n);
	res.erase(res.begin());
	cout << res;
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////