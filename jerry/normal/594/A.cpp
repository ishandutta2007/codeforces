#include <bits/stdc++.h>
using namespace std;

int a[200005], x, n;

int main()
{
	cin.sync_with_stdio(0); cin >> n;
	for (int i = 0;i < n;i++) cin >> a[i];
	sort(a, a+n); x = a[n-1]; n >>= 1;
	for (int i = 0;i < n;i++) x = min(x, a[i+n]-a[i]);
	cout << x << endl;
	return 0;
}