#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;
int a[4000], s[4000], ans[4000];
int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < m; i++) {
			s[i] = max(a[i], a[i + n - m]);
			//cout << s[i] << ' ';
		}
		//cout << endl;
		k = m - k;
		k = max(k, 1);
		deque<int> q;
		int mmax = 0;
		for (int i = 0; i < m; i++) {
			while (!q.empty() && s[q.back()] >= s[i]) q.pop_back();
			q.push_back(i);
			while (!q.empty() && q.front() < i - k + 1) q.pop_front();
			ans[i] = s[q.front()];
			//cout << ans[i] << ' ';
		}
		for (int i = k - 1; i < m; i++) {
			mmax = max(mmax, ans[i]);
		}
		//cout << endl;
		cout << mmax << endl;
	}
}