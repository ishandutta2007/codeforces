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
typedef tuple<int, int, int, int> tpl; typedef vector<tpl> vtpl;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	auto kill = [](){
	    cout << "NO";
	    exit(0);
	};
	int n;
	cin >> n;
	vtpl t(n);
	for(auto &[a1, a2, a3, a4]: t){
		cin >> a1 >> a2 >> a3 >> a4;
	}
	sort(all(t));
	vpii a(n);
	vi sb(n), eb(n);
	for(int i = 0; i < n; ++ i){
		auto [a1, a2, a3, a4] = t[i];
		a[i] = {a1, a2}, sb[i] = a3, eb[i] = a4;
	}
	vector<vector<tuple<int, int, int>>> query1(n + 1); // query1[pos] = {queryind, queryval}
	vector<vpii> query2(n);
	for(int i = 0; i < n - 1; ++ i){
		auto [l, r] = a[i];
		auto high = upper_bound(all(a), pii{r, 2e9}) - a.begin();
		if(i + 1 < high){
			query1[i + 1].push_back({i, sb[i], eb[i]});
			query1[high].push_back({i, sb[i], eb[i]});
		}
		if(high < n){
			query2[high].push_back({sb[i], eb[i]});
		}
	}
	vector<vi> res(n);
	Tree<pii> pl, pr;
	for(int i = 0; i < n; ++ i){
		pl.insert({sb[i], i}), pr.insert({eb[i], i});
		for(auto [ind, l, r]: query1[i + 1]){
			res[ind].push_back(i + 1 - pl.order_of_key({r + 1, 0}) + pr.order_of_key({l, 0}));
		}
	}
	for(auto &arr: res){
		if(!arr.empty() && arr[0] != arr[1]){
			kill();
		}
	}
	set<pii> q;
	for(int i = n - 1; i > 0; -- i){
		q.insert({sb[i], eb[i]});
		for(auto [l, r]: query2[i]){
			auto it = q.upper_bound({l, (int)2e9});
			if(it != q.end() && it->first <= r){
				kill();
			}
			if(it != q.begin()){
				it --;
				if(l <= it->second){
					kill();
				}
			}
		}
	}
	cout << "YES";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////