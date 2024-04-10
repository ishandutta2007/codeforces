/*
Sometimes I feel
Like I don't have a partner
Sometimes I feel
Like my only friend
Is the city I live in
The city of angels
Lonely as I am
Together we cry

I drive on her streets
'Cause she's my companion
I walk through her hills
'Cause she knows who I am
She sees my good deeds
And she kisses me windy
I never worry
Now that is a lie

I don't ever wanna feel
Like I did that day
But take me to the place I love
Take me all the way
I don't ever wanna feel
Like I did that day
But take me to the place I love
Take me all the way

It's hard to believe
That there's nobody out there
It's hard to believe
That I'm all alone
At least I have her love
The city she loves me
Lonely as I am
Together we cry

I don't ever wanna feel
Like I did that day
But take me to the place I love
Take me all the way
I don't ever wanna feel
Like I did that day
But take me to the place I love
Take me all the way

Under the bridge downtown
Is where I drew some blood
Under the bridge downtown
I could not get enough
Under the bridge downtown
Forgot about my love
Under the bridge downtown
I gave my life away
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

int n;
struct circ
{
	int x;
	int y;
	int r;
};

struct pt
{
	double x;
	double y;
};

circ c[N];
int used[N];
vector<int> comp;
int COMPS;
int ans;
vector<pt> all_ip;
vector<pt> IP;

bool equal(pt a, pt b)
{
	return (fabs(a.x - b.x) < eps&&fabs(a.y - b.y) < eps);
}

double get_dist(circ a, circ b)
{
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

bool do_intersect(circ a, circ b)
{
	if (a.r < b.r)
		swap(a, b);
	return get_dist(a, b) < a.r + b.r + eps&&get_dist(a, b) >= a.r - b.r - eps;
}

void dfs(int v)
{
	comp.push_back(v);
	used[v] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (do_intersect(c[v],c[i]) == 1 && used[i] == 0)
		{
			dfs(i);
		}
	}
}

struct line
{
	double a;
	double b;
	double c;
};

vector<pt> intersect(circ a, line l)
{
	vector<pt> res;

	double x0 = -l.a*l.c / (l.a*l.a + l.b*l.b);
	double y0 = -l.b*l.c / (l.a*l.a + l.b*l.b);
	if (l.c*l.c > a.r*a.r*(l.a*l.a + l.b*l.b) + eps)
		return res;
	if (fabs(l.c*l.c - a.r*a.r*(l.a*l.a + l.b*l.b)) < eps)
	{
		pt temp;
		temp.x = x0;
		temp.y = y0;
		res.push_back(temp);
		return res;
	}

	double d = a.r*a.r - l.c*l.c / (l.a*l.a + l.b*l.b);
	double mult = sqrt(d / (l.a*l.a + l.b*l.b));
	double ax, ay, bx, by;
	ax = x0 + l.b*mult;
	bx = x0 - l.b*mult;
	ay = y0 - l.a*mult;
	by = y0 + l.a*mult;
	pt temp;
	temp.x = ax;
	temp.y = ay;
	res.push_back(temp);
	temp.x = bx;
	temp.y = by;
	res.push_back(temp);
	return res;
}

vector<pt> intersect(circ a, circ b)
{
	b.x -= a.x;
	b.y -= a.y;
	line L;
	L.a = -2 * b.x;
	L.b = -2 * b.y;
	L.c = (b.x*b.x + b.y*b.y + a.r*a.r - b.r*b.r);
	vector<pt> solutions = intersect(a, L);
	for (int i = 0; i < solutions.size(); i++)
	{
		solutions[i].x += a.x;
		solutions[i].y += a.y;
	}
	return solutions;
}

bool cmp(pt a, pt b)
{
	if (fabs(a.x - b.x)>eps)
		return (a.x < b.x);
	return a.y < b.y;
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n;
	//n=3;
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i].x >> c[i].y >> c[i].r;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (c[i].x == c[j].x&&c[i].y == c[j].y&&c[i].r == c[j].r)
				used[j] = 1;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (used[i])
			continue;
		comp.clear();
		dfs(i);
		COMPS++;
		all_ip.clear();
		//v+f-e=2;

		int vertices = 0;
		int edges = 0;

		for (int j = 0; j < comp.size(); j++)
		{
			IP.clear();

			for (int q = 0; q < comp.size(); q++)
			{
				if (j == q)
					continue;
				vector<pt> V = intersect(c[comp[j]], c[comp[q]]);
				for (int t = 0; t < V.size(); t++)
				{
					IP.push_back(V[t]);
				}
			}

			/*for (int q = 0; q < IP.size(); q++)
			{
				cout << IP[q].x << " " << IP[q].y << endl;
			}
			cout << endl;
			*/
			int cnt = 0;

			sort(IP.begin(), IP.end(), cmp);
			for (int q = 0; q < IP.size(); q++)
			{
				if (q == 0 || !equal(IP[q], IP[q - 1]))
					++cnt;
			}
			if (cnt>0)
			{
				edges += cnt;
			}

			for (int q = 0; q < IP.size(); q++)
			{
				all_ip.push_back(IP[q]);
			}
		}

		sort(all_ip.begin(), all_ip.end(), cmp);

		for (int j = 0; j < all_ip.size(); j++)
		{
			if (j == 0 || !equal(all_ip[j], all_ip[j-1]))
				vertices++;
		}

		//cout << vertices << " " << edges << endl;

		ans += -vertices + 2 + edges;
	}

	ans -= COMPS - 1;

	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}