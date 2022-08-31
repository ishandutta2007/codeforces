/*
You say you know just who I am
But you can't imagine
What waits for you across the line
You thought you had me

But I'm still here standing
And I'm tired of backing down

And I'm here now feeling the pain
Of a thousand hearts
Been to hell and back again
I won't take this

You try so hard to bring me down
You can't break the broken
You still don't seem to understand
It's your turn to see just

How it feels to be me
How it feels to be knocked down

And you're here now feeling the pain
Of a thousand hearts
You've been to hell and back again
You can't take this

Remember
This feeling

How it feels to be alive
Now you see me through my eyes

And we're here now feeling the beat
Of a thousand hearts
Coming back to life again
We can make it

Remember
This feeling
Remember
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
const int N = 105000;

int n, p;
int c[N], h[N], t[N];

int tests;
vector<int> events[N];
int dp[10000];
int memo_dp_pref[4005][4005],
memo_dp_suf[4005][4005];

vector<pair<int, int> > all_events;

void update_dp(int id)
{
	for (int i = 4000; i >= 0; --i)
	{
		dp[i + c[id]] = max(dp[i + c[id]], dp[i] + h[id]);
	}
}


int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n >> p;
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i] >> h[i] >> t[i];
		events[t[i]].push_back(i);
		all_events.push_back(make_pair(t[i], i));
	}

	for (int i = 0; i <= 20000; i++)
	{
		sort(events[i].begin(), events[i].end());
	}

	sort(all_events.begin(), all_events.end());

	for (int cut = 0; cut <= 20000; cut += p)
	{
		for (int i = 0; i <= 4000; i++)
		{
			dp[i] = 0;
		}
		for (int j = cut - 1; j >= cut - p&&j>=0; --j)
		{
			if (events[j].size())
			for (int q = events[j].size()-1; q>=0; q--)
			{
				int id = events[j][q];
				update_dp(id);
				for (int p = 0; p <= 4000; p++)
				{
					memo_dp_suf[id][p] = dp[p];
				}
			}
		}
		
		for (int i = 0; i <= 4000; i++)
		{
			dp[i] = 0;
		}

		for (int j = cut; j <= cut + p; j++)
		{
			for (int q = 0; q < events[j].size(); q++)
			{
				int id = events[j][q];
				update_dp(id);
				for (int p = 0; p <= 4000; p++)
				{
					memo_dp_pref[id][p] = dp[p];
				}
			}
		}
	}

	cin >> tests;
	for (; tests; --tests)
	{
		int a, money;
		cin >> a >> money;
		int L, R;
		R = a;
		L = a - p + 1;
		int C;

		if (L<0)
			C = -1;
		else
			C = L / p;
		int start = lower_bound(all_events.begin(), all_events.end(), make_pair(L, -1)) - all_events.begin();
		if (start == all_events.size() || all_events[start].first > a)
		{
			cout << 0 << endl;
			continue;
		}
		int nd = lower_bound(all_events.begin(), all_events.end(), make_pair(R+1, -1)) - all_events.begin() - 1;
		int id1 = all_events[start].second;	
		int id2 = all_events[nd].second;

		int flag1 = 0;
		int flag2 = 0;

		//cout << id1 << "%" << id2 << endl;

		if (t[id1] / p != C||L%p==0)
			flag1 = 1;
		if (t[id2] / p != R / p)
			flag2 = 1;
		int res = 0;
//		cout << flag1 << "%" << flag2 << endl;
		for (int i = 0; i <= money; i++)
		{
			int here = 0;
			if (flag1 == 0)
				here += memo_dp_suf[id1][i];
			if (flag2 == 0)
				here += memo_dp_pref[id2][money-i];
			res = max(res, here);
		}
		cout << res << endl;
	}

	cin.get(); cin.get();
	return 0;
}