#include <bits/stdc++.h>
#define int long long
#define ld long double
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define pr pair
#define vc vector
#define len(v) (int)v.size()
#define all(v) v.begin(),v.end()
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,abm,mmx,avx,avx2,popcnt,tune=native")
//#pragma GCC target("avx,avx2")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("inline")

using namespace std;

template<typename T, typename U>
inline ostream &operator<<(ostream &_out, const pair<T, U> &_p){
	_out << _p.fs << ' ' << _p.sc;
	return _out;
}

template<typename T, typename U>
inline istream &operator>>(istream &_in, pair<T, U> &_p){
	_in >> _p.fs >> _p.sc;
	return _in;
}

template<typename T>
inline ostream &operator<<(ostream &_out, const vc<T> &_v){
	if (_v.begin() != _v.end()){
		_out << *(_v.begin());
		for (auto it = next(_v.begin()); it != _v.end(); ++it){
			_out << ' ' << *it;
		}
	}
	return _out;
}

template<typename T>
inline ostream &operator<<(ostream &_out, const set<T> &_v){
	if (_v.begin() != _v.end()){
		_out << *(_v.begin());
		for (auto it = next(_v.begin()); it != _v.end(); ++it){
			_out << ' ' << *it;
		}
	}
	return _out;
}

template<typename T>
inline istream &operator>>(istream &_in, vc<T> &_v){
	for (auto &_x : _v){
		_in >> _x;
	}
	return _in;
}


int toint(string s){
	int a = 0;
	for (auto v : s){
		a += v;
	}
	return a;
}

mt19937 rnd(toint("	 	   	 	 	 	 	     	  	   	 	 	"));

const int MOD = 1e9+7;
const int MAXN = 5e5;
const int INF = 1e9;

//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());


void solve(istream &in, ostream &out){	
	int n;
	in >> n;
	vc<int> b(n);
	in >> b;
	map<int, int> as;
	int ans = 0;
	for (int i = 0; i < n; i++){
		int tans = as[i - b[i]] + b[i];
		as[i - b[i]] = max(as[i - b[i]], tans);
		ans = max(ans, tans);
	}
	out << ans;
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve(cin, cout);
}