/*
Many many years ago, when Persia came ashore
Heeding Leonidas' call the Spartans went to war

Joined by their brothers, a few against the fateful horde
Hellenic hearts are set aflame, the hot gates calls their name

A final stand, stop the Persians, spear in hand
Form a wall, live to fall, and live forever

Sparta! Hellas!
Then, and again. Sing of three hundred men
Slaughter! Persians!
Glory and death. Spartans will never surrender

Morning has broken, today they're fighting in the shade

When arrows blocked the sun they fell,
Tonight they dine in Hell

By traitor's hand. secret passage, to their land
Know his name, know his shame will last forever
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
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007
const int N = 1100031;

int n,pr[N],cnt[N],meb[N];
int guys_divisible[N];
int guys_with[N];
int pw2[N],ans;
long long score[N];

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	pw2[0]=1;
	for (int i=1;i<N;i++)
	{
		pw2[i]=pw2[i-1]*2%bs;
	}

	cin>>n;
	pr[1]=1;
	for (int i=2;i<N;i++)
	{
		if (pr[i]==0)
		{
			for (int j=i*2;j<N;j+=i)
				pr[j]=1;
		}
	}

	for (int i=1;i<N;i++)
	{
		if (pr[i]==0)
		{
			for (int j=i;j<N;j+=i)
			{
				cnt[j]++;
			}
		}
	}

	for (int i=2;i*i<N;i++)
	{
		for (int j=i*i;j<N;j+=i*i)
			cnt[j]=-1;
	}
	for (int i=1;i<N;i++)
	{
		if (cnt[i]==-1)
			meb[i]=0;
		else if (cnt[i]%2)
			meb[i]=1;
		else
			meb[i]=-1;
	}

	for (int i=1;i<=n;i++)
	{
		int val;
		cin>>val;
		guys_with[val]++;
	}

	for (int i=1;i<N;i++)
	{
		for (int j=i;j<N;j+=i)
			guys_divisible[i]+=guys_with[j];
	}

	for (int i=2;i<N;i++)
	{
		if (guys_divisible[i]==0)
			continue;
		long long ways=pw2[guys_divisible[i]-1];
		ways=ways*guys_divisible[i]%bs;
		score[i]=ways;
	}

	/*for (int i=1;i<=10;i++)
	{
		cout<<i<<" "<<score[i]<<endl;
	}*/

	for (int i=N-1;i>=1;--i)
	{
		for (int j=i*2;j<N;j+=i)
		{
			score[i]-=score[j];
			if (score[i]<0)
				score[i]+=bs;
		}
	}

	/*for (int i=1;i<=10;i++)
	{
		cout<<i<<"   "<<score[i]<<endl;
	}*/

	for (int i=2;i<N;i++)
	{
		ans=(ans+1ll*score[i]*i)%bs;
	}
	cout<<ans<<endl;


	cin.get(); cin.get();
	return 0;
}