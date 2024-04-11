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
int n, _ID = 0;
char wvls[] = { 'a', 'o', 'e', 'u', 'i' };
int wvl(char a) {
	for (int i = 0; i < 5; i++)
		if (a == wvls[i])
			return i;
	return -1;
}
string s[1001000];
struct wrd {
	int id = 0, cnt = 0, lst;
	void get() {
		cin >> s[(id = ++_ID)];
		for (auto i : s[id])
			if (wvl(i) != -1)
				cnt++, lst = wvl(i);
	}
};
__V<wrd> f[1001000][5];
__V<pair<wrd, wrd>> pairs;
__V<pair<pair<wrd, wrd>, pair<wrd, wrd>>> ans;

int main() {
	doin();
	cin >> n;
	while (n--) {
		wrd a;
		a.get();
		f[a.cnt][a.lst].pb(a);
	}
	__V<pair<wrd, wrd>> pairs, leftp;
	for (int i = 1; i <= 1000000; i++) {
		__V<wrd> left;
		for (int j = 0; j < 5; j++) {
			int sz = f[i][j].size();
			while (sz > 1) {
				pairs.pb( { f[i][j][sz - 1], f[i][j][sz - 2] });
				f[i][j].pop_back();
				f[i][j].pop_back();
				sz -= 2;
			}
			if (sz)
				left.pb(f[i][j].back());
		}
		while(left.size() > 1) {
			leftp.push_back({left.back(), left[left.size()-2]});
			left.pop_back();
			left.pop_back();
		}
	}

	int sz = pairs.size();
	while (!pairs.empty()) {
		if (leftp.size()) {
			ans.pb( { leftp.back(), pairs.back() });
			pairs.pop_back();
			leftp.pop_back();
			sz--;
		} else {
			if (sz < 2)
				break;
			ans.pb( { pairs[sz - 2], pairs[sz - 1] });
			pairs.pop_back();
			pairs.pop_back();
			sz -= 2;
		}
	}
	cout << ans.size() << "\n";
	for (auto i : ans) {
		cout << s[i.first.first.id] << " " << s[i.second.first.id] << "\n";
		cout << s[i.first.second.id] << " " << s[i.second.second.id] << "\n";
	}
	return 0;
}