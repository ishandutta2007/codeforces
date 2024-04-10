#include <cstdio>
#include <algorithm>
#include <cassert>
 
using namespace std;
 
const int maxn = 1010, INF = 100000;
const int P[2] = {2, 5};
int n, Cnt[2][maxn][maxn], Dp[2][2][maxn][maxn], Min0[2];
bool Is0[maxn][maxn] = {0};
char Way[2][maxn][maxn];
 
inline bool isnum(char c)
{ return '0' <= c && c <= '9'; }
int read_int()
{
	char c;
	int s = 0;
	while(!isnum(c = getchar()));
	do
		s = s * 10 + c - '0';
	while(isnum(c = getchar()));
	return s;
}
int cnt(int x, int p)
{
	if(x == 0) return 1;
	int u = 0;
	while(!(x % p))
	{
		x /= p;
		u++;
	}
	return u;
}
void read_input()
{
	n = read_int();
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			int w = read_int();
			if(w == 0) Is0[i][j] = 1;
			for(int k = 0; k < 2; k++)
				Cnt[k][i][j] = cnt(w, P[k]);
		}
	assert(!Is0[n - 1][n - 1]);
}
 
void dp(int k)
{
	Way[k][n - 1][n - 1] = -1;
	for(int w = 0; w < 2; w++)
		Dp[k][w][n - 1][n - 1] = Cnt[w][n - 1][n - 1];
	for(int i = n - 2; i >= 0; i--)
	{
		Way[k][i][n - 1] = 'D';
		for(int w = 0; w < 2; w++)
			Dp[k][w][i][n - 1] = Dp[k][w][i + 1][n - 1] + Cnt[w][i][n - 1];
	}
	for(int j = n - 2; j >= 0; j--)
	{
		Way[k][n - 1][j] = 'R';
		for(int w = 0; w < 2; w++)
			Dp[k][w][n - 1][j] = Dp[k][w][n - 1][j + 1] + Cnt[w][n - 1][j];
	}
	for(int i = n - 2; i >= 0; i--)
		for(int j = n - 2; j >= 0; j--)
			if(Dp[k][k][i + 1][j] <= Dp[k][k][i][j + 1])
			{
				Way[k][i][j] = 'D';
				for(int w = 0; w < 2; w++)
					Dp[k][w][i][j] = Dp[k][w][i + 1][j] + Cnt[w][i][j];
			}
			else
			{
				Way[k][i][j] = 'R';
				for(int w = 0; w < 2; w++)
					Dp[k][w][i][j] = Dp[k][w][i][j + 1] + Cnt[w][i][j];
			}
}
 
void show_way(int i, int j, int k)
{
	while(Way[k][i][j] != -1)
	{
		putchar(Way[k][i][j]);
		if(Way[k][i][j] == 'D') i++;
		else j++;
	} 
}
 
int main()
{
	//freopen("least.in", "r", stdin);
	read_input();
	for(int k = 0; k < 2; k++)
	{
		dp(k); 
		Min0[k] = min(Dp[k][0][0][0], Dp[k][1][0][0]);
	}
	int k = Min0[0] <= Min0[1] ? 0 : 1;
	if(Min0[k] > 1)
	{
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if(Is0[i][j])
					Cnt[0][i][j] = -INF;
		dp(0);
		if(Dp[0][0][0][0] < 0)
		{
			Min0[0] = 1;
			k = 0;
		}
	}
	printf("%d\n", Min0[k]);
	show_way(0, 0, k);
	return 0; 
}