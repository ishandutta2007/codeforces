#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

const int MOD = 1000000007;

char s[105];
ll st[105];
int n;

int main()
{
	scanf("%s", s);
	int n = strlen(s);
	reverse(s, s + n);
	st[0] = 1;
	ll answer = 0;
	for (int i = 1; i <= n; i++) st[i] = (st[i - 1] * 2) % MOD;
	for (int i = 0; i < n; i++) if (s[i] == '1')
	{
		answer = (answer + (st[i] * st[i]) % MOD * st[n - i - 1]) % MOD;
	}
	cout << answer << endl;
	return 0;
}