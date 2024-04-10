#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

priority_queue<pair<long long, int> > q;
int a[1000009], r[1000009];

long long cc(int i, int k)
{
	if (a[i] < k) k = a[i];
	int p = a[i] / k, c = a[i] % k;
	return 1LL * p * p * (k - c) + 1LL * (p + 1) * (p + 1) * c;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		ans += 1LL * a[i] * a[i];
		r[i] = 1;
		q.push(make_pair(cc(i, r[i]) - cc(i, r[i] + 1), i));
	}
	for (int i = 0; i < k - n; i++) {
		ans -= q.top().first; int hi = q.top().second;
		q.pop();
		r[hi]++;
		q.push(make_pair(cc(hi, r[hi]) - cc(hi, r[hi] + 1), hi));
	}
	cout << ans << '\n';
	return 0;
}