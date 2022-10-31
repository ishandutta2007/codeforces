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
#define B 1000

typedef long long ll;

using namespace std;

int ans, m, t, r, a[sz], k[sz], ok[sz], j;

int main()
{
	scanf("%d %d %d", &m, &t, &r);	
	rep(i, 0, m) {
		scanf("%d", &a[i]);
		k[i] = r;
	}
	rep(i, 0, m) {
		j = a[i] - 1;
	 	while (k[i] > 0 && j + t >= a[i]) {
	 	 	if (!ok[j+B]) {
	 	 	 	ok[j+B] = 1;
	 	 	 	rep(e, i, m)
	 	 	 		if (j + t >= a[e]) {
						k[e]--;
	 	 	 		} else break;
	 	 	 	ans++;
	 	 	}
	 	 	j--;
	 	}
	 	if (k[i] > 0) {
	 	 	printf("-1");
	 	 	return 0;
	 	}
	}
	printf("%d", ans);
	return 0;
}