#include <bits/stdc++.h>
#include <parallel/numeric>
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
typedef int _INT;
typedef double ld;
typedef pair<_INT, _INT> pi;
typedef pair<ld, ld> pd;
typedef map<_INT, _INT> mii;
typedef __V <_INT> vi;
typedef __V <pi> vpi;
typedef __V <__V<_INT>> vvi;
typedef __V <__V<pi>> vvpi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m, k, ans;
vi a, b;
int main() {
	doin();
	cin >> n >> m >> k;
	a.resize(n);
	b.resize(n);
	for(auto& i : a)
		cin >> i;
	adjacent_difference(all(a), b.begin());
	sort(b.begin()+1, b.end(), greater<int>());
	ans = a.back()-a[0]+1;
	for(int i = 1; i < k; i++)
		ans-=b[i]-1;
	cout << ans;
	return 0;
}