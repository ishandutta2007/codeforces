#include <bits/stdc++.h>
#define m(x,y) (a[x]>a[y]?x:y)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
	int n,i,m=0,t=0,x;
	scanf("%d", &n);
	for (i = 0; i < n; i++)scanf("%d", &x), m = max(m, x), t += x;
	int ans = (t * 2 + 1 + n - 1) / n;
	printf("%d", max(ans, m));
	getchar(); getchar();
}