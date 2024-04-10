/*
In a land where no love can be born
Self destruction everywhere
A restless soul on it's search for an answer
Sees through this masquerade of dispair
In a time where no love can be born
Desperation frozen eyes
A restless soul so alone no direction
Suffering as they follow the blind

This is a new dawn rising
Over this Shadowland
Tearing you from the world that you used to know

In a land where no love can be born
Isolation is the price
And the horror of this cold souless place here
Put everlasting stains on your life
In a time where no love can be born
Another crisis yet to come
A senseless life breeds a senseless death
Wondering what kind of pain will come next

Tired of being alive losing every time
Suffering side by side shadows of mankind
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
#include <ctime> 
#include <assert.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1234567891
#define bsize 512

const int N = 210000;

using namespace std;

int n, m, k;
string st;
int t[N*4][10][10];
int Where[100];
int topush[N * 4];
int lmost[N * 4];
int rmost[N * 4];

void combine(int v)
{
	lmost[v] = lmost[v * 2];
	rmost[v] = rmost[v * 2 + 1];
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < k; j++)
			t[v][i][j] = t[v * 2][i][j] + t[v * 2 + 1][i][j];
	}
	t[v][rmost[v * 2]][lmost[v * 2 + 1]]++;
}

void build(int v, int tl, int tr)
{
	topush[v] = -1;

	if (tl == tr)
	{
		lmost[v] = rmost[v] = st[tl] - 'a';
		return;
	}
	int tm = tl + tr;
	tm /= 2;
	build(v * 2, tl, tm);
	build(v * 2 + 1, tm + 1, tr);
	combine(v);
}

void push(int v, int tl, int tr)
{
	if (topush[v] == -1)
		return;
	int tm = tl + tr;
	tm /= 2;
	topush[v * 2] = topush[v * 2 + 1] = topush[v];
	lmost[v * 2] = rmost[v * 2] = lmost[v * 2 + 1] = rmost[v * 2 + 1] = topush[v];
	for (int i = 0; i<k; i++)
	{
		for (int j = 0; j < k; j++)
		{
			t[v * 2][i][j] = t[v * 2 + 1][i][j] = 0;
		}
	}
	t[v * 2][topush[v]][topush[v]] = tm - tl;
	t[v * 2 + 1][topush[v]][topush[v]] = tr - tm - 1;
	
	topush[v] = -1;
}

void update(int v, int tl, int tr, int l, int r, int val)
{
	if (l>r)
		return;
	if (tl == l&&tr == r)
	{
		lmost[v] = rmost[v] = val;
		for (int i = 0; i < k; i++)
		{
			for (int j = 0; j < k; j++)
			{
				t[v][i][j] = 0;
			}
		}
		t[v][val][val] = tr - tl;
		topush[v] = val;
		return;
	}
	push(v, tl, tr);
	int tm = tl + tr;
	tm /= 2;
	update(v * 2, tl, tm, l, min(r, tm), val);
	update(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r, val);
	combine(v);
}

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n >> m >> k;
	
	cin >> st;

	build(1, 0, n - 1);

	for (; m; --m)
	{
		int tp;
		cin >> tp;
		if (tp == 1)// update
		{
			string st;
			int l, r;
			cin >> l >> r >> st;
			--l;
			--r;
			update(1, 0, n-1, l, r, st[0] - 'a');
		}
		if (tp == 2)// get
		{
			string st;
			cin >> st;
			for (int i = 0; i < st.size(); i++)
			{
				Where[st[i] - 'a'] = i;
			}
			int ans = 1;
			for (int i = 0; i < k; i++)
			{
				for (int j = 0; j < k; j++)
				{
					if (Where[i] >= Where[j])
						ans += t[1][i][j];
				}
			}
			cout << ans << endl;
		}
	}
	cin.get(); cin.get();
	return 0;
}