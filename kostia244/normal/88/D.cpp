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
typedef int _I;
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
int n;
string s, t;
map<string, int> m;
set<string> a;
void add(string n, string p) {
	a.insert(n);
	int ptr = count(all(p), '*');
	int ref = count(all(p), '&');
	p = p.substr(ref, p.size() - ref - ptr);
	if ((a.find(p) == a.end()) || m[p] == -1) {
		m[n] = -1;
		return;
	}
	ptr += m[p];
	ptr -= ref;
	if (ptr < 0)
		m[n] = -1;
	else
		m[n] = ptr;
}
void print(string s) {
	int ptr = count(all(s), '*');
	int ref = count(all(s), '&');
	s = s.substr(ref, s.size() - ref - ptr);
	if (a.find(s) == a.end()) {
		cout << "errtype\n";
		return;
	}
	ptr += m[s];
	ptr -= ref;
	if (ptr < 0 || m[s] == -1) {
		cout << "errtype\n";
	} else {
		cout << "void";
		while (ptr--)
			cout << "*";
		cout << "\n"; //
	}
}

int main() {
	doin();
	cin >> n;
	a.insert("void");
	m["void"] = 0;
	while (n--) {
		cin >> s;
		if (s == "typeof") {
			cin >> s;
			print(s);
		} else {
			cin >> s >> t;
			add(t, s);
		}
	}
}