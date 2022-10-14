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
#ifdef LOCAL
//  freopen("input.txt", "r", stdin);
#endif
}
typedef long long ll;
typedef ll _I;
typedef double ld;
typedef pair<_I, _I> pi;
typedef pair<ld, ld> pd;
typedef map<_I, _I> mii;
typedef __V <_I> vi;
typedef __V <char> vc;
typedef __V <ld> vd;
typedef __V <pi> vpi;
typedef __V <__V<_I>> vvi;
typedef __V <__V<char>> vvc;
typedef __V <__V<pi>> vvpi;
const int N = 1e5 + 5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, cnt = 0, b[N], a[N];
bool m[N];
string s;
int main() {
	doin();
	n = (cin >> s, s.size());
	int j = -1, i = 0;
	b[0] = -1;
	while (i < n) {
		while (j != -1 && s[i] != s[j])
			j = b[j];
		i++, j++;
		b[i] = j;
	}
	i = s.size();
	while (i > 0) {
		m[i] = true;
		cnt++;
		i = b[i];
	}
	for(int i = n; i > 0; i--)
		a[b[i]]++;
	for(int i = n; i > 0; i--)
		a[b[i]]+=a[i];
	cout << cnt << "\n";
	for(int i = 1; i <= n; i++)
		if(m[i])
			cout << i << " " << ++a[i] << "\n";
}