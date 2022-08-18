/*
I can see the end in sight as we pacify our itching ears
Quickly we are trending light and absolving self of all eternal fears
Until our conscious clears
Hear this voice engage the fight as I pound my chest still knowing my end nears
Still knowing my end nears

The sun is burning out and your rule is left, your rule is left in doubt
We'll sing, and scream, and shout "For You have won, You have won the bout!"

The earth is screaming against its bondage of decay
Creation eager for the coming new day
My lungs are breathing stealing every single breath
Not my soul, but my body is put to death

For if heaven's not your cry, you're still afraid to die
I'll tell you now the end is not far
The sun is burning out and with all creation shout
Enter in the bright Morning Star

I know this is a voyage, it's not my destination
I know this is a voyage, it's not my destination

Not waiting for no dying sun, or watching for a fading moon
No shooting star has caught my eye
Nothing in my hand
Still there is nothing in my hand I bring
Only to the cross
For only to the cross my arms will cling
Only to the cross
Nothing in my hand that I will bring, there is nothing in my hand

For if heaven's not your cry, you're still afraid to die
I'll tell you now the end is not far
The sun is burning out and with all creation shout
Enter in the bright Morning Star

I can see the coming light as the nights will pass and the dawn it clears
Screaming out with all my might for the Morning Star, the Morning Star He nears
I see a new day is coming
I see a new day is near
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

int n, m;
long long mod;
int used[N];
int cnt;
vector<int> g[N];
int comps;

void dfs(int v)
{
	++cnt;
	used[v] = 1;
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if (used[to])
			continue;
		dfs(to);
	}
}

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//	freopen("F:/in.txt", "r", stdin);
	//	freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n >> m >> mod;
	
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	long long ans = 1;

	for (int i = 1; i <= n; i++)
	{
		if (used[i])
			continue;
		cnt = 0;
		dfs(i);
		ans *= cnt;
		ans %= mod;
		++comps;
	}

//	cout << ans << " " << comps << endl;

	for (int i = 1; i+2 <= comps; i++)
	{
		ans = ans*n%mod;
	}
	if (comps == 1)
		ans = 1 % mod;

	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}