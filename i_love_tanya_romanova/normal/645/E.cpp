/*
Like wild fire
Comes roaring
Mad whirlwind
Burning the road
Black thunder
White lightning
Speed demons cry

The Hell patrol
The Hell patrol

Night riders
Death dealers
Storm bringers
Tear up the ground
Fist flying
Eyes blazing
They're glory bound

The Hell patrol
The Hell patrol

Brutalize you
Neutralize you
Gonna go for your throat as you choke
Then they'll vaporapeize you
Terrorize you
Pulverize you
Gonna cut to the bone as you groan
And they'll paratamize you

Chrome masters
Steel warriors
Soul stealers
Ripping out hearts
They're devil dogs

The Hell patrol
The Hell patrol
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

const int N = 2300000;

using namespace std;

string st;
int n, k;
int last[N];
int m;
int sum[N], dp[N];

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n >> k;
	cin >> st;
	for (int i = 0; i < k; i++)
	{
		last[i] = -1;
	}

	for (int i = 0; i < st.size(); i++)
	{
		last[st[i] - 'a'] = i;
	}

	m = st.size();
	for (int i = m; i < m+n; i++)
	{
		int bp = -1;
		int bst = 1e9;
		for (int j = 0; j < k; j++)
		{
			if (last[j] < bst)
				bst = last[j],
				bp = j;
		}
		st += char(bp + 'a');
		last[bp] = i;
	}

	dp[0] = 1;
	for (int i = 0; i <= k; i++)
	{
		last[i] = 0;
	}

	sum[0] = 1;

	for (int i = 1; i <= st.size(); i++)
	{
		int here = st[i-1] - 'a';
		int P;
		if (last[here] != 0)
			P = sum[last[here] - 1];
		else
			P = 0;
		dp[i] = (sum[i - 1] - P+ bs) % bs;
		sum[i] = (sum[i - 1] + dp[i]) % bs;
		last[here] = i;
//		cout << dp[i] << " "<<suendl;
	}

	cout << sum[st.size()] << endl;

	cin.get(); cin.get();
	return 0;
}