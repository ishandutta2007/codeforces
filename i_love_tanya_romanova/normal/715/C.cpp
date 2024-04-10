/*
The romance lives on inside
Here I am again
Put this ring around your finger
Can you trust me?
I've hurt so many
I am real this time
I've said I love you
Will you trust me?
Deceived and broken
So many hearts
I'm scared of falling
Failing you, my dear
I know I'm weak
I know I'm broken
Your beauty is in my heart
Your beauty keeps me walking on
I will hold you forever my love
This promise is real
Deceived and broken
So many hearts
It's in the past now
This love is real
I've said it before, but this time it's real
Forget the past, it's gone
Believe me when I say that you're the one
That you're the one now
Forget the past, it's gone
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
#define bs 1234567891
#define bsize 350

using namespace std;

const int INF = 1e9;
const int N = 200000;

const int TTL = 1;

int n, m;
vector<pair<int,int> > g[N];
vector<int> vec[N];
vector<long long> tneed;
vector<long long> LABEL[N];
int ans1, ans2;
bool found;

int RAND()
{
	int res = 0;
	for (int i = 0; i <= 50; i++)
	{
		res = res * 2 + rand() % 2;
		res %= bs;
	}
	return res;
}

map<long long, int> mapa;

vector<int> UPS;
vector<pair<int,int> >DWNS;

int PHI;
int banned[N];

int used[N];
int dead[N];

long long ans;

long long pw10[N];
long long inv10[N];

long long pw(long long a, long long b)
{
	if (b == 0)
		return 1 % m;
	if (b % 2)
		return a*pw(a, b - 1) % m;
	return pw(a*a%m, b / 2);
}

void trace(int v,long long u,long long d,long long dep)
{
	used[v] = 1;
	DWNS.push_back(make_pair(d%m,dep));
	UPS.push_back(u%m);
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i].first;
		if (used[to])
			continue;
		if (dead[to])
			continue;
		trace(to, (u+1ll*pw10[dep]*g[v][i].second)%m,(1ll*d*10+g[v][i].second)%m,dep+1);
	}
}

int subsize[N];
int par[N];
vector<vector<int> > all_ups;
vector<vector<pair<int, int> > > all_dwns;

map<int, int> mapa2;

long long inv(long long x)
{
	return pw(x, PHI - 1);
}

int trace_sizes(int v)
{
	subsize[v] = 1;
	used[v] = 1;
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i].first;
		if (dead[to] || used[to])
			continue;
		par[to] = v;
		int here = trace_sizes(to);
		subsize[v] += here;
	}
	return subsize[v];
}

void clear_used(int v)
{
	used[v] = 0;
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i].first;
		if (dead[to] == 1 || used[to] == 0)
			continue;
		clear_used(to);
	}
}

void solve_tree(int v)
{
	par[v] = -1;

	int SZ = trace_sizes(v);

	while (true)
	{
		int new_son;
		int F = 0;
		for (int j = 0; j < g[v].size(); j++)
		{
			int to = g[v][j].first;
			if (dead[to] == 1 || par[to] != v)
				continue;
			if (subsize[to] * 2 > SZ)
				F = 1,
				new_son = to;
		}
		if (F)
			v = new_son;
		else
			break;
	}

	clear_used(v);

	mapa.clear();
	mapa2.clear();

	dead[v] = 1;

	all_ups.clear();
	all_dwns.clear();

	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i].first;
		if (dead[to])
			continue;
		UPS.clear();
		DWNS.clear();

		trace(to, g[v][i].second,g[v][i].second,1);

		all_ups.push_back(UPS);
		all_dwns.push_back(DWNS);

		for (int j = 0; j < UPS.size(); j++)
		{
			//cout << UPS[j] << "%" << endl;
			mapa[UPS[j]]++;
		}
	}

	for (int it = 0; it < all_ups.size(); it++)
	{
		DWNS = all_dwns[it];
		UPS = all_ups[it];
		mapa2.clear();
		
		for (int i = 0; i < UPS.size(); i++)
		{
			mapa2[UPS[i]]++;
		}

		// check for ans
		for (int j = 0; j < DWNS.size(); j++)
		{
			int val = DWNS[j].first;
			int len = DWNS[j].second;
			int need = (m - val) % m;
			need = need * 1ll * inv10[len] % m;
			ans += mapa[need] - mapa2[need];
			if (DWNS[j].first == 0) // from root
				++ans;
		}
	}

	//cout << "$$" << mapa[0] << endl;

	ans += mapa[0];// to root
//	cout << "!" << endl;

	clear_used(v);
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i].first;
		if (dead[to])
			continue;
		solve_tree(to);
	}
}

int get_phi(int x)
{
	int res = x;
	for (int i = 2; i*i <= x; i++)
	{
		if (x%i)
			continue;
		res = res / i*(i - 1);
		while (x%i == 0)
			x /= i;
	}
	if (x > 1)
		res = res / x*(x - 1);
	return res;
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	//cout << get_phi(10) << endl;

	scanf("%d", &n);
	scanf("%d", &m);

	PHI = get_phi(m);

	pw10[0] = 1;
	for (int i = 1; i < N; i++)
	{
		pw10[i] = 1ll * pw10[i - 1] * 10 % m;
	}
	for (int i = 0; i < N; i++)
	{
		inv10[i] = inv(pw10[i]);
	}

	for (int i = 1; i < n; i++)
	{
		int a, b;
		int val;
		scanf("%d", &a);
		scanf("%d", &b);
//		a = i;
//		b = rand() % i;
		scanf("%d", &val);
		g[a].push_back(make_pair(b,val));
		g[b].push_back(make_pair(a,val));
	}

	int root = rand() % n;

	solve_tree(root);

	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}