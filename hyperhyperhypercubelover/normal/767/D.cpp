#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[10000001];
vector<int> b[10000001];
vector<int> c;
vector<int> d;

int main() {
	int i, j, k, l, m, n, r;
	scanf("%d%d%d", &n, &m, &l);
	while (n--) {
		scanf("%d", &i);
		a[i]++;
	}
	for (i = 1; i <= m; i++) {
		scanf("%d", &j);
		b[j].push_back(i);
	}
	j = r = 0;
	for (i = 10000000; i >= 0; i--) {
		j += a[i];
		for (auto t : b[i]) c.push_back(t);
		if (j > l) j -= l;
		else {
			if (j + c.size() > l) {
				for (k = 0; k < l - j; k++) {
					d.push_back(c.back());
					c.pop_back();
				}
			}
			else {
				while (!c.empty()) {
					d.push_back(c.back());
					c.pop_back();
				}
			}
			j = 0;
		}
	}
	if (j) puts("-1");
	else {
		printf("%d\n", d.size());
		for (auto t : d) printf("%d ", t);
	}
}