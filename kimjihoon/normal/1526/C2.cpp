#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int> > q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	long long s = 0;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		if (s + 1LL * a >= 0LL) {
			s += a;
			q.push(a);
			ans++;
		}
		else if (!q.empty() && q.top() < a) {
			s -= q.top();
			s += a;
			q.pop();
			q.push(a);
		}
	}
	cout << ans << '\n';
	return 0;
}