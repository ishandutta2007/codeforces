#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
const int maxn = 200;

int n, k, a[maxn];

int main()
{
	cin >> n >> k;
	forn(i, n) cin >> a[i];
	cout << count_if(a, a+n, [](int x) {return x && x >= a[k-1];}) << endl;
		
	return 0;
}