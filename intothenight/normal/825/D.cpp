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



int main(){
	cin.tie(0)->sync_with_stdio(0);
	string s, t;
	cin >> s >> t;
	vi cnts(26), cntt(26);
	int q = 0;
	for(auto c: s){
		if(c == '?') ++ q;
		else ++ cnts[c - 'a'];
	}
	for(auto c: t){
		++ cntt[c - 'a'];
	}
	int l = 0, r = (sz(s) + sz(t) - 1) / sz(t) + 1;
	while(r - l > 1){
		int mid = l + r >> 1;
		int d = 0;
		for(int i = 0; i < 26; ++ i){
			d += max(0, cntt[i] * mid - cnts[i]);
		}
		if(d <= q) l = mid;
		else r = mid;
	}
	vpii add;
	for(int i = 0; i < 26; ++ i){
		if(cntt[i] * l > cnts[i]){
			add.emplace_back(i, cntt[i] * l - cnts[i]);
		}
	}
	for(auto &c: s){
		if(c == '?'){
			if(add.empty()){
				c = 'a';
			}
			else{
				c = add.back().first + 'a';
				if(add.back().second == 1) add.pop_back();
				else -- add.back().second;
			}
		}
	}
	cout << s;
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////