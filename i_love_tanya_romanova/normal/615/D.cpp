/*
And in the summer when the clouds show through
I might go the same way too if
You and I could talk together
Well, what I supposed to do with

You and I would walk together
Then with always close around and
Now you gaze towards the doorway
When the weather comes falling down

And when the rain comes down
Would you choose to walk or stay?
Would you choose to walk?
Would you choose to stay?
Would you walk, walk, walk, walk, walk away?

And when the rain comes down
Would you choose to walk or stay?
Would you choose to walk?
Would you choose to stay?
Would you walk, walk, walk, walk, walk away?

Though when the day is nearly through
I might see the same way too
If you would name the things that bring you down on me
So I could see it's not quite true

If you don't really know
Or understand the circumstance
Behind, then I might clear your mind
And you won't have to go so

And when the rain comes down
Would you choose to walk or stay?
Would you choose to walk?
Would you choose to stay?
Would you walk, walk, walk, walk, walk away?
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

#define eps 1e-8
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

const int N = 200050;

using namespace std;

int m;
int p[N];
long long ans;
long long ways, prod;

long long pw(long long a, long long b, long long mod)
{
	if (b == 0)
		return 1 % mod;
	if (b % 2)
		return a*pw(a, b - 1, mod) % mod;
	return pw(a*a%mod, b / 2, mod);
}

vector<pair<int, int> > comp()
{
	vector<pair<int, int> > ret;
	int cnt = 1;
	for (int i = 1; i < m; i++)
	{
		if (p[i] == p[i - 1])
		{
			++cnt;
		}
		else
		{
			ret.push_back(make_pair(p[i - 1], cnt));
			cnt = 1;
		}
	}
	ret.push_back(make_pair(p[m - 1], cnt));
	return ret;
}

long long pref[N], suf[N];

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//	freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	ans = 1;

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> p[i];
	}

	sort(p, p + m);

	vector<pair<int, int> > v = comp();
	
	//cout << v.size() << endl;
	/*
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].first << " " << v[i].second << endl;
	}*/

	pref[0] = 1;

	for (int i = 0; i < v.size(); i++)
	{
		pref[i + 1] = pref[i] * (v[i].second + 1) % (bs - 1);
	}

	suf[v.size() - 1] = 1;

	for (int i = v.size() - 1; i > 0; --i)
	{
		suf[i - 1] = suf[i] * (v[i].second + 1) % (bs - 1);
	}
	long long ans = 1;
	long long times = 0;

	for (int i = 0; i < v.size(); i++)
	{
		times = 1ll * pref[i] * suf[i] % (bs - 1);
		long long cur = 1;
		for (int j = 0; j < v[i].second; j++)
		{
			cur = cur*v[i].first%bs;
			ans = ans*pw(cur, times, bs) % bs;
		}
	}

	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}