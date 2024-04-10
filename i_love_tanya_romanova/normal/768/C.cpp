/*
Lovely little lady
You've got me on the run
You're a love machine and you say that I'm your gun
But I don't care 'cause I've got to know

You said you were a loser
The kind that came off worse
So I had to try hard to satisfy your thirst
But I don't care 'cause I've got to know

The only time she's happy
Is when the bullets fly
And she'll make you feel you're better than any other guy
But I don't care 'cause I've got to know

Lovely little lady
You've got me on the run - yeah
You're a love machine and you say that I'm your gun
But I don't care 'cause I've got to know
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

#define eps 1e-11
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 200031;

int n,k,x;
int cnt[N],new_cnt[N];

void perform_op()
{
	int v1,v2;
	int s=0;
	for (int i=0;i<1024;i++)
	{
		if (cnt[i]==0)
			continue;
		v1=(cnt[i]+1)/2;
		v2=cnt[i]-v1;
		if (s%2)
			swap(v1,v2);
		new_cnt[i^x]+=v1;
		new_cnt[i]+=v2;
		s+=cnt[i];
	}
}

int main(){
//	freopen("japanese.in","r",stdin);
//	freopen("japanese.out","w",stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>k>>x;
	for (int i=0;i<n;i++)
	{
		int val;
		cin>>val;
		cnt[val]++;
	}

	for (int iter=1;iter<=k;iter++)
	{
		for (int j=0;j<1024;j++)
		{
			new_cnt[j]=0;
		}

		perform_op();
		for (int j=0;j<1024;j++)
		{
			cnt[j]=new_cnt[j];
		}
	}

	int mx=-1e9;
	int mn=1e9;
	for (int i=0;i<1024;i++)
	{
		if (cnt[i])
		{
			mx=max(mx,i);
			mn=min(mn,i);
		}
	}

	cout<<mx<<" "<<mn<<endl;

	cin.get(); cin.get();
	return 0;
}