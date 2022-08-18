/*
My God is better than yours
And the walls of my house are so thick
I hear nothing at all

I followed you out in the storm
But it carried you off
And I burned every picture of yours
Was that not enough?

My gun is bigger than yours
So let's arm the masses
And see what the bastards do then
Walking tall once set us apart
Now we're down on all fours
Do you cry my name in the dark
Like I do yours?

These storms are getting stronger now
Trusses all bend and sway
Lightning hits, the power goes out in the fray
As the waves crash high
And the shoreline disappears
I will scream to the sky
"Hey, people live here."

My dreams are not unlike yours
They long for the safety
And break like a glass chandelier
But there's laughter and oh there is love
Just past the edge of our fears
And there's chaos when push comes to shove
But it's music to my ears

May you be in Heaven before the Devil knows you're dead
May these winds be always at your back

'Cause when we're all just ghosts
And the madness overtakes us
We will look at the ashes
And say, "People lived here."

From the penthouse to the holy martyr
Sea to shining sea
From the coffins full of kindergarteners
Is this what you call free?
From the hate that drips from all your crosses
Are your hands so clean?

There's a wildfire and it's spreading far
From sea to shining sea

When we're all just ghosts
And the madness overtakes us
I will scream to the sky, yeah I'll scream to the sky
Yeah I'll scream to the sky
"Hey, people live here."
*/

#pragma GCC optimize("O3")
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
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd

#define eps 1e-11
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 5031;

int n;
string st;
vector<char> blocks;
int le[N];
int same[N];

int dp[N][N],S[N][N];

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	cin>>st;
	for (int i=0;i<st.size();i++)
	{
		if (i==0||st[i]!=st[i-1])
			blocks.push_back(st[i]);
	}

	for (int i='a';i<='z';i++)
	{
		le[i]=-1;
	}

	for (int i=0;i<blocks.size();i++)
	{
		int here=blocks[i];
		same[i]=le[here];
		le[here]=i;
	}

	for (int i=1;i<=n;i++)
	{
		for (int cur_block=0;cur_block<blocks.size();cur_block++)
		{
			if (i==1)
			{
				if (same[cur_block]==-1)
					dp[i][cur_block]=1;
				continue;
			}
			int cl=same[cur_block]+1;
			dp[i][cur_block]=S[i-1][cur_block];
			if (cl>0)
				dp[i][cur_block]-=S[i-1][cl-1];
			if (dp[i][cur_block]<0)
				dp[i][cur_block]+=bs;
		}

		for (int cur_block=0;cur_block<blocks.size();cur_block++)
		{
			S[i][cur_block]=dp[i][cur_block];
			if (cur_block)
				S[i][cur_block]+=S[i][cur_block-1];
			if (S[i][cur_block]>=bs)
				S[i][cur_block]-=bs;
		}
	}

	long long ans=0;
	for (int i=0;i<blocks.size();i++)
	{
		ans=ans+dp[n][i];
		ans%=bs;
	}
	cout<<ans<<endl;

	cin.get(); cin.get();
	return 0;
}