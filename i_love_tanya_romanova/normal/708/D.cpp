/*
Step inside this world of hate

Search lights cut through the darkest of air
Eagles fly where the brave only dare
Pray for death let the chaos begin
Thou shalt kill is the mandatory sin

You wanna start a fucking war
You wanna feed upon the energy
You wanna take the shortest straw
You wanna take it to the death

Viva la hate
A circle of brutality
Hatred dictates
Gonna pull you under
Viva la hate
The ultimate insanity
Violence awaits
You can burn with me in hell

Hate sent fuel powers deep through my veins
Troops of doom run theaters of pain
White red black hail the backdrop of fear
Anger burns ritual violence crawling near

Annihilation crushing all
Extermination of the enemy
Destructive loss of self control
You wanna take it to the death

Viva la hate
A circle of brutality
Hatred dictates
Gonna take you under
Viva la hate
The ultimate insanity
Violence awaits
You can burn with me in hell

They speak with twisted minds
Of concepts so despised
Their fear is where we shine
You are the hate
We are the hate
Viva la hate

Blood stained walls in the hatebox domain
War dogs prey on the weak and insane
Human storm laying waste in the pits
Special force bare the number of 666

You wanna start a fucking war
You wanna feed upon the energy
You wanna take the shortest straw
You wanna take it to the death

Viva la hate
A circle of brutality
Hatred dictates
Gonna take you under
Viva la hate
The ultimate insanity
Violence awaits
You can burn with me in hell
Viva la hate
Viva la hate
Viva la hate
You can burn with me in hell
Viva la hate
Viva la hate
Viva la hate
You can burn with me in hell
Viva la hate
Viva la hate
Viva la hate
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

#define eps 1e-7
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 350

using namespace std;

const int INF = 1e9;
const int N = 100031;

int n, m, res;
int bal[N];

struct rib
{
	int b, u, c, f;
	int back;
};

vector<rib> g[N];
int s, t;

void add_edge(int a, int b, int u, int c)
{
	rib r1 = { b, u, c, 0, g[b].size() };
	rib r2 = { a, 0, -c, 0, g[a].size() };
	g[a].push_back(r1);
	g[b].push_back(r2);
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/input.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int a, b, c, f;
		cin >> a >> b >> c >> f;
		bal[a] += f;
		bal[b] -= f;

		if (c > f)
		{
			add_edge(a, b, c - f, 1);
			add_edge(a, b, 1000000000, 2);
			add_edge(b, a, f, 1);
		}
		else
		{
			res += f - c;
			add_edge(b, a, f - c, 0);
			add_edge(a, b, 1000000000, 2);
			add_edge(b, a, c, 1);
		}
	}

	add_edge(n, 1, 1000000000, 0);

	for (int i = 1; i <= n; i++)
	{
		if (bal[i] < 0)
			add_edge(0, i, -bal[i], 0);
		else
			add_edge(i, n + 1, bal[i], 0);
	}

	s = 0;
	t = n + 1;
	n = t + 1;
	int flow = 0;
	int cost = 0;
	while (true)
	{
		vector<int> id(n, 0);
		vector<int> d(n, 1000000000);
		vector<int> q(n);
		vector<int> p(n);
		vector<int> p_rib(n);
		int qh, qt;
		qh = qt = 0;
		q[qt] = s;
		qt++;
		d[s] = 0;
		while (qh != qt)
		{
			int v = q[qh];
			++qh;
			if (qh == n)
				qh = 0;
			id[v] = 2;
			for (int i = 0; i < g[v].size(); i++)
			{
				rib&r = g[v][i];
				if (r.f < r.u&&d[v] + r.c < d[r.b])
				{
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

		if (d[t] > 1e5)
			break;
		int addflow = 1e6;
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
		flow += addflow;
	}

	cout << res + cost << endl;

	cin.get(); cin.get();
	return 0;
}