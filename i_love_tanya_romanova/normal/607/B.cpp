/*
One time love, take care how you use it
Try to make it last all night, And if you take your pick
Be careful how you choose it, Sometimes its hard to feel it bite
Feel it bite.

A man I know, went down to Louisiana,
had himself a bad, bad fight
And when the sun peeked through
John Cameron with Suzanna,
He kissed the whiskers, left & right
Whiskers!

Now, now, now, fright subsides
Out at a hotel in the quarter, our friends check in to pass the night
Now love gets hot, but fire preceded water
Poor whiskers set the room alight.
Whiskers!

Down on Bourbon street, You know it's right
You can see my friend, they run around all through the night
Most everywhere, Until the closet's bare
Run for the razor, Doin' up my hair

New Orleans queens, Sure know how to schmooze it
Maybe for some that seems alright
When I step out, strut down with my sugar
She'd best not talk like Barry White!

One time love, take care how you use it
Try to make it last all night, And if you take your pick
Be careful how you choose it, Sometimes its hard to feel it bite
Feel it bite.
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
#include <ctime> 
#include <assert.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-8
#define M_PI 3.141592653589793
//#define bs 1234567891
#define bsize 512

const int N = 600;

using namespace std;

int n, ar[N], dp[N][N][3];

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> ar[i];

	for (int r = 1; r <= n; r++)
	{
		for (int l = r; l >= 1; --l)
		{
			dp[l][r][0]=dp[l][r][1] = 1e9;
			if (l == r)
			{
				dp[l][r][0] = 1;
				dp[l][r][1] = 0;
				continue;
			}
			for (int cp = l; cp < r; cp++)
			{
				dp[l][r][0] = min(dp[l][r][0], dp[l][cp][0] + dp[cp + 1][r][0]);
				dp[l][r][1] = min(dp[l][r][1], dp[l][cp][1] + dp[cp + 1][r][0]);
			}
			for (int cp = l + 1; cp <= r;cp++)
			{
				dp[l][r][1] = min(dp[l][r][1], dp[cp][r][1] + dp[l][cp - 1][0]);
			}

			for (int match = l + 1; match <= r; match++)
			{
				if (ar[l] == ar[match])
					dp[l][r][0] = min(dp[l][r][0], dp[l + 1][match - 1][1] + dp[match + 1][r][0] + 1),
					dp[l][r][1] = min(dp[l][r][1], dp[l + 1][match - 1][1] + dp[match + 1][r][0]);
			}
			for (int match = l; match < r; match++)
			{
				if (ar[match] == ar[r])
				{
					dp[l][r][0] = min(dp[l][r][0], dp[l][match - 1][0] + dp[match + 1][r - 1][1] + 1);
					dp[l][r][1] = min(dp[l][r][1], dp[l][match - 1][0] + dp[match + 1][r - 1][1]);
				}
			}
		}
	}

	cout << dp[1][n][0] << endl;

	cin.get(); cin.get();
	return 0;
}