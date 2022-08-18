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

#define eps 1e-7
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 350

using namespace std;

const int INF = 1e9;
const int N = 100031;

long long n, m, s, t, l;
long long a[N], b[N], w[N];
long long flag[N];
vector<int> g[N];

void run_locker(int val)
{
	for (int i = 0; i < m; i++)
	{
		if (flag[i])
			w[i] = val;
	}
}

int used[N];
long long dist[N];
int par[N];

int get_other(int edge_id, int v_id)
{
	if (a[edge_id] == v_id)
		return b[edge_id];
	return a[edge_id];
}

long long get_solution()
{
	for (int i = 1; i <= n; i++)
	{
		used[i] = 0;
		dist[i] = 1e18;
	}
	dist[s] = 0;
	set<pair<long long, long long> > S;
	set<pair<long long, long long> > ::iterator it;
	for (int i = 1; i <= n; i++)
	{
		S.insert(make_pair(dist[i], i));
	}
	while (S.size())
	{
		it = S.begin();
		pair<long long, long long>p = *it;
		S.erase(it);
		int qv = p.second;
		for (int i = 0; i < g[qv].size(); i++)
		{
			int id = g[qv][i];
			int to = get_other(id, qv);
			long long qd = dist[qv] + w[id];
			if (dist[to]>qd)
			{
				S.erase(make_pair(dist[to], to));
				dist[to] = qd;
				par[to] = id;
				S.insert(make_pair(dist[to], to));
			}
		}
	}
	return dist[t];
}

vector<int> get_path()
{
	vector<int> res;
	int cur = t;
	while (cur != s)
	{
		res.push_back(par[cur]);
		cur = get_other(par[cur], cur);
	}
	return res;
}

vector<int> purify(vector<int> v)
{
	vector<int> res;
	for (int i = 0; i < v.size(); i++)
	{
		int id = v[i];
		if (flag[id])
			res.push_back(id);
	}
	return res;
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/input.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n >> m >> l >> s >> t;

	++s;
	++t;
	for (int i = 0; i < m; i++)
	{
		cin >> a[i] >> b[i] >> w[i];
		++a[i];
		++b[i];
		g[a[i]].push_back(i);
		g[b[i]].push_back(i);
		if (w[i] == 0)
			flag[i] = 1;
	}

	run_locker((int)1e9 + 1e6);

	long long Q = get_solution();

	if (Q<l)
	{
		cout << "NO" << endl;
		return 0;
	}

	run_locker(1);

	Q = get_solution();
	if (Q>l)
	{
		cout << "NO" << endl;
		return 0;
	}

	vector<int> V;
	for (int i = 0; i < m; i++)
	{
		if (flag[i])
			V.push_back(i);
	}

	//	run_locker((int)1e9 + 1e6);
	while (true)
	{
		long long Q = get_solution();
		//cout << Q << endl;
		//vector<int> V = get_path();
		if (Q == l)
			break;
		long long L, R;
		L = 0;
		R = 1e15;

//		V = purify(V);

		while (L < R)
		{
			long long mid = L + R + 1;
			mid /= 2;
			int C = V.size();

			//cout << V.size() << "%" << endl;
			for (int i = 0; i<V.size(); i++)
			{
				int id = V[i];
				w[id] += mid / C;
				if (i<mid%C)
					w[id]++;
			}

			long long QQ = get_solution();
			if (QQ>l)
			{
				R = mid - 1;
			}
			else
			{
				L = mid;
			}

			for (int i = 0; i < V.size(); i++)
			{
				int id = V[i];
				w[id] -= mid / C;
				if (i < mid%C)
					w[id]--;
			}
		}
		for (int i = 0; i < V.size(); i++)
		{
			int id = V[i];
			w[id] += L / V.size();
			if (i < L%V.size())
				w[id]++;
		}
		//	cout << L << " " << get_solution() << endl;
		//	cin.get();
	}

	cout << "YES" << endl;
	for (int i = 0; i < m; i++)
	{
		--a[i];
		--b[i];
		cout << a[i] << " " << b[i] << " " << w[i] << endl;
	}

	cin.get(); cin.get();
	return 0;
}