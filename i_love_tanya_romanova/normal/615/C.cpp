/*
Sinner, cheater, liar
Made your living till the day you retired
Stealing, taking, using, and abusing
Now for all your sins that you are
accused of
Cruelty, greed, dishonesty, and hate
Forever locked outside the pearly gates
Begging, praying, pleading, and bleeding
Won't extinguish the fire you're feeling!
They say when you die you go to hell
But when you're dead it's too late to
tell you
You're left to rot in your wooden cell
Am I in Heaven, or am I in Hell?
Am I in Heaven, or am I just in Hell?
Chorus
Only death decides for sure
Don't you know only death decides...
Where you go!
Pain, sadness, fear
Is all you've ever given throughout
the years
Thievery, intimidation, and assault
Tools of the trade until death puts a halt
Because you're deceiving, unfeeling,
and misleading
The world is final, there's no use in
appealing
The culmination and sudden realization
It's all real, no hallucination!
They say when you die you go to hell
But when you're dead it's too late to
tell you
You're left to rot on your wooden cell
Am I in Heaven, or am I in Hell?
Am I in Heaven, or am I just in Hell?
Chorus
Only death decides where
you go?
Can't you see what death decides for me?
You'll never know until death decides!
Dealer, pusher, conniver
It's no surprise you fell paralyzed
Felon, loser, and misuser
You're dead broke, a washed-up boozer
Misery, disaster, catastrophy
Exactly how you knew the end would be
Torture, terror, and nightmare
Is what you'll receive when death comes
in three's
They say when you die you go to hell
But when you're dead it's too late to
tell you!
You're left to rot in your wooden cell
Am I Heaven, or am I in Hell?
Am I Heaven, or am I just in Hell?
Chorus
Only death decides for sure
Don't you know only death decides for me?
You'll never know until death
decides...
Where you go!
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

const int N = 2150;

using namespace std;

string st1, st2;
int lcp1[N][N], lcp2[N][N];
int ans[N];
int dp[N];
vector<pair<int, int> > answ;
int par[N];
pair<int, int> memo[N];

int rev(int x)
{
	return st1.size() - x - 1;
}

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//	freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> st1;
	cin >> st2;

	for (int i =st2.size()-1; i >=0; i--)
	{
		for (int j = st1.size() - 1; j >= 0; --j)
		{
			lcp1[i][j] = lcp1[i + 1][j + 1] + 1;
			if (st2[i] != st1[j])
				lcp1[i][j] = 0;
		}
	}

	reverse(st1.begin(), st1.end());
	for (int i = st2.size() - 1; i >= 0; --i)
	{
		for (int j = st1.size() - 1; j >= 0; --j)
		{
			lcp2[i][j] = lcp2[i + 1][j + 1] + 1;
			if (st2[i] != st1[j])
			{
				lcp2[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < st2.size(); i++)
	{
		for (int j = 0; j < st1.size(); j++)
		{
			if (lcp1[i][j]>ans[i])
			{
				ans[i] = lcp1[i][j];
				memo[i] = make_pair(j, j + lcp1[i][j]-1);
			}
		}
	}

	for (int i = 0; i < st2.size(); i++)
	{
		for (int j = 0; j < st1.size(); j++)
		{
			if (lcp2[i][j]>ans[i])
			{
				ans[i] = lcp2[i][j];
				memo[i] = make_pair(rev(j), rev(j + lcp2[i][j] - 1));
			}
		}
	}
	/*
	cout << memo[3].first << " " << memo[3].second << endl;

	cout << memo[0].first << " " << memo[0].second << endl;
	*/
	for (int i = 0; i <= st2.size(); i++)
	{
		dp[i] = 1e9;
	}

	dp[0] = 0;
	for (int i = 0; i < st2.size(); i++)
	{
		int to = i + ans[i];
		if (dp[to] > dp[i] + 1)
		{
			dp[to] = dp[i] + 1;
			par[to] = i;
		}
	}

	if (dp[st2.size()] > 1e8)
	{
		cout << -1 << endl;
		return 0;
	}

	int cur = st2.size();
	while (cur)
	{
		int ps = par[cur];
		answ.push_back(memo[ps]);
		cur = ps;
	}
	reverse(answ.begin(), answ.end());
	cout << answ.size() << endl;
	for (int i = 0; i < answ.size(); i++)
	{
		cout << answ[i].first + 1 << " " << answ[i].second + 1 << endl;
	}

	cin.get(); cin.get();
	return 0;
}