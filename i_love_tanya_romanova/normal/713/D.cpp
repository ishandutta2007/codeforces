/*
*/

//#pragma comment(linker, "/STACK:16777216")
#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
#include <assert.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 350

using namespace std;

const int INF = 1e9;
const int N = 1031;
const int T = 1000031;

int n, m, ar[N][N];
short SZ[N][N];
int s[N][N];

bool bad_cell(int a, int b, int side)
{
	if (a + side - 1 > n || b + side - 1 > m)
		return true;
	int area = side*side;
	int here = s[a + side - 1][b + side - 1] - s[a + side - 1][b-1] - s[a-1][b + side - 1] + s[a - 1][b - 1];
	return (here != area);
}

int gbest;
int tests;
int x1[T], y1[T], x2[T], y2[T];
int l[T], r[T];

vector<pair<int, int> > events[N];

int t[N][N];
vector<int> checklist[N];

inline int sum(int x, int y)
{
	int res = 0;
	for (int i = x; i >= 0; i = (i&(i + 1)) - 1)
	{
		for (int j = y; j >= 0; j = (j&(j + 1)) - 1)
			res += t[i][j];
	}
	return res;
}

inline void inc(int x, int y, int val)
{
	for (int i = x; i <=n; i = (i | (i + 1)))
	{
		for (int j = y; j <= m; j = (j | (j + 1)))
		{
			t[i][j] += val;
		}
	}
}

short AR[N][N];
int S[75][N][N];

const int STEP = 16;

int next_divisible(int val)
{
	if (val % STEP == 0)
		return val + STEP;
	return val - val % STEP + STEP;
}

bool check(int id,int whr)
{
	if (whr == 0)
		return true;
	//cout << S[whr][x2[id] - whr * STEP + 1][y2[id] - whr * STEP + 1] - S[whr][x1[id] - 1][y2[id] - whr * STEP + 1] - S[whr][x2[id] - whr * STEP + 1][y1[id] - 1] +
		//S[x1[id] - 1][y1[id] - 1] << endl;
	return S[whr][x2[id] - whr * STEP + 1][y2[id] - whr * STEP + 1] - S[whr][x1[id] - 1][y2[id] - whr * STEP + 1] - S[whr][x2[id] - whr * STEP + 1][y1[id]-1] +
		S[whr][x1[id] - 1][y1[id] - 1];
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	scanf("%d", &n);
	scanf("%d", &m);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &ar[i][j]);
			//ar[i][j] = 1;

			/*if (rand() % 100)
				ar[i][j] = 0;
			else
				ar[i][j] = 1;
			*/
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1]+ar[i][j];
		}
	}
	
	for (int i = n; i; i--)
	{
		for (int j = m; j;--j)
		{
			SZ[i][j] = SZ[i + 1][j + 1] + 1;
			while (bad_cell(i, j, SZ[i][j]))
				--SZ[i][j];
			gbest = max(gbest, (int)SZ[i][j]);
			if (SZ[i][j])
				events[SZ[i][j]].push_back(make_pair(i, j));
		}
	}
	
	for (int iter = max(n,m); iter >=0; iter--)
	{
		for (int i = 0; i < events[iter].size(); i++)
		{
			pair<int, int> p = events[iter][i];
			AR[p.first][p.second] = 1;
		}

		/*for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				cout << AR[i][j] << " ";
			}
		}
		cout << endl;
		*/

		if (iter % STEP == 0)
		{
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= m; j++)
				{
					S[iter / STEP][i][j] = S[iter / STEP][i - 1][j] + S[iter / STEP][i][j - 1] - S[iter / STEP][i - 1][j - 1] + AR[i][j];
				}
			}
		}
	}

	scanf("%d", &tests);
	for (int test = 1; test <= tests; test++)
	{
		scanf("%d", &x1[test]);
		scanf("%d", &y1[test]);
		scanf("%d", &x2[test]);
		scanf("%d", &y2[test]);
		/*x1[test] = rand() % 10 + 1;
		y1[test] = rand() % 10 + 1;
		x2[test] = n - rand() % 10;
		y2[test] = n - rand() % 10;
		*/
		l[test] = 0;
		r[test] = min(x2[test] - x1[test] + 1, y2[test] - y1[test] + 1);
		r[test] = min(r[test], gbest);

		while (r[test] - l[test] >= STEP)
		{
			int v = next_divisible(l[test]);
			//cout << test << "%" << v << " " << check(test, v / STEP) << endl;

			if (check(test, v/STEP))
				l[test] = v;
			else
				r[test] = v - 1;
		}
	}
	
	while (true)
	{
		for (int i = 0; i <= 1000; i++)
		{
			checklist[i].clear();
		}
		int flag = 0;
		for (int i = 1; i <= tests; i++)
		{
			if (l[i] == r[i])
				continue;
			flag = 1;
			int mid = l[i] + r[i]+1;
			mid /= 2;
			checklist[mid].push_back(i);
		}
		if (flag == 0)
			break;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				t[i][j] = 0;
			}
		}

		for (int i = 1000; i >= 0; i--)
		{
			for (int j = 0; j < events[i].size(); j++)
			{
				int tx = events[i][j].first;
				int ty = events[i][j].second;
				inc(tx, ty, 1);
				//cout << tx << "^" << ty << " " << i << endl;
			}

			for (int j = 0; j < checklist[i].size(); j++)
			{
				int id = checklist[i][j];
				if (i == 0)
				{
					l[id] = 0;
					continue;
				}
				int here = sum(x2[id] - i + 1, y2[id] - i + 1) - sum(x1[id] - 1, y2[id] - i + 1) 
					- sum(x2[id] - i + 1, y1[id] - 1) + sum(x1[id] - 1, y1[id] - 1);
				//cout << i << "%" << id << " " << here << endl;
				/*cout << sum(x2[id] - i + 1, y2[id] - i + 1) << endl;
				cout << sum(x1[id] - 1, y2[id] - i + 1) << endl;
				cout << sum(x2[id] - i + 1, y1[id] - 1) << endl;
				cout << sum(x1[id] - 1, y1[id] - 1) << endl;
				*/
				if (here)
					l[id] = i;
				else
					r[id] = i - 1;
			}
		}
	}

	for (int i = 1; i <= tests; i++)
	{
		printf("%d\n", l[i]);
	}

	cin.get(); cin.get();
	return 0;
}