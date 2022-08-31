/*
She's been gone since yesterday
Oh I didn't care
Never cared for yesterdays
Fancies in the air

No sighs or mysteries
She lay golden in the sun
No broken harmonies
But I've lost my way
She had rainbow eyes
Rainbow eyes
Rainbow eyes

Love should be a simple blend
A whispering on the shore
No clever words you can't defend
They lead to never more

No sighs or mysteries
She lay golden in the sun
No broken harmonies
But I've lost my way
She had rainbow eyes
Rainbow eyes
Rainbow eyes

Summer nights are colder now
They've taken down the fair
And all the lights have died somehow
Or were they ever there

No sighs or mysteries
She lay golden in the sun
No broken harmonies
But I've lost my way
She had rainbow eyes
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
const int N = 501031;

int n,q;
vector<pair<int,int> > order;
vector<int> candidates;
int ans;

vector<int> t[N*4];

int count_on_seg(int val,int l,int r)
{
	return upper_bound(order.begin(),order.end(),make_pair(val,r))-lower_bound(order.begin(),order.end(),make_pair(val,l));
}

void run_query(int v,int tl,int tr,int l,int r)
{
	if (l>r)
		return;
	if (tl==l&&tr==r)
	{
		for (int i=0;i<t[v].size();i++)
		{
			candidates.push_back(t[v][i]);
		}
		return;
	}
	int tm=tl+tr;
	tm/=2;
	run_query(v*2,tl,tm,l,min(r,tm));
	run_query(v*2+1,tm+1,tr,max(tm+1,l),r);
}

int a[N];

vector<int> cleanup(vector<int> v){
	vector<int> ret;
	for (int i=0;i<v.size();i++)
	{
		if (i==0||v[i]!=v[i-1])
			ret.push_back(v[i]);
	}
	return ret;
}

void build(int v,int tl,int tr)
{
	if (tl==tr)
	{
		t[v].push_back(a[tl]);
		return;
	}
	int tm=tl+tr;
	tm/=2;
	build(v*2,tl,tm);
	build(v*2+1,tm+1,tr);
	for (int i=0;i<t[v*2].size();i++)
	{
		int entries_here=count_on_seg(t[v*2][i],tl,tr);
		if (entries_here*5>tr-tl+1)
			t[v].push_back(t[v*2][i]);
	}
	for (int i=0;i<t[v*2+1].size();i++)
	{
		int entries_here=count_on_seg(t[v*2+1][i],tl,tr);
		if (entries_here*5>tr-tl+1)
			t[v].push_back(t[v*2+1][i]);
	}
	sort(t[v].begin(),t[v].end());
	t[v]=cleanup(t[v]);
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>q;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		order.push_back(make_pair(a[i],i));
	}

	sort(order.begin(),order.end());

	build(1,1,n);

	for (;q;--q)
	{
		int l,r,k;
		scanf("%d",&l);
		scanf("%d",&r);
		scanf("%d",&k);
		candidates.clear();
		run_query(1,1,n,l,r);
		ans=2e9;
		for (int i=0;i<candidates.size();i++)
		{
			int here=count_on_seg(candidates[i],l,r);
//			cout<<l<<" "<<r<<" "<<here<<" "<<candidates[i]<<endl;
			if (here*k>r-l+1)
				ans=min(ans,candidates[i]);
		}
		if (ans>1e9)
			ans=-1;
		printf("%d\n",ans);
	}

	cin.get(); cin.get();
	return 0;
}