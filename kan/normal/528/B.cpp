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

const int maxn = 200005;

int l[maxn], r[maxn];
bool was[maxn];
int alll[maxn], allr[maxn];

int n;

inline bool cmpl(int a, int b)
{
	return l[a] < l[b];
}

inline bool cmpr(int a, int b)
{
	return r[a] < r[b];
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x, w;
		scanf("%d%d", &x, &w);
		l[i] = x - w;
		r[i] = x + w;
		allr[i] = i;
		alll[i] = i;
	}
	sort(alll, alll + n, cmpl);
	sort(allr, allr + n, cmpr);
	for (int i = 0; i < n; i++) was[i] = false;
	int cur = 0;
	int answer = 0;
	for (int i = 0; i < n; i++) if (!was[allr[i]])
	{
		answer++;
		while (cur < n && l[alll[cur]] < r[allr[i]])
		{
			was[alll[cur]] = true;
			cur++;
		}
	}
	cout << answer << endl;
	return 0;
}