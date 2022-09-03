#include <cstdio>
#include <string>

using namespace std;

string a[500005];
char t[500005];

int main() {
	int i, j, n;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s", t);
		a[i] = t;
	}
	for (i = n - 2; i >= 0; i--) {
		for (j = 0; j < a[i].size() && j < a[i + 1].size() && a[i][j] == a[i + 1][j]; j++);
		if (j == a[i + 1].size() && j < a[i].size() || a[i][j] > a[i + 1][j]) a[i].resize(j);
	}
	for (i = 0; i < n; i++) puts(a[i].c_str());
}