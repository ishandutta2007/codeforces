// Solution by Mukai Yersin
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <set>
#include <map>

#define sz 2000000
#define mp make_pair
#define pb push_back
#define eps 1e-5
#define inf 1<<30
#define INF (long long)(1ll<<62)
#define rep(i, l, r) for (int i = l; i < r; i++)
#define F first
#define S second

typedef long long ll;

using namespace std;

char s[sz];
int ok, n, m, l[100];

int odd(char v) {
	return ((v - '0') % 2 != 0);
}

int main()
{
	scanf("%s", s);
	n = strlen(s);                 
	rep(i, 0, n)
		if (!odd(s[i])) {
			ok = 1;
		}
	if (!ok) {
	 	printf("-1");
	 	return 0;
	}
	if (odd(s[n-1])) {
	 	rep(i, 0, n)
	 		if (!odd(s[i] - '0')) {
	 		 	if (s[i] < s[n - 1]) {
	 		 		swap(s[i], s[n-1]);
	 		 		printf("%s", s);
	 		 		return 0;
	 		 	}
	 		}
		for (int i = n - 1; i >= 0; i--)
	 		if (!odd(s[i] - '0')) {
	 		 	swap(s[i], s[n-1]);
	 		 	printf("%s", s);
	 		 	return 0;
	 		}
	}
	rep(i, 0, n-2)
	 	l[s[i] - '0'] = i;
	rep(i, 0, 10)
		if (l[i]) m = i;
	rep(i, 0, n)
		if (s[i] - '0' < m)	{
			if (s[n - 1] >= m && s[i] % 2 == 0) {
				swap(s[i], s[n - 1]);
			} else swap(s[i], s[m]);
		}
	printf("%s", s);
	return 0;
}