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
#define bsize 512

const int N = 15000;

using namespace std;

int n;
long long a[N];
long long A[N][30];

int maxlog[100];
int tests;
string st;
int base;
long long c;
long long prod[N];
vector<int> primes[1000];
vector<long long> moduls;
int flag;
vector<int> cur;
set<pair<vector<int>, pair<int, int> > > did;
map<pair<vector<int>, pair<int, int> >, vector<int> >memo_prod;

void add_modulo(int a, int b, int c, int d, int e, int f)
{
	int id = moduls.size();
	long long Prod = a*b * 1ll * c*d*e*f;

	primes[id].push_back(a);
	primes[id].push_back(b);
	primes[id].push_back(c);
	primes[id].push_back(d);
	primes[id].push_back(e);
	primes[id].push_back(f);
	moduls.push_back(Prod);
}

void add_modulo(int a, int b, int c, int d, int e, int f,int g)
{
	int id = moduls.size();
	long long Prod = a*b * 1ll * c*d*e*f*g;

	primes[id].push_back(a);
	primes[id].push_back(b);
	primes[id].push_back(c);
	primes[id].push_back(d);
	primes[id].push_back(e);
	primes[id].push_back(f);
	primes[id].push_back(g);
	moduls.push_back(Prod);
}

int eval(char c)
{
	if (c == '?')
		return -1;
	if (c >= '0'&&c <= '9')
		return c - '0';
	return c - 'A' + 10;
}

vector<int> norm(string st, int base)
{
	while (st.size() > maxlog[base])
	{
		if (st[0] != '?'&&st[0] != '0')
		{
			flag = 1;
		}
		st.erase(st.begin());
	}
	while (st.size() < maxlog[base])
		st = "?" + st;
	vector<int> res;
	for (int i = 0; i < st.size(); i++)
	{
		res.push_back(eval(st[i]));
	}
	return res;
}

void dfs(int val, int ps)
{
	if (val>=n)
		return;
	if (ps == maxlog[base])
	{
		for (int i = 0; i < moduls.size(); i++)
		{
			prod[i] = prod[i] * (A[val][i]) % moduls[i];
		}
		return;
	}
	if (cur[ps] == -1)
	{
		for (int i = 0; i < base; i++)
		{
			dfs(val*base + i, ps + 1);
		}
	}
	else
		dfs(val*base + cur[ps], ps + 1);
}

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	add_modulo(7, 17, 37, 47, 61, 97);
	add_modulo(11, 13, 41, 43, 67, 89);
	add_modulo(2, 3, 23, 31, 53, 71, 83);
	add_modulo(5, 19, 29, 59, 73, 79);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		for (int j = 0; j < moduls.size(); j++)
		{
			A[i][j] = a[i] % moduls[j];
		}
	}

	for (int i = 2; i <= 16; i++)
	{
		int val = n;
		while (val > 0)
		{
			maxlog[i]++;
			val /= i;
		}
	}

	cin >> tests;
	for (; tests; --tests)
	{
		cin >> base;
		cin >> st;
		cin >> c;
		flag = 0;
		cur = norm(st, base);

		for (int i = 0; i < moduls.size(); i++)
		{
			prod[i] = 1;
		}

		if (did.find(make_pair(cur, make_pair(base, flag))) != did.end())
		{
			for (int i = 0; i < moduls.size(); i++)
				prod[i] = memo_prod[make_pair(cur, make_pair(base,flag))][i];
		}
		else
		{
			if (flag == 0)
				dfs(0, 0);
			did.insert(make_pair(cur, make_pair(base,flag)));
			vector<int> P;
			for (int i = 0; i < moduls.size(); i++)
				P.push_back(prod[i]);
			memo_prod[make_pair(cur, make_pair(base,flag))] = P;
		}

		int best_ans = 200;

		for (int i = 0; i < moduls.size(); i++)
		{
			long long here = prod[i] + c;
			here %= moduls[i];
			for (int j = 0; j < primes[i].size(); j++)
			{
				if (here%primes[i][j] == 0)
					best_ans = min(best_ans, primes[i][j]);
			}
		}

		if (best_ans>100)
			best_ans = -1;

		cout << best_ans << endl;

	}

	cin.get(); cin.get();
	return 0;
}