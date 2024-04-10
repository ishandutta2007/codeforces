#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define forn(i, n) for (int i = 0; i < n; i++)
const int maxn = 100500;

int a[maxn];
int ans[maxn];
int order[maxn];
int N1, N2, n;
bool cmp (int i, int j)
{
	if (N1 < N2) return a[i] > a[j] || (a[i] == a[j] && i < j);
	else return a[i] < a[j] || (a[i] == a[j] && i < j);
};

int main()
{
	cin >> n >> N1 >> N2;
	forn(i, n) cin >> a[i];
	if (N1 == N2)
	{
		forn(i, N1) cout << "1 ";
		forn(i, N1) cout << "2 ";
		return 0;
	}
	forn(i, n) order[i] = i;
	sort(order, order+n, cmp);
	forn(i, N1) ans[order[i]] = 1;
	forn(i, n) cout << 2 - ans[i] << " ";
};