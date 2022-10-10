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
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rndll(chrono::steady_clock::now().time_since_epoch().count());
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
	int tt;
	cin >> tt;
	while(tt --){
		int n;
		cin >> n;
		vpii a(n);
		cin >> a;
		sort(all(a));
		vpii left;
		deque<pii> right;
		vector<vpii> log;
		for(auto [l, r]: a){
			log.emplace_back();
			if(!left.empty() && l <= left.back().second){
				l = left.back().first, r = max(r, left.back().second);
				log.back().push_back(left.back());
				left.pop_back();
			}
			left.emplace_back(l, r);
		}
		int res = 0;
		for(int i = n - 1; i >= 0; -- i){
			left.pop_back();
			for(auto [l, r]: log.back()){
				left.emplace_back(l, r);
			}
			log.pop_back();
			int inter = 0;
			if(!left.empty()){
				auto [l, r] = left.back();
				inter = upper_bound(all(right), pii{r, 2e9}) - right.begin();
			}
			res = max(res, sz(left) + sz(right) - inter);
			auto [l, r] = a[i];
			while(!right.empty() && right.front().first <= r){
				r = max(r, right.front().second);
				right.pop_front();
			}
			right.emplace_front(l, r);
		}
		cout << res << "\n";
	}
	return 0;
}

/*
1
5
0 5 
9 9 
5 5 
3 8 
6 7 
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////