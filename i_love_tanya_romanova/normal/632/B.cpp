/*
That night I never came home
Wandering souls captured my thoughts
Emptiness filled my mind
Urgency spoke her lies

In the confines of these gray walls
I watched them move together
Taking me places I cannot remember, remember
We have been poured out into this loveless bride

How quickly I forget
That this is meaningless?
How quickly I forget
That this is meaningless?

In a world passing
Through my fingers
I still chase the wind

How quickly I forget
That this is meaningless?
How quickly I forget
That this is meaningless?

What have
I learned from yesterday?
What have
I learned from yesterday?
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

const int N = 500010;

using namespace std;

int n;
int val[N];
long long sa[N], sb[N];
string st;
long long ans, here;

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> val[i];
	}
	cin >> st;

	for (int i = 1; i <= n; i++)
	{
		sa[i] = sa[i - 1];
		sb[i]=sb[i - 1];
		if (st[i - 1] == 'A')
			sa[i] += val[i];
		else
			sb[i] += val[i];
	}

	ans = sb[n];

	for (int i = 1; i <= n; i++)
	{
		here = sa[i] + sb[n] - sb[i];
		ans = max(ans, here);
	}

	for (int i = n; i; --i)
	{
		here = sb[i] + sa[n] - sa[i];
		ans = max(ans, here);
	}

	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}