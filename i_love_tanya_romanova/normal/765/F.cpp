/*
I will not play along
With things I find unfair
I will not mount defences
Against unjust attacks
This land was never given
We built this on our own
It is sanity dependent
Whether we rise or fall

Whether we rise or we fall
One for the night
One for uncontrol

Hold your feet to the ground
To the end of our time for the rest of our lives
Hold your head up high
To the end of our time for the rest of our lives

Secretly I hope
That nothing ever comes of this
And you are not alone
In wanting to come back
To a place where it won't matter
Just what side you're on
It's when our lives are branded
What's underneath will overcome

What's underneath will overcome
One for the night one for the uncontrol

Hold your feet to the ground
To the end of our time for the rest of our lives
Hold your head up high
To the end of our time for the rest of our lives

Now it's time to stand up tall
One for the night
One for the uncontrol

Hold your feet to the ground
To the end of our time for the rest of our lives
Hold your head up high
To the end of our time for the rest of our lives
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
#define right asdashgasrhsdf

#define eps 1e-11
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 600031;

int n,ar[N];
int tests;
int l[N],r[N];
int ans[N];

vector<int> qu_list[N];
int m;
vector<pair<int,int> > order;
int Ps[N];

int t_ans[N*4];
int t_le[N*4];

void build_tree_ans(int v,int tl,int tr)
{
	t_ans[v]=1e9;
	if (tl==tr)
		return ;
	int tm=tl+tr;
	tm/=2;
	build_tree_ans(v*2,tl,tm);
	build_tree_ans(v*2+1,tm+1,tr);
}

void build_tree_last_entry(int v,int tl,int tr)
{
	t_le[v]=-1;
	if (tl==tr)
		return ;
	int tm=tl+tr;
	tm/=2;
	build_tree_last_entry(v*2,tl,tm);
	build_tree_last_entry(v*2+1,tm+1,tr);
}

int get_ans(int v,int tl,int tr,int l,int r)
{
//	cout<<v<<" "<<tl<<" "<<tr<<" "<<l<<" "<<r<<" "<<t_ans[v]<<endl;
	if (l>r)
		return 1e9;
	if (tl==l&&tr==r)
		return t_ans[v];
	int tm=tl+tr;
	tm/=2;
	return min(get_ans(v*2,tl,tm,l,min(r,tm)),get_ans(v*2+1,tm+1,tr,max(tm+1,l),r));
}

int get_le(int v,int tl,int tr,int l,int r)
{
	if (l>r)
		return -1;
	if (l==tl&&tr==r)
		return t_le[v];
	int tm=tl+tr;
	tm/=2;
	return max(get_le(v*2,tl,tm,l,min(r,tm)),get_le(v*2+1,tm+1,tr,max(tm+1,l),r));
}

void update_ans(int v,int tl,int tr,int ps,int val)
{
	if (tl==tr)
	{
		t_ans[v]=min(t_ans[v],val);
		return ;
	}
	int tm=tl+tr;
	tm/=2;
	if (ps<=tm)
		update_ans(v*2,tl,tm,ps,val);
	else
		update_ans(v*2+1,tm+1,tr,ps,val);
	t_ans[v]=min(t_ans[v*2],t_ans[v*2+1]);
}

void update_le(int v,int tl,int tr,int ps,int val)
{
	if (tl==tr)
	{
		t_le[v]=max(t_le[v],val);
		return ;
	}
	int tm=tl+tr;
	tm/=2;
	if (ps<=tm)
		update_le(v*2,tl,tm,ps,val);
	else
		update_le(v*2+1,tm+1,tr,ps,val);
	t_le[v]=max(t_le[v*2],t_le[v*2+1]);
}

void add_element(int ps)
{
	int bound=1e9;
	while (true)
	{
		int le=lower_bound(order.begin(),order.end(),make_pair(ar[ps],-1))-order.begin();
		int ri=upper_bound(order.begin(),order.end(),make_pair(bound+1,-1))-order.begin();
		if (ri==le)
			break;
		int last_ent=get_le(1,0,n-1,le,ri-1);
		if (last_ent==-1)
			break;
		int cur_val=ar[last_ent];
		int res_here=cur_val-ar[ps];
		//cout<<last_ent<<" "<<ps<<"%"<<res_here<<endl;
		update_ans(1,1,n,last_ent,res_here);
		//cout<<get_ans(1,1,n,4,8)<<"%%"<<endl;
		if (cur_val==ar[ps])
			break;
		bound=(cur_val+ar[ps])/2;
	}
	update_le(1,0,n-1,Ps[ps],ps);
}

void run_solver()
{
	for (int i=1;i<=n;i++)
	{
		qu_list[i].clear();
	}

	int m=tests;

	for (int i=1;i<=m;i++)
	{
		qu_list[r[i]].push_back(i);
	}

	order.clear();
	for (int i=1;i<=n;i++)
	{
		order.push_back(make_pair(ar[i],i));
	}
	sort(order.begin(),order.end());

	for (int i=0;i<order.size();i++)
	{
		Ps[order[i].second]=i;
	}

	build_tree_ans(1,1,n);
	build_tree_last_entry(1,0,n-1);

	for (int i=1;i<=n;i++)
	{
		add_element(i);
		for (int j=0;j<qu_list[i].size();j++)
		{
			int id=qu_list[i][j];
			//cout<<id<<"%^"<<l[id]<<" "<<r[id]<<endl;
			ans[id]=min(ans[id],get_ans(1,1,n,l[id],r[id]));
		}
	}

}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>ar[i];
	}

	cin>>tests;
	for (int test=1;test<=tests;test++)
	{
		int i=test;

		cin>>l[i]>>r[i];
		ans[i]=1e9;
	}

	run_solver();
	for (int i=1;i<=n;i++)
	{
		if (i<n-i+1)
			swap(ar[i],ar[n-i+1]);
	}

	for (int i=1;i<=tests;i++)
	{
		l[i]=n-l[i]+1;
		r[i]=n-r[i]+1;
		swap(l[i],r[i]);
	}

	run_solver();

	for (int i=1;i<=tests;i++)
	{
		cout<<ans[i]<<"\n";
	}

	cin.get(); cin.get();
	return 0;
}