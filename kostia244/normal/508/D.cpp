#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define xx first.first
#define yy first.second
#define __V vector
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define oit ostream_iterator
#define mod 1000000007ll
using namespace __gnu_pbds;
using namespace std;
void doin() {
	cin.tie();
	cout.tie();
	ios::sync_with_stdio(0);
#ifdef LOCALc
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
template<typename T, typename l>
void getv(T& a, int n, l f) {
	a.resize(n);
	for (auto& i : a)
		cin >> i, f(i);
}
template<typename T>
void getv(T& a, int n) {
	a.resize(n);
	for (auto& i : a)
		cin >> i;
}
typedef unsigned long long ull;
typedef long long ll;
typedef double ld;
typedef ll _I;
typedef pair<_I, _I> pi;
typedef pair<ld, ld> pd;
typedef map<_I, _I> mii;
typedef __V <_I> vi;
typedef __V <char> vc;
typedef __V <ld> vd;
typedef __V <vd> vvd;
typedef __V <pi> vpi;
typedef __V <__V<_I>> vvi;
typedef __V <__V<char>> vvc;
typedef __V <__V<pi>> vvpi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, in[100100], out[100100];
vvi g;
char a, b, c;
string ans;
//1Aa
int vid(char a, char b) {
	return (a*256)+b;
}

void dfs(int v) {
	while(!g[v].empty()) {
		int t = g[v].back();
		g[v].pop_back();
		dfs(t);
	}
	ans += v%256;
}

int main() {
	doin();
	cin >> n;
	g.resize(100100);
	int tn = n;
	int start = 0, end = 0, u, v;
	while(tn--) {
		cin >> a >> b >> c;
		g[vid(a, b)].pb(vid(b, c));
		out[vid(a, b)]++;
		in[vid(b, c)]++;
		v = vid(a, b);
	}
	for(int i = 0; i < 100100; i++) {
		if(in[i]+out[i]==0)
			continue;
		int delta = in[i]-out[i];
		if(delta == -1) v = i, start++;
		else if(delta == 1) end++;
		else if(delta) return cout << "NO\n", 0;
	}
	if(end+start!=2&&end+start!=0) return cout << "NO\n", 0;
	dfs(v);
	ans+=v/256;
	reverse(all(ans));
	if(ans.size() != n+2) return cout << "NO\n", 0;
	cout << "YES\n" << ans;
}