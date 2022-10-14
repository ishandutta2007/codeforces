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
#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
}
template<typename X, typename Y>
istream& operator>>(istream& in, pair<X, Y> &a) {
	in >> a.first >> a.second;
	return in;
}
template<typename T>
void getv(T& i) {
	cin >> i;
}
template<typename T, typename ... Ns>
void getv(vector<T>& v, int n, Ns ... ns) {
	v.resize(n);
	for (auto& i : v)
		getv(i, ns...);
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
int l;
string s;

string add(string a, string b) {
	reverse(all(a));
	reverse(all(b));
	while (a.size() < b.size())
		a += "0";
	while (a.size() > b.size())
		b += "0";
	string res;
	int co = 0;
	for (int i = 0; i < a.size(); i++) {
		int ia = a[i] - '0', ib = b[i] - '0';
		int r = (ia + ib + co);
		res += to_string(r % 10);
		co = r / 10;
	}
	if (co)
		res += to_string(co);
	reverse(all(res));
//	cout << a << " " << b << " " << res << "\n";
	return res;
}

int main() {
	doin();
	cin >> l >> s;
	int r = l + 4;
	vi j;
	for (int i = 0; i < l; i++) {
		if (s[i] != '0' && abs(l-i-i) < r)
			r = abs(l-i-i), j = {i};
		else if (s[i] != '0' && abs(l-i-i) == r)
			j.pb(i);
	}
	string ans = add(s.substr(0, j[0]), s.substr(j[0], l));
	for(auto i : j) {
		string r = add(s.substr(0, i), s.substr(i, l));
		if(r.size() < ans.size())
			ans = r;
		if(r < ans)
			 ans=r;
	}
	cout << ans;
}