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
#define mod 1000000009ll
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
typedef double ld;
typedef pair<ll, ll> pi;
typedef pair<ld, ld> pd;
typedef map<int, int> mii;
typedef __V <ll> vi;
typedef __V <pi> vpi;
typedef __V <__V<int>> vvi;
typedef __V <__V<pi>> vvpi;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n;
vi a;
bool sorted(int i, int j) {
	i++;
	for(; i < j; i++)
		if(a[i-1] > a[i])
			return false;
	return true;
}

int ans(int i, int j) {
	if(sorted(i, j)) return (j-i);
	int mid = (i+j)/2;
	return max(ans(i, mid), ans(mid, j));
}

int main() {
	doin();
	cin >> n;
	a.resize(n);
	for(auto& i : a) cin >> i;
	cout << ans(0, n);
	return 0;
}