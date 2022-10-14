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
//#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
//#endif
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
ll n, m, k, c, t, cnt[101], pot[101], npot[101], ans = 0, mc = 0, md = 0, sd = 0;
string s;
set<int> a;

int main() {
	doin();
	cin >> m >> k;
	for (int i = 0; i < k; i++)
		cin >> t, a.insert(t);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		cin >> c;
		for (int j = 0; j < c; j++) {
			cin >> t;
			if (t)
				if (a.find(t) != a.end())
					cnt[i]++;
				else
					npot[i]++;
			else
				pot[i]++;
		}
		int T = cnt[i];
		cnt[i] = cnt[i] + max(0ll, pot[i] - (m - npot[i] - k));
		pot[i]=T+min(pot[i], k-T);

		if (md < pot[i]) {
			sd = md;
			md = pot[i];
			mc = 0;
		} else if(sd < pot[i])
			sd = pot[i];
		mc += (md == pot[i]);
		if (ans < cnt[i]) {
			mc = 1, ans = cnt[i];
		} else if (ans == cnt[i])
			mc++;

	}
	for (int i = 0; i < n; i++) {
		if (cnt[i] == md || (cnt[i] == ans && pot[i] == md && cnt[i]>=sd))
			cout << "0\n";
		else if (pot[i]>=ans)
			cout << "2\n";
		else
			cout << "1\n";
	}
}