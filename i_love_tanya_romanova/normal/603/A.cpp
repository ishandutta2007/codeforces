/*
I was working in the lab, late one night
When my eyes beheld an eerie sight
For my monster from his slab, began to rise
And suddenly to my surprise

He did the mash, he did the monster mash
It was a graveyard smash
He did the mash, it caught on in a flash
He did the mash, he did the monster mash

From my laboratory in the castle east
To the master bedroom, where the vampires feast
The ghouls all came from their humble abodes
To get a jolt from my electrodes

He did the mash, he did the monster mash
It was a graveyard smash
He did the mash, it caught on in a flash
He did the mash, he did the monster mash

The zombies were having fun, the party had just begun
The guests included Wolf Man, Dracula and his son

The scene was rockin', all were digging the sounds
Igor on chains, backed by his baying hounds
The coffin-bangers were about to arrive
With their vocal group, "The Crypt-Kicker Five"

He did the mash, he did the monster mash
The monster mash, it was a graveyard smash
They played the mash, it caught on in a flash
He played the mash, he did the monster mash

Out from his coffin, Drac's voice did ring
Seems he was troubled by just one thing
He opened the lid and shook his fist
And said, "Whatever happened to my Transylvania twist?"

It's now the mash, it's now the monster mash
The monster mash, and it's a graveyard smash
It's the mash, it's caught on in a flash
It's the mash, it is the monster mash

Now everything's cool, Drac's a part of the band
And my monster mash is the hit of the land
For you, the living, this mash was meant too
When you get to my door, tell them Boris sent you

Then you can mash, then you can monster mash
The monster mash, and do a graveyard smash
Then you can mash, you'll catch on in a flash
Then you can mash, then you can monster mash
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

const int N = 100005;

using namespace std;

int n;
string st;
int dp[N][5][5];
int ans;

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin>>n;
	cin>>st;
	
	for (int i=0;i<=n;i++)
	{
		dp[i][0][0]=dp[i][0][1]=dp[i][1][0]=dp[i][1][1]=dp[i][2][0]=dp[i][2][1]=-1e9;
	}
	
	dp[0][0][0]=dp[0][0][1]=0;
	
	for (int i=0;i<st.size();i++)
	{
		int here=st[i]-'0';
		
		for (int j=0;j<=2;j++)
			for (int prev=0;prev<=1;prev++)
			{
				dp[i+1][j][prev]=max(dp[i+1][j][prev],dp[i][j][prev]);
				dp[i+1][j+(prev==here)][here]=max(dp[i+1][j+(prev==here)][here],dp[i][j][prev]+1);
			}
	}
	
	for (int i=0;i<=n;i++)
		for (int j=0;j<=2;j++)
			for (int q=0;q<=1;q++)
				ans=max(ans,dp[i][j][q]);
		
	cout<<ans<<endl;
	
	return 0;
}