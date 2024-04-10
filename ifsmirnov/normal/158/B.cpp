#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define forn(i,n) for (int i = 0; i < (int)(n); i++)

int a[10];
int n;

int main()
{
	cin >> n;
	forn(i, n)
	{
		int x;
		cin >> x;
		a[x]++;
	}
	int res = 0;
	
	res += a[4]; a[4] = 0;
	res += a[3]; a[1] = max(0, a[1] - a[3]);
	res += a[2] / 2; a[2] %= 2;
	res += (a[1] + 2*a[2] + 3) / 4;
	
	cout << res << endl;
	
	return 0;
}