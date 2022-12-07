#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
const int N = 500005;
int n, b[N];

void solve() {
	vector<int> ans;
	int u = 0;
	for (; u < n; u++) {
		map<int, int> pre, sum;
		stack<int> s;
		for (int &i = u; i < n; i++) {
			if (pre[b[i]]) {
				for (int j = 0; j < 2; j++) {
					ans.push_back(pre[b[i]]);
					ans.push_back(b[i]);
				}
				break;
			}
			while (!s.empty() && (sum[b[i]] > 1 || sum[b[i]] == 1 && b[i] != s.top())) {
				pre[s.top()] = b[i];
				sum[s.top()]--;
				s.pop();
			}
			s.push(b[i]);
			sum[b[i]]++;
		}
	}
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)
		printf("%d%c", ans[i], ans.size() - 1 == i? '\n' : ' ');
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);
	solve();
	return 0;
}