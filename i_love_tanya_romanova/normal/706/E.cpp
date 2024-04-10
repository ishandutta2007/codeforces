/*
The way I see may make you blind
The way I think may scar your mind
And evil are the words I speak
I am sin and sin you seek

Begging...
Thirsting...
Feeding...
...My hunger never at ease

Seduce/deceive
Go hand in hand
In my eyes they're the same
And you always knew
And you still beg
For the serpent's kiss

Do you dare to taste my soul
Do you dare among the serpent's roll
And to wed their eyes and lick their tongues
I am them and your flesh is young

Crawling close
I'm the one you fear
But when I'm gone
You wish me near

Seduce/deceive
Go hand in hand
In my eyes they're the same
And you always knew
And you still beg
For the serpent's kiss

You tasted me
I tasted you
Your naked flesh
Your life undo

Seduce/deceive
Go hand in hand
In my eyes they're the same
And you always knew
And you still beg
For the serpent's kiss
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
const int N = 1100;
const int M = 20000;

int n, m, q;
pair<short, short> l[N][N], r[N][N], u[N][N], d[N][N];
int ar[N][N];

pair<short, short> v1[N * 6], v2[N * 6];

pair<short, short> get_ptr(int a, int b)
{
	pair<int, int> P = make_pair(a, 0);
	for (int i = 1; i <= b; i++)
	{
		P = r[P.first][P.second];
	}
	return P;
}

inline void r_swap(pair<short, short> &p1, pair<short, short> &p2)
{
	swap(r[p1.first][p1.second], r[p2.first][p2.second]);
	p1 = r[p1.first][p1.second];
	p2 = r[p2.first][p2.second];
	swap(l[p1.first][p1.second], l[p2.first][p2.second]);
}

inline void l_swap(pair<short, short> &p1, pair<short, short> &p2)
{
	swap(l[p1.first][p1.second], l[p2.first][p2.second]);
	p1 = l[p1.first][p1.second];
	p2 = l[p2.first][p2.second];
	swap(r[p1.first][p1.second], r[p2.first][p2.second]);
}

inline void u_swap(pair<short, short>& p1, pair<short, short> &p2)
{
	swap(u[p1.first][p1.second], u[p2.first][p2.second]);
	p1 = u[p1.first][p1.second];
	p2 = u[p2.first][p2.second];
	swap(d[p1.first][p1.second], d[p2.first][p2.second]);
}

inline void d_swap(pair<short, short>& p1, pair<short, short> &p2)
{
	swap(d[p1.first][p1.second], d[p2.first][p2.second]);
	p1 = d[p1.first][p1.second];
	p2 = d[p2.first][p2.second];
	swap(u[p1.first][p1.second], u[p2.first][p2.second]);
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &ar[i][j]);
			//cin >> ar[i][j];
		}
	}

	for (int i = 0; i <= n + 1; i++)
	{
		for (int j = 0; j <= m + 1; j++)
		{
			l[i][j] = make_pair(i, j - 1);
			r[i][j] = make_pair(i, j + 1);
			u[i][j] = make_pair(i - 1, j);
			d[i][j] = make_pair(i + 1, j);
		}
	}

	for (; q; --q)
	{
		int x1, y1, x2, y2, w, h;

		int ptr = 0;

		scanf("%d", &x1);
		scanf("%d", &y1);
		scanf("%d", &x2);
		scanf("%d", &y2);
		scanf("%d", &h);
		scanf("%d", &w);
		//		cin >> x1 >> y1 >> x2 >> y2 >> h >> w;
		pair<short, short> P = get_ptr(x1 - 1, y1);
		pair<short, short> P2 = get_ptr(x2 - 1, y2);
		// uppr side

		for (int i = 1; i <= w; i++)
		{
			v1[ptr] = P;
			v2[ptr] = P2;
			++ptr;
			P = r[P.first][P.second];
			P2 = r[P2.first][P2.second];
		}

		P = d[P.first][P.second];
		P2 = d[P2.first][P2.second];
		// r side
		for (int i = 1; i <= h; i++)
		{
			v1[ptr] = P;
			v2[ptr] = P2;
			++ptr;
			//swap(l[P.first][P.second], l[P2.first][P2.second]);
			P = d[P.first][P.second];
			P2 = d[P2.first][P2.second];
		}
		P = l[P.first][P.second];
		P2 = l[P2.first][P2.second];
		// bot
		for (int i = 1; i <= w; i++)
		{
			v1[ptr] = P;
			v2[ptr] = P2;
			++ptr;
			//			swap(u[P.first][P.second], u[P2.first][P2.second]);
			P = l[P.first][P.second];
			P2 = l[P2.first][P2.second];
		}
		//ls
		P = u[P.first][P.second];
		P2 = u[P2.first][P2.second];
		for (int i = 1; i <= h; i++)
		{
			v1[ptr] = P;
			v2[ptr] = P2;
			++ptr;
			//swap(r[P.first][P.second], r[P2.first][P2.second]);
			P = u[P.first][P.second];
			P2 = u[P2.first][P2.second];
		}

		/*	for (int i = 0; i < v1.size(); i++)
		{
		cout << v1[i].first << " " << v1[i].second << " " << v2[i].first << " " << v2[i].second << endl;
		}
		*/
		// left side swap
		pair<short, short> p1, p2;

		for (int i = 1; i <= h; i++)
		{
			--ptr;
			r_swap(v1[ptr], v2[ptr]);
		}

		/*	for (int q = 0; q < v1.size(); q++)
		{
		cout << v1[q].first << " " << v2[q].first << "%" << endl;
		}
		*/
		// bott
		for (int i = 1; i <= w; i++)
		{
			--ptr;
			u_swap(v1[ptr], v2[ptr]);
		}
		// r side

		for (int i = 1; i <= h; i++)
		{
			--ptr;
			l_swap(v1[ptr], v2[ptr]);
			//	cout << p1.first << " " << p1.second << " " << p2.first << " " << p2.second << " " << p3.first << " " << p3.second << " " << p4.first << " " << p4.second << endl;
		}
		// topmost
		for (int i = 1; i <= w; i++)
		{
			--ptr;
			d_swap(v1[ptr], v2[ptr]);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		pair<int, int> P = get_ptr(i, 1);
		for (int j = 1; j <= m; j++)
		{
			if (j > 1)
				printf(" ");
			printf("%d", ar[P.first][P.second]);
			//			cout << ar[P.first][P.second];
			P = r[P.first][P.second];
		}
		cout << "\n";
	}

	cin.get(); cin.get();
	return 0;
}