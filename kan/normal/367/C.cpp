#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int maxn = 100005;

int n, m;
int a[maxn];

ll calc(int x)
{
	ll ke = (ll)x * (x - 1) / 2;
	if (x % 2 == 0) return x / 2 + ke;
	else return ke + 1;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) scanf("%*d%d", &a[i]);
	sort(a, a + m);
	reverse(a, a + m);
	ll sum = 0;
	ll answer = 0;
	for (int i = 0; i < m; i++)
	{
		sum += a[i];
		if (calc(i + 1) <= n) answer = sum;
	}
	cout << answer << endl;
}