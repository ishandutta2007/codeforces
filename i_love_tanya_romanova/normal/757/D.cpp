/*
Little grave I'm grieving, I will mend you
Sweet revenge I'm dreaming, I will end you

I've been here since dawn of time
Countless hatreds built my shrine
I was born in anger's flame
He was Abel, I was Cain
I am here
I'm hell unbound
Burn your kingdom to the ground
To the ground

Here comes revenge, just for you
Revenge, you can't undo
Revenge, is killing me
Revenge, set me free
Eye for an eye, tooth for a tooth
A life for a life, it's my burden of proof
Revenge, just for you
Revenge
You ask forgiveness, I give you sweet revenge

I return this nightmare, I will find you
Sleepless, cloaked in despair, I'm behind you

Man has made me oh so strong
Blurring lines of right and wrong
Far too late for frail amends
Now it's come to sweet revenge
Desperate hands
That lose control
Have no mercy on your soul
On your soul

Here comes revenge, just for you
Revenge, you can't undo
Revenge, is killing me
Revenge, just set me free
Eye for an eye, tooth for a tooth
A life for a life, it's my burden of proof
Revenge, just for you
Revenge
You ask forgiveness, I give you sweet revenge

Here comes revenge, just for you
Revenge, you can't undo
Revenge, is killing me
Revenge, set me free
Eye for an eye, tooth for a tooth
A life for a life, it's my burden of proof
Revenge, just for you
Revenge
You ask forgiveness, I give you sweet revenge

Sweet revenge
*/

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
#define bs 1000000007
#define bsize 512

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 1000031;

int res;

int get_len(int x)
{
	if (x==1)
		return 1;
	return get_len(x/2)+1;
}

int n;
string st;
int dp[80][1<<20];

int s[200][200];

void add(int &a,int b)
{
	a+=b;
	if (a>=bs)
		a-=bs;
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//	freopen("F:/input.txt", "r", stdin);
	//	freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	/*for (int i=1;i<=20;i++)
	{
		res+=get_len(i);
	}

	cout<<res<<endl;
	 */

	cin>>n;
	cin>>st;

	for (int i=0;i<st.size();i++)
	{
		int cur=0;
		for (int j=i;j<st.size();j++)
		{
			cur=cur*2+st[j]-48;
			s[i][j+1]=cur-1;
		}
	}

	for (int i=0;i<=st.size();i++)
	{
		dp[i][0]=1;
	}

	//cout<<"%"<<endl;

	for (int cur_pref=0;cur_pref<st.size();cur_pref++)
	{
		//cout<<cur_pref<<endl;

		for (int mask=0;mask<(1<<20);mask++)
		{
			if (dp[cur_pref][mask]==0)
				continue;
			for (int next_ps=cur_pref+1;next_ps<=st.size();next_ps++)
			{
				int here=s[cur_pref][next_ps];
				if (here>19)
					break;
				if (here<0)
					continue;

				add(dp[next_ps][mask|(1<<here)],dp[cur_pref][mask]);
			}
		}
	}

	int ans=0;

	for (int k=1;k<=20;k++)
	{
		int need=(1<<k)-1;
		for (int i=1;i<=n;i++)
		{
			add(ans,dp[i][need]);
		}
	}

	cout<<ans<<endl;

	cin.get(); cin.get();
	return 0;
}