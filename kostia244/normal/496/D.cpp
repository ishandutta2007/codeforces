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
#define nxt(x)  pos[x][sc[x]+t]
ll n, a[300100], sum[300100], pos[2][300100], t, s, w, L;
vpi ans;
int gets(int t) {
//	if (t == 26)
//		cout << t << ": ";
	int s = 0, sc[2] = { 0, }, res[2] = { 0, }, r = 0;
	for (; sc[0] + sc[1] < n;) {
		if (nxt(0)!= -1 && (nxt(1) == -1 || nxt(0) < nxt(1))) {
			w = nxt(0), res[0]++,L=0;
//			if(t==26)
//			cout << "0: " << w << "\n";
		} else if (nxt(1)!= -1) {
			w = nxt(1), res[1]++,L=1;
//			if(t==26)
//			cout << "1: " << w << "\n";
		}
		else {
//			if(n == 8946 && (t == 652 || t == 50)) {
//				cout << "B\n";
//				cout << res[0] << " " << res[1] << "\n";
//				cout << w << "\n";
//				cout << L << sc[0] << " " << sc[1] << "\n";
//			}
//			if(t == 15)
//			cout << L <<  " " << res[0] << " " << res[1] << "\n";
			if(res[0]==res[1]||w != n-1
			||res[L]<res[1-L])
			return -1;
//			cout << w << " ( " << sum[w] << " ) " << sc[0] << " " << sc[1] << "]\n";
			return max(res[0], res[1]);
		}
		sc[0] = w-sum[w]+1;
		sc[1] = sum[w];
//		cout << w << " " << res[0] << " " << res[1] << ")\n";
//		cout << w << " ( " << sum[w] << " ) " << sc[0] << " " << sc[1] << "]\n";
//		cout << w << " " << pos[0][sc[0]+1] << " " << pos[1][sc[1]+1] << "}\n";
	}
//	if(n == 8946 && (t == 652 || t == 50)) {
//		cout << res[0] << " " << res[1] << "\n";
//		cout << w << "\n";
//		cout << L << sc[0] << " " << sc[1] << "\n";
//	}
//	if(t == 15)
//	cout << L <<  " " << res[0] << " " << res[1] << "\n";
	if (res[0] == res[1] || w != n - 1 || res[L]<res[1-L])
		return -1;
//	cout<< t << " : " << w << " " << sc[0] << " " << sc[1] << "\n";
	return max(res[0], res[1]);
}

int main() {
	doin();
	memset(pos, -1, sizeof pos);
	int time = clock();
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i], a[i]--;
		sum[i] += a[i];
		sum[i + 1] = sum[i];
		pos[a[i]][a[i] ? sum[i] : (i - sum[i] + 1)] = i;
	}
	w = sum[n - 1] > (n - sum[n - 1]);
	for (t = 1; t <= n; t++) {
		s = gets(t);
//		if((clock() - time)/CLOCKS_PER_SEC >= 1)
//			return cout << t, -1;
		if (s != -1)
			ans.eb(s, t);
	}
	sort(all(ans));
	cout << ans.size() << "\n";
	for (auto i : ans)
		cout << i.first << " " << i.second << "\n";
}