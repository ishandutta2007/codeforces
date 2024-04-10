#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 500;

int a[maxn];

int main() {
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a, a + n);

	int ans = 0;
	
	queue<int> lst;
	lst.push(a[n - 1]);

	for (int i = n - 2; i >= 0; i--) {
		if (lst.front() != a[i]) {
			lst.pop();
			ans += 1;
		}
		lst.push(a[i]);
	}
	cout << ans << endl;
	return 0;
}