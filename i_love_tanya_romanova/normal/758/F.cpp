/*
In every hour every day
This chosen solitude is gone
The pressure coursing
Through your every nerve
Will rise and fade away
There's madness to this method
Conformity now on display
When confidence become the enemy
In time our questions lose their meaning
Wish it away and it comes back to you somehow
A loneliness denied
Our shallow pool of wisdom
Reflects upon our innocent face
Between attacks of pure anxiety
You see humanity slip away
You force the lie to be an absolute
To where there will be no return
There is a face on the surface
I don't ever want to see
There is a light above the water
That is not supposed to be
If there is truth in this resistance
I don't ever want to know
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
const int N = 200031;

long long n,l,r,ans;

int G[4050][4050];
int S[4050];

long long safe_mult(long long a,long long b)
{
	if (a==0||b==0)
		return 0;
	if (1e15/b<=a)
		return 1e15;
	return a*b;
}

long long get_pw(long long a,long long b)
{
	if (b==1)
		return a;
	return safe_mult(a,get_pw(a,b-1));
}

long long pw(long long a,long long b)
{
	if (b==0)
		return 1;
	if (b%2)
		return a*pw(a,b-1);
	return pw(a*a,b/2);
}

long long mem_p[4050];

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>l>>r;
	if (n==1)
	{
		cout<<(r-l+1)<<endl;
		return 0;
	}

	if (n==2)
	{
		long long ans=0;
		for (int i=l;i<=r;i++)
		{
			ans+=r-i;
		}
		cout<<2*ans<<endl;
		return 0;
	}

	--n;

	for (int i=1;i<=4000;i++)
	{
		for (int j=0;j<=i;j++)
		{
			if (j==0)
				G[i][j]=i;
			else
				G[i][j]=G[j][i%j];
		}
	}

	for (int i=1;i<=4000;i++)
	{
		mem_p[i]=pw(i,n);
	}

	for (int p=2;;p++)
	{
		if (get_pw(p,n)>r)
			break;
		for (int i=1;i<=p;i++)
		{
			S[i]=S[i-1];
			if (G[p][i]==1)
				S[i]++;
		}
		long long P=get_pw(p,n);
		long long Q=p-1;

		for (long long d=1;d*P<=r;d++)
		{
			while (mem_p[Q]*d>=l)
				--Q;
			ans+=S[p]-S[Q];
			//cout<<p<<"#"<<d<<" "<<Q<<endl;
		}
	}
	cout<<ans*2<<endl;

	cin.get(); cin.get();
	return 0;
}