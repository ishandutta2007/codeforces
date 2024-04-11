#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define __V vector
#define vi __V<int>
#define pi pair<int, int>
#define mod 1000000007ll
using namespace std;

int n, ans;
vi a;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	a.resize(n);
	for(auto& i : a) cin >> i;
	for(int i = 0; i < n; i++)
		a[i] = min(a[i], 1 + (i ? a[i-1] : 0));
	for(int i = n-1; i>= 0; i--)
		a[i] = min(a[i],1 + (i!=(n-1) ? a[i+1] : 0)), ans = max(a[i], ans);
	cout << ans;
}