#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define forn(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
int n;
int a[100500];



int main()
{
	ios :: sync_with_stdio(false);
	cin >> n;
	forn(i, n) cin >> a[i];
	a[n] = 1e9+1;
	
	ll sum = 0;
	ll cnt = 0;
	int last = 1e9+1;
	
	forn(i, n+1)
	{
		if (a[i] == last) cnt++;
		else
		{
			sum += cnt * (cnt+1) / 2;
			cnt = 1;
			last = a[i];
		}
	}
	cout << sum;
};