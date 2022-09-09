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
const int ND = 10;
const int maxlen = 100005;
const int maxn = 100005;

char s[maxlen];

string t[maxn];
char d[maxn];
int mod[ND], len[ND];
int n;

inline int powmod(int a, int b)
{
	int tmp = a;
	int ans = 1;
	while (b)
	{
		if (b & 1) ans = ((ll)ans * tmp) % MOD;
		tmp = ((ll)tmp * tmp) % MOD;
		b >>= 1;
	}
	return ans;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.getline(s, maxlen);
	d[0] = '0';
	t[0] = string(s, s + strlen(s));
	cin >> n;
	cin.getline(s, maxlen);
	for (int i = 1; i <= n; i++)
	{
		cin.getline(s, maxlen);
		d[i] = s[0];
// 		cout << d[i] << endl;
		char *st = s + 3;
		t[i] = string(st, st + strlen(st));
	}
	for (int i = 0; i < ND; i++) len[i] = 1, mod[i] = i;
	for (int i = n; i >= 0; i--)
	{
		int curlen = 0;
		int curmod = 0;
		int lent = t[i].length();
		for (int j = lent - 1; j >= 0; j--)
		{
			curmod = (curmod + (ll)mod[t[i][j] - '0'] * powmod(10, curlen)) % MOD;
			curlen = (curlen + len[t[i][j] - '0']) % (MOD - 1);
		}
		mod[d[i] - '0'] = curmod;
		len[d[i] - '0'] = curlen;
// 		cout << d[i] << ' ' << curmod << ' ' << curlen << endl;
	}
	cout << mod[0] << endl;
	return 0;
}