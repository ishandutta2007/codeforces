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
vi prefix_function(const Str &s){
	int n = sz(s);
	vi p(n);
	for(int i = 1; i < n; ++ i){
		int j = p[i - 1];
		while(j > 0 && s[i] != s[j]) j = p[j - 1];
		if(s[i] == s[j]) ++ j;
		p[i] = j;
	}
	return p;
}
template<class Str, class UO = function<char(int)>, int lim = 26>
pair<vi, vector<vi>> prefix_automaton(const Str &s, UO trans = [](int c){return c + 'a';}){
	vi p = prefix_function(s);
	int n = sz(s);
	vector<vi> aut(n, vi(lim));
	for(int i = 0; i < n; ++ i){
		for(int c = 0; c < lim; ++ c){
			if(i > 0 && trans(c) != s[i]) aut[i][c] = aut[p[i - 1]][c];
			else aut[i][c] = i + (trans(c) == s[i]);
		}
	}
	return {p, aut};
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	auto trans = [&](int x){
		if(x < 10) return 1;
		else if(x < 100) return 2;
		else if(x < 1000) return 3;
		else return 4;
	};
	string s;
	cin >> s;
	int n = sz(s);
	vector<vi> len(n + 1, vi(n + 1));
	for(int i = 0; i < n; ++ i){
		vi p = prefix_function(s.substr(i)); // length n - i
		len[i][i + 1] = 2;
		for(int j = i + 2; j <= n; ++ j){
			int k = (j - i) - p[j - i - 1];
			len[i][j] = ((j - i) % k ? j - i + 1 : trans((j - i) / k) + k);
		}
	}
	vi dp(n + 1, 1e9);
	dp[0] = 0;
	for(int i = 1; i <= n; ++ i){
		for(int l = 1; l <= i; ++ l){
			ctmin(dp[i], dp[i - l] + len[i - l][i]);
		}
	}
	cout << dp[n];
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////