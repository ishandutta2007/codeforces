#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ar array

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for (auto& x: a)

template<class T> bool umin(T& a, const T& b) {
	return b<a?a=b, 1:0;
}
template<class T> bool umax(T& a, const T& b) { 
	return a<b?a=b, 1:0;
} 

ll FIRSTTRUE(function<bool(ll)> f, ll lb, ll rb) {
	while(lb<rb) {
		ll mb=(lb+rb)/2;
		f(mb)?rb=mb:lb=mb+1; 
	} 
	return lb;
}
ll LASTTRUE(function<bool(ll)> f, ll lb, ll rb) {
	while(lb<rb) {
		ll mb=(lb+rb+1)/2;
		f(mb)?lb=mb:rb=mb-1; 
	} 
	return lb;
}

template<class A> void read(vt<A>& v);
template<class A, size_t S> void read(ar<A, S>& a);
template<class T> void read(T& x) {
	cin >> x;
}
void read(double& d) {
	string t;
	read(t);
	d=stod(t);
}
void read(long double& d) {
	string t;
	read(t);
	d=stold(t);
}
template<class H, class... T> void read(H& h, T&... t) {
	read(h);
	read(t...);
}
template<class A> void read(vt<A>& x) {
	EACH(a, x)
		read(a);
}
template<class A, size_t S> void read(array<A, S>& x) {
	EACH(a, x)
		read(a);
}

string to_string(char c) {
	return string(1, c);
}
string to_string(bool b) {
	return b?"true":"false";
}
string to_string(const char* s) {
	return string(s);
}
string to_string(string s) {
	return s;
}
string to_string(vt<bool> v) {
	string res;
	FOR(sz(v))
		res+=char('0'+v[i]);
	return res;
}

template<size_t S> string to_string(bitset<S> b) {
	string res;
	FOR(S)
		res+=char('0'+b[i]);
	return res;
}
template<class T> string to_string(T v) {
    bool f=1;
    string res;
    EACH(x, v) {
		if(!f)
			res+=' ';
		f=0;
		res+=to_string(x);
	}
    return res;
}

template<class A> void write(A x) {
	cout << to_string(x);
}
template<class H, class... T> void write(const H& h, const T&... t) { 
	write(h);
	write(t...);
}
void print() {
	write("\n");
}
template<class H, class... T> void print(const H& h, const T&... t) { 
	write(h);
	if(sizeof...(t))
		write(' ');
	print(t...);
}

void DBG() {
	cerr << "]" << endl;
}
template<class H, class... T> void DBG(H h, T... t) {
	cerr << to_string(h);
	if(sizeof...(t))
		cerr << ", ";
	DBG(t...);
}
#ifdef _DEBUG
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

template<class T> void offset(ll o, T& x) {
	x+=o;
}
template<class T> void offset(ll o, vt<T>& x) {
	EACH(a, x)
		offset(o, a);
}
template<class T, size_t S> void offset(ll o, ar<T, S>& x) {
	EACH(a, x)
		offset(o, a);
}

mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());
ll randint(ll a, ll b) {
	return uniform_int_distribution<ll>(a, b)(mt_rng);
}

template<class T, class U> void vti(vt<T> &v, U x, size_t n) {
	v=vt<T>(n, x);
}
template<class T, class U> void vti(vt<T> &v, U x, size_t n, size_t m...) {
	v=vt<T>(n);
	EACH(a, v)
		vti(a, x, m);
}

const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};

const int mxN=1e6, mxK=20;
int n, m, k, T[mxN+1][mxK], a[mxN], b[mxN], ps[mxN+1], pt[mxN+1];
string s, t;
ar<int, 2> d[1<<mxK];

void calc(string &s, int ps[mxN+1]) {
	FOR(n+1)
		FOR(j, k)
			ps[i]|=s[j]%2<<T[i][j];
	FOR(n+1)
		dbg(ps[i]);
}
ll cnt = 0;
void upd(int x, int i) {
	d[x]={0, i};
	queue<int> qu;
	qu.push(x);
	while(qu.size()) {
		int x=qu.front();
		qu.pop();
		FOR(j, k) {
			int y=x^1<<j;
			if(d[y][0]>d[x][0]+1) {
				d[y]={d[x][0]+1, d[x][1]};
				qu.push(y);
				//cout << i << " gottt " << d[y][1] << endl;
			}
			//cout << ++cnt << endl;
		}
	}
}

void solve() {
	read(n, m, k, s, t);
	FOR(n)
		read(a[i], b[i]), --a[i], --b[i];
	iota(T[n], T[n]+k, 0);
	for (int i = n - 1; i >= 0; i--) {
		swap(T[n][a[i]], T[n][b[i]]);
	}
	for (int i = n - 1; i >= 0; i--) {
		FOR(j, k) {
			int ni=j;
			if(ni==a[i]||ni==b[i])
				ni^=a[i]^b[i];
			T[i][j]=T[i + 1][ni];
		}
	}
	calc(s, ps);
	calc(t, pt);
	//for (int i = 0; i <= n; i++) {
	//	for (int j = 0; j < k; j++) cout << T[i][j] << " ";
	//	cout << endl;
	//	cout << pt[i] << " " << ps[i] << endl;
	//}
	fill(d, d+(1<<k), ar<int, 2>{k, n});
	ar<int, 3> ans{k, 0, n};
	FOR(j, m, n+1) {
		upd(ps[j-m], j-m);
		//cout << " kacccc" << ans[0] <<endl;
		umin(ans, {d[pt[j]][0], d[pt[j]][1], j});
		if (ans[0] >= d[pt[j]][0] && ans[0] <= ans[1]) {
			//cout << pt[j] << " got here " << ps[j - m] << endl;
			ans[0] = d[pt[j]][0];
			ans[1] = d[pt[j]][1];
			ans[2] = j;
		}
		//cout << ans << " " << j - m << " hukkka " << d[pt[j]][1] << " " << j << " " << d[pt[j]][0] << endl;
	}
	print(k-ans[0]);
	print(ans[1]+1, ans[2]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t=1;
	//read(t);
	FOR(t) {
		//write("Case #", i+1, ": ");
		solve();
	}
}