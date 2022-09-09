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

const int MOD = 1000000007;

const int maxn = 1005;

int p[maxn], d[maxn];
int n;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &p[i]), p[i]--;
	d[0] = 2;
	for (int i = 1; i < n; i++)
	{
		d[i] = 2;
		for (int j = p[i]; j < i; j++) d[i] = (d[i] + d[j]) % MOD;
	}
	int answer = 0;
	for (int i = 0; i < n; i++) answer = (answer + d[i]) % MOD;
	cout << answer << endl;
	return 0;
}