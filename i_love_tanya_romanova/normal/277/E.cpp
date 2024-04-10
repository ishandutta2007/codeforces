/*
We're walking, the streets
We know where, we'll meet
Can't stop us
They don't know why
They try

Can't hurt us
We'll never die
We are on the march of the damned
Of the damned

March of the damned

We know what's, at stake
Won't take your, mistakes

Can't break us
We'll never fall
That's all

It's over, just watch us grow
We are on the march of the damned
Of the damned

March of the damned

We're walking the streets
We know where we'll meet

Can't stop us
They don't know why
They try

Can't hurt us
We'll never die
We are on the march of the damned
Of the damned

March of the damned
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
const int SZ = 300000;

struct rib
{
	int b, u;
	double c;
	int f;
	int back;
};

vector<rib> g[SZ];

void add_rib(int a, int b, int u, double c)
{
	rib r1 = { b, u, c, 0, g[b].size() };
	rib r2 = { a, 0, -c, 0, g[a].size() };
	//cout << "@" << r1.c << " " << r2.c << endl;
	g[a].push_back(r1);
	g[b].push_back(r2);
}

int n; int k;

int ar[200][200];
int m;

double get_dist(pair<int, int> p1, pair<int, int> p2)
{
	return sqrt((p1.first - p2.first)*(p1.first - p2.first) + (p1.second - p2.second)*(p1.second - p2.second));
}

vector<pair<int, int> > v;

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(-b, a));
	}
	
	sort(v.begin(), v.end());

	if (v.size()>1 && v[1].first == v[0].first)
	{
		cout << -1 << endl;
		return 0;
	}

	for (int i = 1; i < v.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (v[j].first == v[i].first)
				continue;
			//cout << i << " " << j << " " << get_dist(v[i], v[j]) << endl;

			//cout << i + 1 << " " << n + j + 1 << " " << get_dist(v[i], v[j]) << endl;

			add_rib(i+1, n + j+1, 1, get_dist(v[i], v[j]));
		}
	}

	for (int i = 1; i <= n; i++)
	{
		add_rib(0, i, 1, 0);
	}

	for (int i = 1; i <= n; i++)
	{
		add_rib(i + n, 2 * n + 1, 2, 0);
	}

	int flow = 0;
	double cost = 0;

	int need = n - 1;
	int s, t;
	s = 0;
	t = 2 * n + 1;
	n = t + 1;

	while (flow<need)
	{
		vector<int> id(n, 0);
		vector<double> d(n, INF);
		vector<int> q(n);
		vector<int> p(n);
		vector<int> p_rib(n);
		int qh = 0;
		int qt = 0;
		q[0] = s;
		qt++;
		d[s] = 0;
		while (qh != qt)
		{
			//cout << qh << " " << qt << " " << q[qh] << " " << d[q[qh]] << endl;
		//	cin.get();
			int v = q[qh];
			++qh;
		//	cout << qh << "%" << v << " " << n << endl;
			id[v] = 2;
			if (qh == n)
				qh = 0;
			for (int i = 0; i < g[v].size(); i++)
			{
				rib&r = g[v][i];
				//cout << r.c<<" "<<qh<<" "<<r.f << " " << r.u << " " << r.c << " " << d[v] << " " << d[r.b] << endl;
				if (r.f < r.u&&d[v] + r.c < d[r.b]-eps)
				{
				//	cout << "@" << endl;
					d[r.b] = d[v] + r.c;
					if (id[r.b] == 0)
					{
						q[qt] = r.b;
						++qt;
						if (qt == n)
							qt = 0;
					}
					else if (id[r.b] == 2)
					{
						--qh;
						if (qh < 0)
							qh = n - 1;
						q[qh] = r.b;
					}
					id[r.b] = 1;
					p[r.b] = v;
					p_rib[r.b] = i;
				}
			}
		}

		if (d[t]>1e6)
			break;
		
		int addflow = 1e9;
		for (int v = t; v != s; v = p[v])
		{
			int pv = p[v];
			int pr = p_rib[v];
			addflow = min(addflow, g[pv][pr].u - g[pv][pr].f);
		}
		for (int v = t; v != s; v = p[v])
		{
			int pv = p[v];
			int pr = p_rib[v];
			int r = g[pv][pr].back;
			g[pv][pr].f += addflow;
			g[v][r].f -= addflow;
			cost += g[pv][pr].c*addflow;
		}
		//cout << "@" << addflow << endl;
		flow += addflow;
	}
	if (flow < need)
		cout << -1 << endl; else
	{
		cout.precision(10);
		cout << fixed << cost << endl;
	}

	cin.get(); cin.get();
	return 0;
}