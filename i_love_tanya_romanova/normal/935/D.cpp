/*
John San what you can
La la Janette dance in sand
What's the mystery my son
Gypsy Dan Caravan
Won Tun Wan with your Chinese fan
It's part of history my son

Murder and rape with your power
The 10th revolution in far away days
It's come to this
A gypsy's kiss
All your power's gonna fade in the haze

Ya who' Jumme gae bile ya heed
The Senorita said
I'll drag yer lungs out through yer nose
Space truckers free and high
Teamsters get ya by and by
That should keep you on your toes

They got a gun at your head
But you ain't necessarily playing their
game
They can't resist
A Gypsy's Kiss
All that's needed to drive them insane

John Wayne The Alamo
Crazy Horse Geronimo
I'll smoke a piece with you
Mind Body Heart and Soul
We got Rock and Roll
And there's nothing they can do

Hear the small voice of truth
Above the shouting despair of the crowd
What do you wish
A Gypsy's Kiss
Gets you strong for crying out loud
*/

//#pragma GCC optimize("O3")
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 400031;

long long n,m,dp[N][4],a[N],b[N];

long long pw(long long a,long long b){
	if (b==0)
		return 1;
	if (b%2)
		return a*pw(a,b-1)%bs;
	return pw(a*a%bs,b/2);
}

long long inv(long long x){
	return pw(x,bs-2);
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n>>m;

	long long invM=inv(m);

	long long halfOfM1=invM*(m-1)%bs*inv(2)%bs;

	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	for (int i=0;i<n;i++){
		cin>>b[i];
	}

	dp[0][0]=1;
	for (int i=0;i<n;i++){
		for (int flag=0;flag<=2;flag++){
			if (flag!=0){
				dp[i+1][flag]+=dp[i][flag];
				dp[i+1][flag]%=bs;
				continue;
			}
			// flag is still 0
			if (a[i]!=0&&b[i]!=0){
				if (a[i]>b[i])
				{
					dp[i+1][1]+=dp[i][flag];
					dp[i+1][1]%=bs;
					continue;
				}
				if (a[i]<b[i]){
					dp[i+1][2]+=dp[i][flag];
					dp[i+1][2]%=bs;
					continue;
				}
				dp[i+1][0]+=dp[i][0];
				dp[i+1][0]%=bs;
				continue;
			}
			// at least one zero at this point
			if (a[i]==0&&b[i]==0){// let's fix one of them
				dp[i+1][0]+=dp[i][0]*invM;
				dp[i+1][0]%=bs;

				dp[i+1][1]+=dp[i][0]*halfOfM1;
				dp[i+1][2]+=dp[i][0]*halfOfM1;
				dp[i+1][1]%=bs;
				dp[i+1][2]%=bs;
				continue;
			}

			if (a[i]!=0){ // b[i]=0
				dp[i+1][0]+=dp[i][0]*invM;
				dp[i+1][0]%=bs;
				dp[i+1][1]+=dp[i][0]*(a[i]-1)%bs*invM;
				dp[i+1][2]+=dp[i][0]*(m-a[i])%bs*invM;
				dp[i+1][1]%=bs;
				dp[i+1][2]%=bs;
			}
			else // a[i]==0
			{ // cp, fix T <>
				dp[i+1][0]+=dp[i][0]*invM;
				dp[i+1][0]%=bs;
				dp[i+1][2]+=dp[i][0]*(b[i]-1)%bs*invM;
				dp[i+1][1]+=dp[i][0]*(m-b[i])%bs*invM;
				dp[i+1][2]%=bs;
				dp[i+1][1]%=bs;
			}
		}
	}

	cout<<dp[n][1]<<endl;

//	cin.get(); cin.get();
	return 0;
}