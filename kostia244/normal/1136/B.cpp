#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define __V vector
#define vi __V<ll>
#define pi pair<ll, ll>
#define maxn 300005
#define mod 1000000007ll
using namespace std;

int n, k, l, r;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	l = k;
	r = n-k;
	if(n == k || k == 1)
		cout << (3*n);
	else
		cout << min(4 * l - 1 + 3 * r, 4 * (r+1) - 1 + 3 * (l-1));
	return 0;
}