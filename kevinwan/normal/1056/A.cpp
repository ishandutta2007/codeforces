#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef bitset<1000> bit;
int main() {
	int n,x,y;
	scanf("%d", &n);
	int i, j;
	bit ans;
	ans.set();
	for (i = 0; i < n; i++) {
		scanf("%d", &x);
		bit t;
		for (int j = 0; j < x; j++)scanf("%d", &y),t[y] = 1;
		ans &= t;
	}
	for (i = 0; i <= 100; i++)if (ans[i])printf("%d ",i );
	getchar(); getchar();
}