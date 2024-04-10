/*
Our backs can never carry
These atrocities around
So we focus on what's safely within reach
To market our concerns
Inside this time and place
There is nothing more you can be to me
Bring out your fear
Bring out your death
Bring out your pain

For now we lie to ourselves to live
Sorrow will find you

You're the only one who knows
things I never say
And nothing can be done
Til skies are clear again
These are things we never talk about
So hear me out this time
I know one day this sorrow will find you

Let your heroes burn their crowns
You're better than this I know
This world can change the best of us
Sometimes for the worst
Sometimes for the ones we try to hold
The ones we hold on to
Bring out your fear
Bring out your death
for now we lie to ourselves to live
sorrow will find you
you're the only one who knows
things I never say
and nothing can be done
til skies are clear again
these are things we never talk about
so hear me out this time
I know one day this sorrow will find you
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

long long n,m,x,y,k,ans[200][200];
vector<long long> order;
long long one_circle;

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>m>>k>>x>>y;
	if (n==1)
		one_circle=m;
	else
		one_circle=(2*n-2)*m;

	long long circles=k/one_circle;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			ans[i][j]+=circles;
			if (i!=n&&i!=1)
				ans[i][j]+=circles;
		}
	}
	k%=one_circle;

	//cout<<circles<<" "<<endl;

	for (int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if (k)
			{
				--k;
				ans[i][j]++;
			}
		}
	}

	for (int i=n-1;i>1;--i)
	{
		for (int j=1;j<=m;j++)
		{
			if (k)
			{
				--k;
				ans[i][j]++;
			}
		}
	}

	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			order.push_back(ans[i][j]);
		}
	}

	sort(order.begin(),order.end());
	cout<<order.back()<<" "<<order[0]<<" "<<ans[x][y]<<endl;

	cin.get(); cin.get();
	return 0;
}