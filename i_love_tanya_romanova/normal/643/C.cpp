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
#define bsize 256

using namespace std;

const int INF = 1e9;
const int N = 200031;

int n, k, ar[N];
vector<int> v;
long double s_inv[N];
long long s[N];
long double dp[55][N];

struct line
{
	long double k;
	long double b;
	int id;
};

vector<line> hull;

long double sum_magic[N];

long double get_inter(line a, line b)
{
	return (b.b - a.b) / (a.k - b.k);
}

int ptr;

void add_line(long double k, long double b, long double id)
{
	line l;
	l.k = k;
	l.b = b;
	l.id = id;
	while (hull.size() > 1 && get_inter(l, hull[hull.size() - 1]) <= get_inter(hull[hull.size() - 2], hull[hull.size() - 1]))
		hull.pop_back();
	hull.push_back(l);
	while (ptr >= hull.size())
		--ptr;
}

long double solve(int n, int k, vector<int> v)
{
	for (int i = 1; i <= v.size(); i++)
	{
		ar[i] = v[i - 1];
		s_inv[i] = s_inv[i - 1] + 1.0 / ar[i];
		s[i] = s[i - 1] + ar[i];
	}
	
	for (int i = 1; i <= n; i++)
	{
		sum_magic[i] = sum_magic[i - 1] + s[i] * 1.0 / ar[i];
	}

	for (int i = 0; i <= n; i++)
	{
		dp[0][i] = 1e18;
	}

	dp[0][0] = 0;

	for (int lev = 1; lev <= k; lev++)
	{
		hull.clear();
		ptr = 0;

		for (int i = 1; i <= n; i++)
		{
			add_line(-s[i - 1], dp[lev - 1][i - 1] + s_inv[i - 1] * s[i - 1]-sum_magic[i-1],i-1);
			while (true)
			{
				if (ptr == hull.size() - 1)
				{
					break;
				}
				long double val = get_inter(hull[ptr], hull[ptr + 1]);
				//cout << "%" << hull.size() << " " << val << " " << s_inv[i] << endl;
				if (val < s_inv[i])
					++ptr;
				else
					break;
			}
			int cut = hull[ptr].id;
			//cout << lev << " " << i << " " << cut << endl;
			dp[lev][i] = dp[lev - 1][cut] + sum_magic[i] - sum_magic[cut];
			dp[lev][i] -= s[cut] * (s_inv[i]-s_inv[cut]);
		}
	}

	return dp[k][n];
}

double solveSlow(vector<int> a, int k) {
	static double ra[210001];
	static long long pref[200011];
	static double rpref[200010];
	static double dp[200101][51];
	int n = (int)a.size();
	for (int i = 0; i < n; ++i) {
		ra[i] = 1.0 / a[i];
		pref[i + 1] = pref[i] + a[i];
		rpref[i + 1] = rpref[i] + ra[i];
	}
	for (int i = 1; i <= k; ++i) {
		dp[0][i] = 1e100;
	}
	for (int i = 1; i <= n; ++i) {
		dp[i][0] = 1e100;
	}
	dp[0][0] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i && j <= k; ++j) {
			dp[i][j] = 1e100;
			double rsum = 0;
			double res = 0;
			for (int t = i - 1; t >= 0; --t) {
				rsum += ra[t];
				res += a[t] * rsum;
				dp[i][j] = min(dp[i][j], dp[t][j - 1] + res);
			}
		}
		for (int j = i + 1; j <= k; ++j) {
			dp[i][j] = 1e100;
		}
	}
	return dp[n][k];
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n >> k;

	//n = 500;
	//k = 5;

	for (int i = 1; i <= n; i++)
	{
		//ar[i] = 1;
		cin >> ar[i];
		//ar[i] = rand() + 1;
		v.push_back(ar[i]);
	}

	cout.precision(8);

	cout << fixed<<solve(n, k, v) << endl;

	//cout << fixed << solveSlow(v,k) << endl;

	cin.get(); cin.get();
	return 0;
}