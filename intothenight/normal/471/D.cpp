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

template<class Str>
vi z_function(const Str &s){
	int n = sz(s);
	vi z(n);
	for(int i = 1, l = 0, r = 1; i < n; ++ i){
		if(i < r) z[i] = min(r - i, z[i - l]);
		while(i + z[i] < n && s[z[i]] == s[i + z[i]]) ++ z[i];
		if(i + z[i] > r) l = i, r = i + z[i];
	}
	return z;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, w;
	cin >> n >> w;
	if(w == 1){
		cout << n;
		return 0;
	}
	vi a(n), b(w);
	cin >> a >> b;
	vi s(n + w - 1);
	for(int i = 1; i < w; ++ i){
		s[i - 1] = b[i] - b[i - 1];
	}
	s[w - 1] = -2e9;
	for(int j = 1; j < n; ++ j){
		s[j - 1 + w] = a[j] - a[j - 1];
	}
	auto z = z_function(s);
	int res = 0;
	for(int i = w; i < n + w - 1; ++ i){
		if(z[i] == w - 1){
			res ++;
		}
	}
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