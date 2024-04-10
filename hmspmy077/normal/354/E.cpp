#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <ctime>
#include <sstream>
#include <fstream>
#include <bitset>
#include <iomanip>

using namespace std;

typedef long long int64;
typedef long long LL;
typedef long double real;
typedef long double LD;

#define mp make_pair
#define PII pair<int, int>
#define pb push_back
#define sz(X) ((int)((X).size()))

const double eps = 1e-8;
const double PI = acos(0.) * 2;
const int lim = 1000000000;
const int inf = ~0U >> 1;

template<class T> T abs(T x){return x < 0 ? -x : x;}

int color[21][105], col;
string s;
int ans[21][105];

bool dfs(int dep, int rest)
{
	if (dep == sz(s)) return rest == 0;
	if (rest >= 50) return false;
	rest += s[dep];
	color[dep][rest] = true;
 	for (int i = 0; i <= 6; ++i)
		for (int j = 0; i + j <= 6; ++j)
		{
			if (i * 7 + j * 4 > rest) break;
			if (dfs(dep + 1, (rest - i * 7 - j * 4) * 10))
			{
				for (int k = 0; k < 6; ++k)
				{
					if (k < i) ans[dep][k] = 7;
					else if (k < i + j) ans[dep][k] = 4;
					else ans[dep][k] = 0;
				}
				return true;
			}
		}
	return false;
}

int main()
{
	#ifdef LOCAL_TEST
		freopen("c.in","r",stdin);
//		freopen("c.out","w",stdout);
	#endif
	int task;
	cin >> task;
	while (task--)
	{
		long long n;
		cin >> n;
		s = "";
		while (n)
		{
			s = (char)(n % 10) + s;
			n /= 10;
		}
		++col;
		if (!dfs(0, 0)) puts("-1");
		else
		{
			for (int j = 0; j < 6; ++j)
			{
				bool first = false;
				for (int i = 0; i < sz(s); ++i)
				{
					if (i == sz(s) - 1) first = true;
					if (!first && ans[i][j] == 0) continue;
					printf("%d", ans[i][j]);
					first = true;
				}
				if (j != 5) printf(" ");
			}
			puts("");
		}
	}
    return 0;
}