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

const int maxn = 1005;

int a[maxn][maxn];
int max00[maxn][maxn];
int max10[maxn][maxn];
int max01[maxn][maxn];
int max11[maxn][maxn];
int n, m;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			max00[i][j] = max(max00[i - 1][j], max00[i][j - 1]) + a[i][j];
// 			cout << max00[i][j] << ' ';
		}
// 		cout << endl;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = m; j >= 1; j--)
		{
			max01[i][j] = max(max01[i - 1][j], max01[i][j + 1]) + a[i][j];
		}
	}
// 	for (int i = 1; i <= n; i++)
// 	{
// 		for (int j = 1; j <= m; j++) cout << max01[i][j] << ' ';
// 		cout << endl;
// 	}
	for (int i = n; i >= 1; i--)
	{
		for (int j = 1; j <= m; j++) max10[i][j] = max(max10[i + 1][j], max10[i][j - 1]) + a[i][j];
	}
// 	for (int i = 1; i <= n; i++)
// 	{
// 		for (int j = 1; j <= m; j++) cout << max10[i][j] << ' ';
// 		cout << endl;
// 	}
	for (int i = n; i >= 1; i--)
	{
		for (int j = m; j >= 1; j--) max11[i][j] = max(max11[i + 1][j], max11[i][j + 1]) + a[i][j];
	}
// 	for (int i = 1; i <= n; i++)
// 	{
// 		for (int j = 1; j <= m; j++) cout << max11[i][j] << ' ';
// 		cout << endl;
// 	}
	int answer = 0;
	for (int i = 2; i < n; i++)
	{
		for (int j = 2; j < m; j++)
		{
			answer = max(answer, max00[i - 1][j] + max11[i + 1][j] + max10[i][j - 1] + max01[i][j + 1]);
			answer = max(answer, max00[i][j - 1] + max11[i][j + 1] + max10[i + 1][j] + max01[i - 1][j]);
		}
	}
	cout << answer << endl;
	return 0;
}