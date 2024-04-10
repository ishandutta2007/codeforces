/*
My story starts the day they said, "She can't be found"
The news so dark, heart stopped, I stood silent without a sound
It's over, she's finished, mother lies with my father and sister too
Cold-blooded, they suffered, shot down by the outlaws after you
Sorrow swallows my screams

Strength of the world is on my shoulders
Strength of the world is on my side
Strength of the world the one true beholder
Ice in my veins for those who've died
I've seen my family fade away, you've taken my whole life
There's nothing left to say

Avenged the dead killed all who cross me in my path
Suicidal, I never planned on coming back
I want it, I need it, revenge is dripping from my teeth
Need nothin', to feel power, and bring the killers to their knees

Nothin' ta lose vengeance ta gain
(You know I'll never be the same)
So taste my breath I'm close behind you
(So desperate on your final day)
Sorrow swallows my screams

Strength of the world is on my shoulders
Strength of the world is on my side
Strength of the world the one true beholder
Ice in my veins for those who've died
I've seen my family fade away, you've taken my whole life
There's nothing left to say

Sitting in silence with heaven above me
I prayed every night by their graves
While I search for closure I feel it no longer
I can't turn my cheek away

I stand before you, I'll sin when I have to
But now I leave your side to avenge my family's pride
I've seen my family fade away, you've taken my whole life
There's nothing left to say

Strength of the world is on my shoulders
Strength of the world is on my side
Strength of the world the one true beholder
Ice in my veins for those who've died

So far forever now alone
A greater punishment on me has been imposed
A killer falling from the light
I'll miss my family, I'll never be alright
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

using namespace std;

int n,m,k,cost[1<<15];
int bonus[200][200];
long long dp[1<<19][19];
long long ans;

int count_bits(int x)
{
	if (x==0)
		return 0;
	return count_bits(x/2)+x%2;
}
int main(){
//freopen("beavers.in","r",stdin);
//freopen("beavers.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m>>k;
for (int i=0;i<n;i++)
	cin>>cost[i];

for (int i=0;i<k;i++)
{
	int a,b,c;
	cin>>a>>b>>c;
	--a;
	--b;
	bonus[a][b]=c;
}

for (int i=0;i<(1<<n);i++)
	for (int last=0;last<n;last++)
		dp[i][last]=-1e16;
		
for (int i=0;i<n;i++)
	dp[1<<i][i]=cost[i];

for (int mask=0;mask<(1<<n);mask++)	
	for (int last=0;last<n;last++)
	{
		if (dp[mask][last]<0)
			continue;
		for (int ad=0;ad<n;ad++)
		{
			if (mask&(1<<ad))
				continue;
			long long tcost=cost[ad]+bonus[last][ad]+dp[mask][last];
			if (dp[mask|(1<<ad)][ad]<tcost)
				dp[mask|(1<<ad)][ad]=tcost;
		}
		int Q=count_bits(mask);
		if (Q==m)
			ans=max(ans,dp[mask][last]);
	}

cout<<ans<<endl;

//cin.get();cin.get();
return 0;}