/*
What was it like to see,
The face of your own stability,
Suddenly look away,
Leaving you with the dead and hopeless?

Eleven and she was gone.
Eleven is when we waved good-bye.
Eleven is standing still,
Waiting for me to free him,
By coming home.

Moving me with a sound.
Opening me within a gesture.
Drawing me down and in,
Showing me where it all began,
Eleven.

You're too scar'd to realize this,
You are the voice that's been calling me back home.

Under a dead Ohio sky,
Eleven has been and will be waiting,
Defending his light and wondering,
Where the hell have I been?
Sleeping lost and numb I.
So glad that I have found you.
I am but wide awake and heading,
Home.

I wish that I could see you,
Turn and run to play.
Dreams are fading,
Carry my ancient soul.

Carry me into the light.
Aim your body heavenly,
Enduring a memory.
Ill come to your light,
Hold your light.
Hold your light where I can see it,

Hold it,
High.

Hold your light,
Eleven, Lead me through each gentle step,
By step,
By inch by loaded memory,
I'll move,
To heal,
As soon as pain allows so we can,
Reunite,
And both move on together.

Hold,
Your light,
Eleven lead me through each gentle step,
By step,
By inch by loaded memory 'till,
One,
And one are one,
Eleven.
So glow,
Child,
Glow.
I'm heading back home...
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
#define bs 1000000007
#define bsize 512

const int N = 110000;

using namespace std;

int n, a, b, dp[N];
string st;
vector<int> ans;
int ptr;

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n >> a >> b;
	dp[0] = 1;
	for (int i = 0; i <= n; i++)
	{
		if (dp[i] == 0)
			continue;
		dp[i + a] = 1;
		dp[i + b] = 1;
	}

	if (dp[n] == 0)
	{
		cout << -1 << endl;
		return 0;
	}

	while (n > 0)
	{
		if (n >= a&&dp[n - a] == 1)
		{
			ans.push_back(a);
			n -= a;
		}
		if (n >= b&&dp[n - b] == 1)
		{
			ans.push_back(b);
			n -= b;
		}
	}
	string st;
	cout << ans.size() << endl;

	cin >> st;
	for (int i = 0; i < ans.size(); i++)
	{
		for (int j = 0; j < ans[i]; j++)
		{
			cout << st[ptr];
			++ptr;
		}
		cout << endl;
	}
	cin.get(); cin.get();
	return 0;
}