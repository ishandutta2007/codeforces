#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ld double
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define __V vector
#define vi __V<ll>
#define pi pair<int, int>
#define all(x) x.begin(), x.end()
#define mod 1000000007ll
//using namespace __gnu_pbds;
using namespace std;
ll n, a1, a2, l1, l2;
vi a;
int main() {
	cin.tie();
	cout.tie();
	ios::sync_with_stdio(0);
	cin >> n;
	a.resize(n);
	for (auto& i : a)
		cin >> i;
	a1 = a2 = a.back();
	for (int i = n - 2; i >= 0; i--) {
		a[i] = min(max(a[i + 1] - 1, 0ll), a[i]);
		a1 += a[i];
	}
	cout << fixed << a1;
}