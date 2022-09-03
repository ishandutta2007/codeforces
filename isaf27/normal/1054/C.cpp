#include <bits/stdc++.h>
 
using namespace std;

const int M = 1010;

int n, a[M], l[M], r[M];

int main()
{
        cin >> n;
	for (int i = 0; i < n; i++) cin >> l[i];
	for (int i = 0; i < n; i++) cin >> r[i];
	for (int i = 0; i < n; i++) a[i] = (n - l[i] - r[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++)
			l[i] -= (a[j] > a[i]);
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			r[i] -= (a[j] > a[i]);
	for (int i = 0; i < n; i++)
		if (l[i] != 0 || r[i] != 0)
		{
			cout << "NO\n";
			return 0;
		}
	cout << "YES\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	return 0;
}