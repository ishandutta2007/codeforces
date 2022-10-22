#include <bits/stdc++.h>
#define m(x,y) (a[x]>a[y]?x:y)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int a[10000];
vector<int> ans;
int main() {
	int n, i,j,k;
	scanf("%d", &n);
	for (i = 0; i < n; i++)scanf("%d", a + i);
	for (i = n - 1; i; i--)a[i] -= a[i - 1];
	for (i = 1; i <= n; i++) {
		bool pos = 1;
		for (j = 0; j < i; j++) {
			for (k = j; k < n; k += i)if (a[k] != a[j])pos = 0;
		}
		if (pos)ans.push_back(i);
	}
	printf("%d\n", ans.size());
	for (int x : ans)printf("%d ", x);
	getchar(); getchar();
}