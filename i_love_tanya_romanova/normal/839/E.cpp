/*
War begun, the Kaiser has come
Day or night, the shells keep falling
Overrun but never outdone
Street to street, denying defeat

Soldiers of the Serbian army
Keep your heads held high
Overrun, you fall one by one
For Belgrade and the fatherland

Soldiers, heroes, die for your land
Your lives are gone, erased by your command

Until your last dying breath

Overrun, you're under the gun
Day or night, the shells kept falling
Sound the drum, the great war has come
Show no fear, the ending is near

A final charge, to face the fire
Falling one by one
Major calls. The white city falls
Belgrade's streets are stained by blood

In haste, our lives are erased
Forward to glory for king and country

Defend the honour of Belgrade
Forward to glory, to face your fate at last
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

int n,k,val;
int ar[100][100];
long long adj[100];

int pcount(int x)
{
	if (x==0)
		return 0;
	return pcount(x/2)+x%2;
}

int max_clique[1<<22];

int ans,fi,se;

void backtrack(int ps,long long mask,long long mask_second,int ones)
{
	if((mask&mask_second)!=mask_second)
		return;

	if (ps==n)
	{
		ans=max(ans,max_clique[mask&((1ll<<fi)-1)]+ones);
		return;
	}
	backtrack(ps+1,mask,mask_second,ones);
	backtrack(ps+1,mask&adj[ps],mask_second|(1ll<<ps),ones+1);
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>k;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			cin>>val;
			if (i==j)
				val=1;
			ar[i-1][j-1]=val;
			if (ar[i-1][j-1])
				adj[i-1]|=(1ll<<(j-1));
		}
	}

	fi=n/2;
	se=n-fi;

	for (int mask=0;mask<(1ll<<fi);mask++)
	{
		long long adj_list=(1ll<<n);
		--adj_list;
		for (int i=0;i<n;i++)
		{
			if (mask&(1ll<<i))
				adj_list&=adj[i];
		}
		adj_list&=mask;
		if (adj_list==mask)
			max_clique[mask]=pcount(mask);
	}

	for (int mask=0;mask<(1ll<<fi);mask++)
	{
		for (int j=0;j<n;j++)
		{
			if (mask&(1ll<<j))
				max_clique[mask]=max(max_clique[mask-(1ll<<j)],max_clique[mask]);
		}
	//	cout<<mask<<" "<<max_clique[mask]<<endl;
	}

	backtrack(fi,(1ll<<n)-1,0,0);

//	cout<<ans<<endl;

	cout.precision(15);
	double per_one=k*1.0/ans;
	double answ=per_one*(k-per_one)*ans;
	cout<<fixed<<answ/2<<endl;

	cin.get(); cin.get();
	return 0;
}