#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
int main() {
	int n, a, b, k, cnt = 0;
	cin >> n >> a >> b >> k;
	priority_queue<int,vector<int>,greater<int>> que;
	int sum = a + b, h;
	for (int i = 0; i < n; i++) {
		cin >> h;
		h--;
		h = h % sum;
		if (h < a) cnt++;
		else {
			que.push(h / a);
		}
	}
	while (!que.empty()) {
		int need = que.top();
		que.pop();
		if (need > k) break;
		k -= need;
		cnt++;
	}
	cout << cnt;
}