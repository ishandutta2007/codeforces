#include <bits/stdc++.h>
using namespace std;

int arr[2500], n, m, ans;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0;i < n;i++) scanf("%d", arr+i);
	sort(arr, arr+n);
	for (int i = 0;i < m;i++) ans += arr[i];
	printf("%d\n", ans);
	return 0;
}