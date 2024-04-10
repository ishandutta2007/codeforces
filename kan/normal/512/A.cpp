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

char ans[50];
char s[105][105];
int n, kv;
vector<int> gr[500];
int was[500];

void go(int cur)
{
// 	cout << "go " << cur << ' ' << was[cur] << endl;
	if (was[cur] == 1)
	{
		printf("Impossible\n");
		exit(0);
	}
	if (was[cur] == 2) return;
	was[cur] = 1;
	for (auto v : gr[cur]) go(v);
	was[cur] = 2;
	ans[kv++] = cur;
// 	cout << "Ret " << cur << endl;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", s[i]);
	}
	for (int i = 0; i + 1 < n; i++)
	{
		int len = min(strlen(s[i]), strlen(s[i + 1]));
		bool f = false;
		for (int j = 0; j < len; j++) if (s[i][j] != s[i + 1][j])
		{
			gr[s[i + 1][j]].push_back(s[i][j]);
// 			cout << s[i + 1][j] << ' ' << s[i][j] << endl;
			f = true;
			break;
		}
		if (!f)
		{
			if (strlen(s[i]) > strlen(s[i + 1]))
			{
				printf("Impossible\n");
				return 0;
			}
		}
	}
// 	cout << "sadg" << endl;
	kv = 0;
	for (int i = 'a'; i <= 'z'; i++) go(i);
	ans[26] = 0;
	printf("%s\n", ans);
	return 0;
}