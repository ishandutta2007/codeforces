/*
The shiny world of freedom
A deadly golden cage
The book of mankind's history
Is on the final page
Movies killing all our sorrows
Tranquilized the mind
Demons put a spell on us
The world's been turning blind

Dreams for sale - fantasy
Sold memories - blown away by a...

Tornado - made by man
Tornado - the whirlwind of doom
Cutting, ripping souls apart
Damned is all our fate
Tornado - a storm of vast decay

The electric cloud of pictures
Increases and devours
Magnetic storms are lashing on
Fed with human power
Bits and codes to flesh and word
The promise of "forever"
Solemn grave of all our dreams
And of all endeavor

Tagged and blogged - our legacy
Raped and torn - blown away by a...

Sail on seas of promises
Into a brave new world
Dream the dream like all the rest
And search for virgin shores
*/

#pragma comment(linker, "/STACK:16777216")
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
const int N = 510;

int n, k;
int used[N][N], C, board[N][N];
int s[N][N];
int in_comp;
int comp_size[N*N];
int white_inside, total_size;
int ans;
int cur_cnt[N*N];
int QX, QY;

bool outside(int x, int y)
{
	return (x<1 || x>n || y<1 || y>n);
}

bool valid(int x, int y)
{
	if (outside(x, y))
		return false;
	if (used[x][y])
		return false;
	if (board[x][y])
		return false;
	return true;
}

void dfs(int x, int y)
{
	used[x][y] = C;
	in_comp++;
	for (int dx = -1; dx <= 1; dx++)
	{
		for (int dy = -1; dy <= 1; dy++)
		{
			if (abs(dx) + abs(dy) != 1)
				continue;
			if (valid(x + dx, y + dy))
				dfs(x + dx, y + dy);
		}
	}
}

int QI, QJ;

void add_cell(int x, int y)
{
	int comp_id = used[x][y];
	if (used[x][y])
	{
		--comp_size[comp_id]; 
		if (cur_cnt[comp_id])
			--total_size;
		white_inside++;
		//cur_cnt[comp_id]++;
	}
}

void add_borderline(int x, int y)
{
	if (used[x][y] == 0)
		return;
	int comp_id = used[x][y];
	if (cur_cnt[comp_id] == 0)
		total_size += comp_size[comp_id];
	cur_cnt[comp_id]++;
}

void remove_cell(int x, int y)
{
	int comp_id = used[x][y];
	if (used[x][y])
	{
		++comp_size[comp_id];
		if (cur_cnt[comp_id])
			total_size++;
		white_inside--;
		cur_cnt[comp_id]--;
		if (cur_cnt[comp_id] == 0)
			total_size -= comp_size[comp_id];
	}
	add_borderline(x, y);
}

void remove_borderline(int x, int y)
{
	if (used[x][y] == 0)
		return;
	int comp_id = used[x][y];
	if (cur_cnt[comp_id] == 1)
		total_size -= comp_size[comp_id];
	cur_cnt[comp_id]--;
}

void move_right()
{
	for (int j = 0; j < k; j++)
	{
		remove_cell(QI + j, QJ);
		remove_borderline(QI + j, QJ - 1);
	}
	remove_borderline(QI - 1, QJ);
	remove_borderline(QI + k, QJ);
	for (int j = 0; j < k; j++)
	{
		add_cell(QI + j, QJ + k);
		add_borderline(QI + j, QJ + k + 1);
	}
	add_borderline(QI - 1, QJ + k);
	add_borderline(QI + k, QJ + k);
	++QJ;
}

void move_left()
{
	for (int j = 0; j < k; j++)
	{
		remove_cell(QI + j, QJ + k - 1);
		remove_borderline(QI + j, QJ + k);
	}
	remove_borderline(QI - 1, QJ + k - 1);
	remove_borderline(QI + k, QJ + k - 1);
	for (int j = 0; j < k; j++)
	{
		add_cell(QI + j, QJ - 1);
		add_borderline(QI + j, QJ - 2);
	}
	add_borderline(QI - 1, QJ - 1);
	add_borderline(QI + k, QJ - 1);
	--QJ;
}

void move_down()
{
	for (int j = 0; j < k; j++)
	{
		remove_cell(QI, QJ + j);
		remove_borderline(QI - 1, QJ + j);
	}
	remove_borderline(QI, QJ - 1);
	remove_borderline(QI, QJ + k);
	for (int j = 0; j < k; j++)
	{
		add_cell(QI + k, QJ + j);
		add_borderline(QI + k + 1, QJ + j);
	}
	add_borderline(QI + k, QJ - 1);
	add_borderline(QI + k, QJ + k);
	++QI;
}

void trace()
{
	cout << "!"<<QI<<" "<<QJ<<" "<<total_size << " " << white_inside << " "<<total_size<<endl;
	for (int i = 1; i <= C; i++)
		cout << comp_size[i] << " ";
	cout << endl;
	for (int i = 1; i <= C; i++)
	{
		cout << cur_cnt[i] << " ";
	}
	cout << endl;
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		string st;
		cin >> st;
		for (int j = 1; j <= n; j++)
		{
			if (st[j - 1] == '.')
				board[i][j] = 0;
			else
				board[i][j] = 1;
		}
	}
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (used[i][j])
				continue;
			if (board[i][j])
				continue;
			++C;
			in_comp = 0;
			dfs(i, j);
			comp_size[C] = in_comp;
		}
	}
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + board[i][j];
		}
	}

	if (k == n)
	{
		cout << n*n << endl;
		return 0;
	}

	for (int i = 1; i <= k; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			cur_cnt[used[i][j]]++;
			if (used[i][j])
				total_size++;
			add_cell(i, j);
			//comp_size[used[i][j]]--;
		}
	}
	
	for (int i = 1; i <= C; i++)
	{
		if (cur_cnt[i])
			total_size += comp_size[i];
	}
//	trace();

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (max(i, j) == k + 1&&min(i,j)<=k)
				add_borderline(i, j);
		}
	}

///	trace();

	QI = 1;
	QJ = 1;
	//cout << comp_size[1] << endl;
	//cout << total_size << " " << white_inside << endl;

	for (int i = 1; i <= n-k+1; i++)
	{
		if (i % 2 == 1)
		{
			ans = max(ans, total_size+k*k);
			for (int j = 1; j <= n - k; j++)
			{
				move_right();
		//		trace();
				ans = max(ans, total_size + k*k);
			}
			move_down();
		//	trace();
		}
		else
		{
			ans = max(ans, total_size + k*k);
			for (int j = 1; j <= n - k; j++)
			{
				move_left();
		//		trace();
				ans = max(ans, total_size + k*k);
			}
			move_down();
		//	trace();
		}
	}

	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}