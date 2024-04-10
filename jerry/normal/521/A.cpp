#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

#define MOD  1000000007ll

char buf[131072];
int occ[256];
long long ans;
int x;
int n;

int main()
{
	scanf("%d%s", &n, buf);
	for (int i = 0;i < n;i++)
		occ[buf[i]]++;
	sort(occ, occ+256);
	reverse(occ, occ+256);
	x = 1;
	for (int i = 1;i < 5;i++) if (occ[i] == occ[i-1])
		x++;
		else break;
	ans = 1;
	for (int i = 0;i < n;i++) ans = (ans * x) % MOD;
	cout << ans << "\n";
	return 0;
}