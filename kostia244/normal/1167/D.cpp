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
#define mod 1234567891ll
using namespace __gnu_pbds;
using namespace std;
void doin() {
	cin.tie();
	cout.tie();
	ios::sync_with_stdio(0);
#ifdef LOCAL
//		freopen("in", "r", stdin);
//		freopen("out", "w", stdout);
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
int n, m, k, p, op = 0, md = 0, cl[200006];
string s, t;
stack<int> pos;

int main() {
	doin();
	cin >> n >> s;
	for(int i = 0; i < n; i++) {
		if(s[i] == '(')
			md = max(md, ++op), pos.push(i);
		else
			op--, cl[pos.top()] = i, pos.pop();
	}
	op = 0;
	md/=2;
	t.resize(n, '0');
	for(int i = 0; i < n; i++) {
		if(s[i] == '(') {
			if(++op <= md)
				t[i] = t[cl[i]] = '1';
		}
		else
			op--;
	}
	cout << t;

}