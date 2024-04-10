#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> v(11, -1);
		for (int i = 0; i < N; ++i) {
			int a, b; cin >> a >> b;
			v[b] = max(a, v[b]);
		}
		int flag = 0;
		for (int i = 1; i <= 10; ++i) if (v[i] == -1) {
			flag = 1;
			break;
		}
		if (flag) puts("MOREPROBLEMS");
		else printf("%d\n", accumulate(v.begin() + 1, v.end(), 0));
	}
	
	return 0;
}