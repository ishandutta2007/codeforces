#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pi pair<int, int>
#define __V vector
#define vi __V<int>
using namespace std;
int n, t, ans;
int cnt[5];
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	while (n--)
		cin >> t, cnt[t]++;
	ans = cnt[4] + (t = min(cnt[1], cnt[3]));
	cnt[1] -= t;
	cnt[3] -= t;
	if (cnt[1] > 0) {
		ans +=((cnt[1])/4) + (cnt[2]*2 + (cnt[1]%4) + 3)/4;
	} else if (cnt[3] > 0) {
		ans += cnt[3];
		ans += (cnt[2]+1)/2;
	} else
		ans += (cnt[2]+1)/2;
	cout << ans;
}