#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
const int maxn = 20050;

int n;
int a[maxn];

int main()
{
	cin >> n;
	int mx = 0;
	forn(i, n)
	{
		cin >> a[i];	
		mx += a[i];
	}
	for (int i = 3; i <= n; i++) if (n%i == 0) forn(j, n/i)
	{
		int s = 0;
		for (int k = j; k < n; k += n/i)
			s += a[k];
		mx = max(mx, s);
	}
	cout << mx << endl;
	
	return 0;
}