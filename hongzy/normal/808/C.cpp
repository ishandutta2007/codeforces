#include <algorithm>
#include <cstdio>
using namespace std;
int n, w, a[110], b[110], arr[110];
bool cmp(int x, int y) { return a[x] < a[y]; }
int main() {
	scanf("%d%d", &n, &w);
	for(int i = 1; i <= n; i ++) scanf("%d", a + i), arr[i] = i;
	sort(arr + 1, arr + n + 1, cmp);
	int p = 0, la = 0, num = 0; 
	for(int i = 1, j; i <= n; i = j + 1) {
		for(j = i; a[arr[j + 1]] == a[arr[i]]; j ++) ;
		num = max((a[arr[i]] + 1) >> 1, la);
		for(int k = i; k <= j; k ++) b[arr[k]] = num;
		la = num;
	}
	for(int i = 1; i <= n; i ++) w -= b[i];
	if(w < 0) return puts("-1"), 0;
	for(int i = n; w && i >= 1; i --) {
		int t = min(w, a[arr[i]] - b[arr[i]]);
		b[arr[i]] += t; w -= t;
	}
	for(int i = 1; i <= n; i ++) printf("%d ", b[i]);
	return 0;
}