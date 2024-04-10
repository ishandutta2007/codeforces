/*
There is something that has changed
Corrupted in your ways
Recite your contradictions
This world's perception has been grazed, distracted and dismayed
But you have all the answers for me

It's clear to me now you're not what you claim
You don't speak, you don't speak for me
There is no mistake, it's written on your face
You don't bleed, you don't bleed for me
Bleed for me

When the scales fall from our eyes, we see proof behind the lies
I don't believe a word you say

It's clear to me now you're not what you claim
You don't speak, you don't speak for me
There is no mistake, it's written on your face
You don't bleed, you don't bleed
You don't bleed for me

Fly your flag of righteousness
When underneath it is deviousness, it is greed and lies
Don't pretend to know me you martyr of disgrace
With your plastic smile
I don't believe a word you say
You don't speak for me
You don't bleed, you don't bleed
You don't bleed for me
For me

Your words betray
The life that you live is a lie
The truth remains
I see through you

It's clear to me now you're not what you claim
You don't speak, you don't speak for me
There is no mistake, it's written on your face
You don't bleed, you don't speak
You don't bleed, you don't bleed for me
You don't bleed for me
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

#define eps 1e-13
#define M_PI 3.141592653589793
//#define bs 1000000007
#define bsize 512

using namespace std;

const int N = 1000031;

int n,m;
long long L[N];
long long HDP[5005][5005];
long long A[N];
long long S,dp[N],ndp[N];
long long bs;
long long fact[N];

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin>>n>>m>>bs;
	
	fact[0]=1;
	for (int i=1;i<=m;i++)
		fact[i]=1ll*fact[i-1]*i%bs;
	
	for (int i=1;i<=n;i++)
		cin>>L[i];
	
	HDP[0][0]=1;
	for (int i=1;i<=5000;i++)
		for (int j=1;j<=i;j++)
			HDP[i][j]=(HDP[i-1][j-1]+HDP[i-1][j]*1ll*(j-1))%bs;
	
	A[1]=m%bs;
	for (int i=2;i<=m;++i)
		A[i]=A[i-1]*1ll*(m-i+1)%bs;
	
	dp[0]=1;
	S=1;
	
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<=L[i]&&j<=m;j++)
			ndp[j]=0;
		
		if (i>1)
		{
			S=0;
			for (int j=1;j<=L[i-1]&&j<=m;j++)
			{
				S=(S+1ll*dp[j]*A[j])%bs;
			}
		}
		
		for (int j=1;j<=L[i]&&j<=m;j++)
		{
			ndp[j]=1ll*S*HDP[L[i]][j]%bs;
			// subt bad
			if (j<=L[i-1])
			{
				long long bad=dp[j]*fact[j]%bs;
				bad=bad*HDP[L[i]][j]%bs;
				ndp[j]-=bad;
				if (ndp[j]<0)
					ndp[j]+=bs;
			}
		}
		for (int j=1;j<=L[i]&&j<=m;j++)
			dp[j]=ndp[j];
		/*
		for (int j=1;j<=L[i]&&j<=m;j++)
			cout<<dp[j]<<" ";
		cout<<endl;
		*/
	}
	
	long long ans=0;
	for (int i=1;i<=m&&i<=L[n];i++)
		ans=(ans+1ll*dp[i]*A[i])%bs;
	cout<<ans<<endl;
	
	return 0;
}