#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long llong;

int n, k;
char str[1000001];
int f[26]; int e[26];
pair<int, int> v[52];
int main() {
	scanf("%d%d%s", &n, &k, str);
	for (int i = 0; i < 26; ++i) f[i] = e[i] = -1;
	for (int i = 0; i < n; ++i) {
		if (f[str[i] - 'A'] == -1) {
			f[str[i] - 'A'] = i;
		}
		e[str[i] - 'A'] = i;
	}
	int j = 0;
	for (int i = 0; i < 26; ++i) {
		if (f[i] != -1) {
			v[j++] = { f[i], -1 };
			v[j++] = { e[i], 1 };
		}
	}
	sort(v, v + j);
	int x = 0;
	for (int i = 0; i < j; ++i) {
		x -= v[i].second;
		if (x > k) {
			printf("YES");
			return 0;
		}
	}
	printf("NO");
	return 0;
}