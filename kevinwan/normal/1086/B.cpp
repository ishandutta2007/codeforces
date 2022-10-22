#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
int am[100001];
int main()
{
	int n,i,a,b;
	double s;
	scanf("%d%lf", &n, &s);
	for (i = 0; i < n - 1; i++)scanf("%d%d", &a, &b), am[a]++, am[b]++;
	int num = 0;
	for (i = 1; i <= n; i++)if (am[i] == 1)num++;
	printf("%lf", s / num * 2);
	getchar(); getchar();
}