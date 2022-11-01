#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

using namespace std;

int main(void) {
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	if (a == b) {
		for (int i = 0; i < a; i++) {
			printf("1 ");
		}
		for (int i = 0; i < a; i++) {
			printf("2 ");
		}
		printf("\n");
		return 0;
	}
	typedef pair<int, int> pii;
	vector<pii> v;
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		if (a < b) {
			v.push_back(pii(-t, i));
		} else
			v.push_back(pii(t, i));
	}
	sort(v.begin(), v.end());
	vector<int> res(n);
	for (int i = 0; i < n; i++) {
		res[v[i].second] = (i < a) ? 1 : 2;
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", res[i]);
	}
	printf("\n");
	return 0;
}