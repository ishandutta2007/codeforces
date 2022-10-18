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
const int MAXN = 4e5;
const int INF = 1e18;

//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
int t[4 * MAXN];
int obh[4 * MAXN];
vc<int> aaaa;

void push(int v, int l, int r){
	t[v] += obh[v];
	if (l != r){
		obh[2 * v] += obh[v];
		obh[2 * v + 1] += obh[v];
	}
	obh[v] = 0;
}

void build(int v, int l, int r){
	obh[v] = 0;
	if (l == r){
		t[v] = -aaaa[l];
		return;
	}
	int mid = (l + r) / 2;
	build(2 * v, l, mid);
	build(2 * v + 1, mid + 1, r);
	t[v] = max(t[2 * v], t[2 * v + 1]);
}

void add(int v, int l, int r, int tl, int tr, int xxx){
	push(v, l, r);
	if (tl <= l && r <= tr){
		obh[v] += xxx;
		push(v, l, r);
		return;
	}
	if (tr < l || r < tl){
		return;
	}
	int mid = (l + r) / 2;
	add(2 * v, l, mid, tl, tr, xxx);
	add(2 * v + 1 , mid + 1, r, tl, tr, xxx);
	t[v] = max(t[2 * v], t[2 * v + 1]);
}

void solve(istream &in, ostream &out){	
	int n, m, p;
	in >> n >> m >> p;
	int ans = -INF;
	map<int, int> ba, bb;
	for (int i = 0; i < n; i++){
		int a, b;
		in >> a >> b;
		if (ba.find(a) == ba.end() || ba[a] > b){
			ba[a] = b;
		}
	}	
	for (int i = 0; i < m; i++){
		int a, b;
		in >> a >> b;
		if (bb.find(a) == bb.end() || bb[a] > b){
			bb[a] = b;
		}
	}	
	vc<int> ca(len(ba)), cb(len(bb));
	{
		int lasts = 0;
		for (auto &v : ba){
			ca[lasts] = v.sc;
			v.sc = lasts++;	
		}
	}	
	{
		int lasts = 0;
		for (auto &v : bb){
			cb[lasts] = v.sc;
			v.sc = lasts++;	
		}
	}	
	n = len(ca), m = len(cb);
	ba[INF] = n;
	bb[INF] = m;	
	vc<vc<pr<int, int>>> adds(n + 1);
	for (int i = 0; i < p; i++){
		int a, b, c;
		in >> a >> b >> c;
		{
			a = (*ba.upper_bound(a)).sc;
			b = (*bb.upper_bound(b)).sc;
		}
		adds[a].pb({b, c});
	}
	aaaa = cb;
	build(1, 0, m - 1);	
	for (int i = 0; i < n; i++){
		for (auto to : adds[i]){
			add(1, 0, m - 1, to.fs, m - 1, to.sc);
		}		
		ans = max(ans, t[1] - ca[i]);
	}
	out << ans;
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve(cin, cout);
}