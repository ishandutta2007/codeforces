
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
const int N = 100031;

int a00, a01, a10, a11;

bool invalid(long long x)
{
	for (int i = 0; i <= 100000; i++)
	{
		if (1ll * i*(i - 1) / 2 == x)
			return false;
	}
	return true;
}

vector<long long> get_cnt(long long x)
{
	vector<long long> res;
	for (int i = 0; i <= 100000; i++)
	{
		if (1ll * i*(i - 1) / 2 == x)
			res.push_back(i);
	}
	return res;
}

string solve()
{
	if (invalid(a00) || invalid(a11) || invalid(0ll+a00 + a01 + a10 + a11))
	{
		return "Impossible";
	}
	vector<long long> cnt0, cnt1;
	cnt0 = get_cnt(a00);
	cnt1 = get_cnt(a11);
	vector<long long> ttl = get_cnt(0ll+a00 + a01 + a10 + a11);
	for (int i = 0; i < cnt0.size(); i++)
	{
		for (int j = 0; j < cnt1.size(); j++)
		{
			for (int q = 0; q < ttl.size(); q++)
			{
				long long a = cnt0[i];
				long long b = cnt1[j];
				long long c = ttl[q];
				//cout << a << "%" << b << " " << c << endl;
				if (a + b != c)
					continue;
				if (c == 0)
					continue;

				string res = "";
				if (a == 0 && a10 > 0)
					continue;
				int F = 0;
				if (a10>0)
					F = a10 / a;
				for (int p = 0; p < F; p++)
				{
					res += "1";
				}
				b -= F;

				int rem = 0;
				if (a>0 && a10%a > 0)
					rem = a10%a;
				for (int i = a; i > 0; --i)
				{
					if (i == rem)
					{
						res += "1";
						--b;
					}
					res += "0";
				}
				while (b)
				{
					res += "1";
					--b;
				}
				return res;
			}
		}
	}
	//	cout << "!" << endl;
	return "Impossible";
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> a00 >> a01 >> a10 >> a11;

	string res = solve();

	cout << res << endl;

	cin.get(); cin.get();
	return 0;
}