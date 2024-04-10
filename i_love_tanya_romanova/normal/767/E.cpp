/*
You were once the source of a pureness that can't be defined
And now you curse the day, how can you leave your faith behind

Just look at yourself do you like what you see
I want no more of you, watch me walk away

This is your last time you are forgotten
You let your dreams die you are the forgotten

Placed your ego above all but misplaced your innocence

Just look at yourself do you like what you see
I want no more of you, watch me walk away

This is your last time you are forgotten
You let your dreams die you are the forgotten

What have you given up will never return again
Now you're dead inside I hope it was worth the cost
I hope it was worth the cost I hope it was worth the cost
Now you're buried alive

This is the last time
This is the last time you are forgotten
You let your dreams die you are forgotten
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
const int N = 100031;

int n,start_val;
int ar[N];
int w[N];
int flag[N];
long long ans;
set<pair<long long,long long> > S;
set<pair<long long, long long> > ::iterator it;

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>start_val;
	for (int i=1;i<=n;i++)
	{
	//	cin>>ar[i];
		scanf("%d",&ar[i]);
	}
	for (int i=1;i<=n;i++)
	{
//		cin>>w[i];
		scanf("%d",&w[i]);
	}

	for (int i=1;i<=n;i++)
	{
		if (ar[i]%100==0)
			continue;
		start_val-=ar[i]%100;
		long long cost_here=w[i]*(100-ar[i]%100);
		S.insert(make_pair(cost_here,i));
		while (start_val<0)
		{
			it=S.begin();
			pair<long long, long long> p=(*it);
			S.erase(it);
			start_val+=100;
			flag[p.second]=1;
			ans+=p.first;
		}
	}

	cout<<ans<<endl;

	for (int i=1;i<=n;i++)
	{
		if (flag[i])
		{
			printf("%d",ar[i]/100+1);
			printf(" 0\n");
		}
		else
		{
			printf("%d",ar[i]/100);
			printf(" %d\n",ar[i]%100);
		}
	}

	cin.get(); cin.get();
	return 0;
}