/*
No more love to purchase
I've invested in myself
You know nothing about me
Keep opinions to yourself
No more complications
Everything's just swell
No more obligations
There's nothing more to tell

Ooh
I just want to be alone

When I get weak or I'm dying and afraid
When I sleep all my dreams turn out the same
When I bleed I'll relieve you of your pain
Can't believe you won't let me do the same
Oh oh

Please give me a reason
So I can shut you out
Though your heart is bleeding
You've left me with no doubt
Give me segregation
Give me back my health
Take your observations
And turn them on yourself

Ooh
I just want to be alone

When I get weak or I'm dying and afraid
When I sleep all my dreams turn out the same
When I bleed I'll relieve you of your pain
I can't believe you won't let me go
Let me live my life alone

When I'm running scared
That's when I need to know
That you'll let me go

When I get weak or I'm dying and afraid
When I sleep all my dreams turn out the same
When I bleed I'll relieve you of your pain
I can't believe you won't let me go
Let me live my life alone
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
#define M 18
#define N 1050

using namespace std;

int tests;
int was[33][33][55];
int memo[33][33][55];

int solve(int a,int b,int need)
{
	if (was[a][b][need])
		return memo[a][b][need];
	was[a][b][need]=1;
	if (need==0)
	{
		memo[a][b][need]=0;
		return 0;
	}
	
	if (need==a*b)
	{
		memo[a][b][need]=0;
		return 0;
	}
	
	int res=1e9;
	
	for (int i=1;i<a;i++)
	{
		for (int dwn=0;dwn<=need;dwn++)
		{
			int res1=solve(i,b,dwn);
			int res2=solve(a-i,b,need-dwn);
			res1=res1+res2+b*b;
			res=min(res,res1);
		}
	}
	for (int i=1;i<b;i++)
	{
		for (int dwn=0;dwn<=need;dwn++)
		{
			int res1=solve(a,i,dwn);
			int res2=solve(a,b-i,need-dwn);
			res1=res1+res2+a*a;
			res=min(res,res1);
		}
	}
	memo[a][b][need]=res;
	return res;
}

int main(){
//freopen("beavers.in","r",stdin);
//freopen("beavers.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

for (int i=1;i<=30;i++)
	for (int j=1;j<=30;j++)
		for (int need=0;need<=50;need++)
			solve(i,j,need);
cin>>tests;

for (;tests;--tests)
{
	int a,b,c;
	cin>>a>>b>>c;
	cout<<solve(a,b,c)<<endl;
}

//cin.get();cin.get();
return 0;}