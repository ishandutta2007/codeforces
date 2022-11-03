#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int k1;
	cin >> k1;
	vector<int> a(k1);
	for (int i = 0; i < k1; i++)
		cin >> a[i];
	int k2;
	cin >> k2;
	vector<int> b(k2);
	for (int i = 0; i < k2; i++)
		cin >> b[i];
	vector<int> tp(2 * n);
	vector<int> sz1(n, k1), sz2(n, k2);
	queue<int> q;
	tp[0] = -1; tp[n] = -1;
	q.push(0); q.push(n);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		if (v < n) {
			if (tp[v] == -1) {
				for (int i : b) {
					int to = (v - i + n) % n + n;
					if (tp[to] == 0) {
						tp[to] = 1;
						q.push(to);
					}
				}
			}
			else {
				for (int i : b) {
					int to = (v - i + n) % n;
					sz2[to]--;
					if (sz2[to] == 0) {
						tp[to + n] = -1;
						q.push(to + n);
					}
				}
			}
		}
		else {
			if (tp[v] == -1) {
				for (int i : a) {
					int to = (v - i + n) % n;
					if (tp[to] == 0) {
						tp[to] = 1;
						q.push(to);
					}
				}
			}
			else {
				for (int i : a) {
					int to = (v - i + n) % n;
					sz1[to]--;
					if (sz1[to] == 0) {
						tp[to] = -1;
						q.push(to);
					}
				}
			}
		}
	}
	for (int i = 1; i < n; i++) {
		if (tp[i] == 1)
			cout << "Win ";
		if (tp[i] == -1)
			cout << "Lose ";
		if (tp[i] == 0)
			cout << "Loop ";
	}
	cout << '\n';
	for (int i = n + 1; i < 2 * n; i++) {
		if (tp[i] == 1)
			cout << "Win ";
		if (tp[i] == -1)
			cout << "Lose ";
		if (tp[i] == 0)
			cout << "Loop ";
	}
	return 0;
}