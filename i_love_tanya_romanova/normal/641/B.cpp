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
#define bsize 256

using namespace std;

const int INF = 1e9;
const int N = 50031;

pair<int,int> board[105][105];
int res[105][105];

int n, m, queries;

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n >> m >> queries;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			board[i][j] = make_pair(i, j);
		}
	}

	for (; queries; --queries)
	{
		int tp;
		cin >> tp;
		if (tp == 1)
		{
			int id;
			cin >> id;
			--id;
			pair<int,int> temp = board[id][0];
			for (int i = 0; i < m; i++)
			{
				board[id][i] = board[id][i + 1];
			}
			board[id][m - 1] = temp;
		}
		if (tp == 2)
		{
			int id;
			cin >> id;
			--id;
			pair<int, int> temp;
			temp = board[0][id];
			for (int i = 0; i < n; i++)
			{
				board[i][id] = board[i + 1][id];
			}
			board[n - 1][id] = temp;
		}
		if (tp == 3)
		{
			int a, b, val;
			cin >> a >> b >> val;
			--a;
			--b;
			res[board[a][b].first][board[a][b].second] = val;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (j)
				cout << " ";
			cout << res[i][j];
		}
		cout << endl;
	}

	cin.get(); cin.get();
	return 0;
}