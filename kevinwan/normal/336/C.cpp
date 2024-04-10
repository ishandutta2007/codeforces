#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<int> nums;
int v[100001];
int main() {
	int n, i,j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)scanf("%d", v + i);
	for (i = 30; i >= 0; i--) {
		int cum = -1;
		for (j = 0; j < n; j++)if ((v[j] >> i) & 1)cum &= v[j], nums.push_back(v[j]);
		if ((cum&((1 << i) - 1)) == 0) {
			printf("%d\n", nums.size());
			for (int x : nums)printf("%d ", x);
			return 0;
		}
		nums.clear();
	}
	printf("%d\n", n);
	for (i = 0; i < n; i++)printf("%d", v[i]);
}