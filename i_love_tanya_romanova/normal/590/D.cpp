/*
We take no prisoners, there's no retreat
Our only purpose is your defeat
The wheels of death keep turning
Leave your cities burning
There's nothing you can do
To stop them breaking through

Wheels of terror
Crushing all before
Wheels of terror
Battle tanks of war

Blitzkrieg coming, this is the end
High explosive, your will we bend
Smashing your defenses down
Making rubble of your town
Moving on relentlessly
Only death will set you free

Wheels of terror
Crushing all before
Wheels of terror
Battle tanks of war

Target in our sights, armor piercing shell
There's no use running from the raining hell
Wheels of death keep turning
Leave your city burning
There's nothing you can do
To stop us breaking through

Wheels of terror
Crushing all before
Wheels of terror
Battle tanks of war
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
#define bsize 256
#define N 1031

using namespace std;

int n,k,s,ar[1<<20];
int dp[3][200][200*200];

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	
	cin>>n>>k>>s;
/*	n=150;
	k=150;
	s=1000000;
*/	
	for (int i=1;i<=n;i++)
//		ar[i]=rand();
		cin>>ar[i];
	
	if (s>n*n/2+10)
		s=n*n/2+10;
	
	for (int done=0;done<=s;done++)
		for (int pref=0;pref<=k;pref++)
			dp[0][pref][done]=1e9;
	
	dp[0][0][0]=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<=s;j++)
			for (int q=0;q<=k;q++)
				dp[i%2][q][j]=1e9;
			
		for (int pref=0;pref<i&&pref<=k;pref++)
			for (int done=0;done<=s;done++)
			{
				// ignore
				dp[i%2][pref][done]=min(dp[i%2][pref][done],dp[1-i%2][pref][done]);
				// take
				int ndone=done+i-pref-1;
				if (ndone<=s)
					dp[i%2][pref+1][ndone]=min(dp[i%2][pref+1][ndone],dp[1-i%2][pref][done]+ar[i]);
			}
	}
	
//	cout<<dp[0][2][0]<<endl;
	
	int ans=1e9;
	for (int i=0;i<=s;i++)
		ans=min(ans,dp[n%2][k][i]);
	cout<<ans<<endl;
	
	return 0;
}