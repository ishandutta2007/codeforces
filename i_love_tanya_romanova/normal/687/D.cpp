/*
I've talked the talk, I've walked the walk
It's taken ten fucking years
For them to see I don't need their approval

I've paid the piper, I've stayed my course
Lived chomping at the bit
With only blood, sweat and tears to adhere to

Open your eyes and see that it's so menacing
You need to realize that bleeding is a luxury
Give 'til there's nothing left, value in every breath
You need to realize that bleeding is a luxury

Take it for granted, forsake the cost
We're a big shit eating crowd
With only blood, sweat and tears to adhere to

Not there to burn at the chase, you're a pig
And you think that fucking hurts
So they can see, I don't need their approval

Open your eyes and see that it's so menacing
You need to realize that bleeding is a luxury
Give 'til there's nothing left, value in every breathe
You need to realize that bleeding is a luxury

Everyday, take your beatings
Lead the way or decay as you fall down
You fall down

Open your eyes and see that it's so menacing
You need to realize that bleeding is a luxury
Give 'til there's nothing left, value in every breathe
You need to realize that bleeding is a luxury
It's a luxury, bleeding is a luxury
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
const int N = 500031;

int n, m, tests;
int a[N], b[N], c[N];
vector<pair<int, int> >order;
int L[N], R[N];

int w[1010];
char clr[1010];
int fkup[1010];

void update(int q, int id)
{
	if (w[a[id]] == w[b[id]])
	{
		if (clr[a[id]] == clr[b[id]])
		{
			fkup[q] = max(fkup[q], c[id]);
			return;
		}
		return;
	}
	int flag = (clr[a[id]] == clr[b[id]]);
	int nw = w[a[id]];
	int old = w[b[id]];
	for (int i = 1; i <= n; i++)
	{
		if (w[i] == old)
		{
			clr[i] ^= flag;
			w[i] = nw;
		}
	}
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
	scanf("%d", &tests);

	/*n = 1000;
	m = 500000;
	tests = 1000;
	*/
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &a[i]);
		scanf("%d", &b[i]);
		scanf("%d", &c[i]);

		/*a[i] = rand() % n + 1;
		b[i] = rand() % n + 1;
		c[i] = rand() % 1000000;
		*/
		order.push_back(make_pair(c[i], i));
	}

	sort(order.begin(), order.end());
	reverse(order.begin(), order.end());

	for (int i = 1; i <= tests; i++)
	{
		scanf("%d", &L[i]);
		scanf("%d", &R[i]);
		/*L[i] = 1;
		R[i] = n;
		if (L[i] > R[i])
		swap(L[i], R[i]);*/
	}

	for (int i = 1; i <= tests; i++)
		fkup[i] = -1;

	for (int j = 1; j <= tests; j++)
	{
		for (int i = 1; i <= n; i++)
		{
			w[i] = i;
			clr[i] = 0;
		}
		for (int i = 0; i < order.size(); i++)
		{
			int id = order[i].second;
			if (L[j] <= id&&R[j] >= id&&fkup[j] == -1)
			{
				update(j, id);
			}
		}
		printf("%d\n", fkup[j]);
	}

	cin.get(); cin.get();
	return 0;
}