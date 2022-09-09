#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>
#include <ctime>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

#define pb push_back
#define all(x) begin(x), end(x)

const int maxn = (1 << 12) + 5;

int a[maxn];
int n;

int main()
{
	scanf("%d", &n);
	int m = (1 << (n + 1)) - 1;
	for (int i = 2; i <= m; i++) scanf("%d", &a[i]);
	int answer = 0;
	for (int i = m / 2; i >= 1; i--)
	{
		answer += abs(a[i * 2] - a[i * 2 + 1]);
		a[i] += max(a[i * 2], a[i * 2 + 1]);
	}
	cout << answer << endl;
	return 0;
}