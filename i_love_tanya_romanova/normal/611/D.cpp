/*
First time I went to California
I couldn't believe my eyes
Skirts were so short
Nights so long
I thought that I would probably die
Fresh our of Luckenbach Texas
I didn't expect that pair
Both of them had one thing on their mind
Both of them were willing to share

I never had two women before
I'm an open minded person
So baby, lock that door
We're lovin' in stereo
Lets go
Love in stereo
It's love in stereo
Ooh, how can anything feel so good

Lovin' from the bottom, lovin' from the top
Lovin' to the left and the right, now
Well, I'm a lover not a fighter
But it looks like I'm gonna have to fight
To keep from losin' my mind, mind, mind

I never had two women before
I'm an open minded person
So baby, lock that door
We're lovin' in stereo
Lets go
Love in stereo
It's love in stereo
Ooh, how can anything feel so good

Well, first time I went to California
I couldn't believe my eyes
Skirts were so short
Nights so long
Girls comin' two at a time

We're lovin' in stereo
Lets go
Love in stereo
It's love in stereo
Lets go

We're lovin' in stereo
Lets go
It's love in stereo
Ooh, how can anything feel so good
*/

//#pragma comment(linker, "/STACK:16777216")
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

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

const int N = 5050;

using namespace std;

void add(int&a, int &b)
{
	a += b;
	if (a >= bs)
		a -= bs;
}

string st;
int n;
int lcp[N][N];
int dp[N][N];
int sum[N][N];

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("C:/input.txt","r",stdin);
	//freopen("C:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;
	cin >> st;

	for (int i = n - 1; i >= 0; --i)
	{
		for (int j = n - 1; j >= 0; --j)
		{
			lcp[i][j] = lcp[i + 1][j + 1]+1;
			if (st[i] != st[j])
				lcp[i][j] = 0;
		}
	}
	/*
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << lcp[i][j] << " ";
		cout << endl;
	}*/

	for (int j = 0; j < st.size(); j++)
	{
		for (int i = 0; i <= j; i++)
		{
			if (st[i] == '0')
				continue;
			if (i == 0)
			{
				dp[i][j] = 1;
				continue;
			}
			// shorter
			int sho = i - (j - i);
			if (sho < 0)
				sho = 0;
			int ways = sum[i-1][i-1];
			if (sho>0)
				ways -= sum[i-1][sho - 1];
			if (ways < 0)
				ways += bs;
			add(dp[i][j], ways);
			int mir = i - (j - i) - 1;
			if (mir < 0)
				continue;
			int p = lcp[mir][i];
			if (p + i == st.size())//equal
				continue;
			if (p >= (j - i + 1))
				continue;
			if (st[p + i]>st[mir + p])// bigger
			{
				add(dp[i][j], dp[mir][i - 1]);
			}
		}
		sum[j][0] = dp[0][j];
		for (int q = 1; q < n; q++)
		{
			sum[j][q] = sum[j][q - 1] + dp[q][j];
			sum[j][q] %= bs;
		}
	}

	int ans = 0;

	for (int i = 0; i <= n; i++)
		add(ans, dp[i][n - 1]);
	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}