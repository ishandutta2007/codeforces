/*
Crystal horn that sang in the morning
Wake up children of the enemy
They raise the flag on the bloody lords
Who perished much centuries ago
And sun is turning round utter dark
And crying moon's lying on the rack
And dogs of war are stern on the track
They glad to see baneful ages back

Like a flowers in barren place
Appeared as if what the people says
Showing signs of all living craze
We unknew calling all the banes
Yesterday's rivers taking me
To the top of the mysteries
There I see as the life goes by
Reason is so fine for me to die

Steel Says Last!
Steel Says Last!
Steel Says Last!
Steel Says Last!

Take my hand and be my sister
Take my hand and be my sister
I just have to hear your whisper
Wanted west, but I got eastern
Northern one is unexistent
World-ship wrecks but I flow away
Upon the current of the yesterdays
As they're out of forgotten springs
Joined by ocean of tomorrow in
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

#define eps 1e-6
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

using namespace std;

int n,k,x;
long long dp[200006][26];

int ar[1<<20];

int main(){
//freopen("beavers.in","r",stdin);
//freopen("beavers.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>k>>x;


for (int i=1;i<=n;i++)
	cin>>ar[i];

long long ans=0;

for (int iter=1;iter<=100;iter++)
{
	double cur=clock()*1.0/CLOCKS_PER_SEC;
	if (cur>1.75)
		break;
	for (int i=1;i<=n;i++)
		for (int j=0;j<=k;j++)
			dp[i][j]=0;

random_shuffle(ar+1,ar+n+1);
for (int i=1;i<=n;i++)
{
	long long val=ar[i];
	for (int j=0;j<=k;j++)
	{
		for(int q=0;q<=k;q++)
			dp[i][q+j]=max(dp[i][q+j],dp[i-1][q]|val);
		val*=x;
	}
}

for (int i=0;i<=k;i++)
	ans=max(ans,dp[n][i]);
}
cout<<ans<<endl;

//cin.get();cin.get();
return 0;}