/*
Take this love, my dear
And cherish it in your heart
You shall have no fear
Nothing could tear us apart

Accept this love sincere
from the bottom of my heart
For now our time is here
and love shall heal the scars

Now twilight hides the clear
and haunts the day away
We cross the last frontier
and it sets our hearts ablaze

The Waves lie still and gleaming on Our Sea
and we're drifting down the stream

Let's drown ourselves in this love
(my darling, my only one)
Let's give our lives for this love
We are in make it forever

Let me dry your tears
and hold you in embrace
'til we disappear
in the crimson haze

The Flames rise still so freezing on Our Sea
and we're drifting down the stream

Let's drown ourselves in this love
(my darling, my only one)
Let's give our lives for this love
We are in do it together

And we take our dive into the waters of eternity
Here all pain has died and the only ones are you and me

The Haze lies still and bleeding on Our Sea
And we're drifting down the stream

Let's drown ourselves in this love
(my darling, my only one)
Set sacrifices for this love
We are in make it forever

Let's drown ourselves in this love
Let's give our lives for this love
We are in do it together

(my darling, my only one)
(my darling, my only one)
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
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

const int N = 600000;

using namespace std;

int n, m, ar1[N], ar2[N];
long long s1, s2, tp;
pair<long long, long long> ans;
long long best_dif;
vector<int> v1, v2;
int ptr;

bool same_sign(long long a, long long b)
{
	if (a == 0 || b == 0)
		return 1;
	if (a > 0 && b > 0)
		return 1;
	if (a < 0 && b < 0)
		return 1;
	return 0;
}

void check(int a, int b)
{
	long long ns1 = s1 + b - a;
	long long ns2 = s2 + a - b;
	long long here = abs(ns1 - ns2);
	if (here < best_dif)
	{
		best_dif = here;
		tp = 2;
		ans = make_pair(a, b);
	}
	return;
}
int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//	freopen("F:/in.txt", "r", stdin);
	//	freopen("F:/output.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> ar1[i];
	}

	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> ar2[i];
	}

	for (int i = 1; i <= n; i++)
	{
		s1 += ar1[i];
	}
	for (int i = 1; i <= m; i++)
	{
		s2 += ar2[i];
	}

	best_dif = abs(s1 - s2);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			long long ns1 = s1 + ar2[j] - ar1[i];
			long long ns2 = s2 + ar1[i] - ar2[j];
			long long here = abs(ns1 - ns2);
			if (here < best_dif)
			{
				best_dif = here;
				tp = 1;
				ans = make_pair(i, j);
			}
		}
	}

//	cout << best_dif << " " << ans.first<<" "<<ans.second << endl;
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			v1.push_back(ar1[i] + ar1[j]);
		}
	}

	for (int i = 1; i <= m; i++)
	{
		for (int j = i + 1; j <= m; j++)
		{
			v2.push_back(ar2[i] + ar2[j]);
		}
	}

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	/*
	cout << s1 - s2 << endl;

	for (int i = 0; i < v1.size(); i++)
	{
		for (int j = 0; j < v2.size(); j++)
		{
			cout << s1 - v1[i] + v2[j] - (s2 - v2[j] + v1[i]) << " ";
		}
		cout << endl;
	}
	*/
	ptr = 0;
	for (int i = 0; i < v1.size(); i++)
	{
		while (ptr + 1 < v2.size()&& (s1 - v1[i] + v2[ptr + 1]) - (s2 + v1[i] - v2[ptr + 1])<=0)
			++ptr;
		for (int j = ptr - 2; j <= ptr + 2; j++)
		{
			if (j >= 0 && j < v2.size())
			{
				check(v1[i], v2[j]);
			}
		}
	}

	cout << best_dif << endl;
	cout << tp << endl;
	
	if (tp == 0)
	{

	}
	else
	if (tp == 1)
	{
		cout << ans.first << " " << ans.second << endl;
	}
	else
	{
		pair<int, int> p1, p2;

		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				if (ar1[i] + ar1[j] == ans.first)
					p1 = make_pair(i, j);
			}
		}
		for (int i = 1; i <= m; i++)
		{
			for (int j = i + 1; j <= m; j++)
			{
				if (ar2[i] + ar2[j] == ans.second)
					p2 = make_pair(i, j);
			}
		}
		cout << p1.first << " " << p2.first << endl;
		cout << p1.second << " " << p2.second << endl;
	}

	cin.get(); cin.get();
	return 0;
}