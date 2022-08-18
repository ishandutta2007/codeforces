/*
Let the weakness set in
This world I know
Days cannot hold me
I blur in between
Never fully engaged
The mind races between words
As far as I can get
Away from it all

When indecision ends can life begin again

I am silence
When the world screams out
I am escape when you reach out to me
I am panic
I am fear behind these walls that protect me
I am failure and resistance
I am lost where I belong
I am silence when the world screams

My insecurity extends
To others talking about themselves
Fed with this poison of
Self righteous false confidence
It's in their eyes
It's in our lives

Set to the tune of darkness
This is one to hold
I cannot stop insanity
From chasing down my thoughts
Linger in the mind
For what now seems indefinite time
My mind is holding me down

When indecision ends can life begin again

I am silence
When the world screams out
I am escape when you reach out to me
I am panic
I am fear behind these walls that protect me
I am failure and resistance
I am lost where I belong
I am silence when the world screams
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

int n;
string st;

long long dp[N];

long long safe_mult(long long a,long long b)
{
	if (a==0||b==0)
		return 0;
	if (5e18/b<=a)
		return 5e18;
	return a*b;
}

long long eval_num(long long l,long long r)
{
	long long res=0;
	for (int i=l;i<=r;i++)
	{
		res=res*10+st[i]-48;
	}
	return res;
}

bool valid_num(int l,int r)
{
	if (l!=r&&st[l]=='0')
		return false;
	if (r>l+15)
		return false;
	long long here=eval_num(l,r);
	if (here<n)
		return true;
	return false;
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	cin>>st;
	if (st=="0")
	{
		cout<<0<<endl;
		return 0;
	}

	for (int i=0;i<=st.size();i++)
	{
		dp[i]=5e18;
	}
	dp[0]=0;
	for (int i=0;i<st.size();i++)
	{
		for (int j=i;j<st.size();j++)
		{
			if (valid_num(i,j))
			{
				dp[j+1]=min(dp[j+1],safe_mult(dp[i],n)+eval_num(i,j));
			}
		}
	}

	cout<<dp[st.size()]<<endl;

	cin.get(); cin.get();
	return 0;
}