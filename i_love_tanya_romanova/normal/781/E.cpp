/*
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

int h,w,n,u[N],l[N],r[N],s[N];
vector<pair<int,int> > order;
vector<pair<int,int> >qu_res;
int THOLD;

pair<int,int> t[N*4];
stack<pair<int,int> > S[N];

void build(int v,int tl,int tr)
{
	t[v]=make_pair(1e9+1e6,1e9+1e6);
	if (tl==tr)
		return ;
	int tm=tl+tr;
	tm/=2;
	build(v*2,tl,tm);
	build(v*2+1,tm+1,tr);
}

pair<int,int> better(pair<int,int> p1,pair<int,int> p2){
	if (p1.second!=p2.second)
	{
		if (p1.second<p2.second)
			return p1;
		return p2;
	}
	return p1;
}

void add(int v,int tl,int tr,int h,int ps,int val)
{
	//cout<<v<<"%"<<tl<<" "<<tr<<endl;

	//t[v].insert(make_pair(h,make_pair(ps,val)));
	if (tl==tr)
	{
		S[tl].push(make_pair(h,val));
		t[v]=better(t[v],make_pair(tl,h));
		return ;
	}

	int tm=tl+tr;
	tm/=2;
	if (ps<=tm)
		add(v*2,tl,tm,h,ps,val);
	else
		add(v*2+1,tm+1,tr,h,ps,val);
	t[v]=better(t[v*2],t[v*2+1]);
}

void remove(int v,int tl,int tr,int ps,int h,int val)
{
	//cout<<S[tl].size()<<endl;

	//cout<<v<<"@"<<tl<<" "<<tr<<endl;

	if (tl==tr)
	{
		//cout<<tl<<" "<<tr<<" "<<S[tl].size()<<endl;

		S[tl].pop();
		if (S[tl].size()==0)
			t[v]=make_pair(1e9+1e6,1e9+1e6);
		else
			t[v]=make_pair(tl,S[tl].top().first);
		return;
	}

	int tm=tl+tr;
	tm/=2;
	if (ps<=tm)
		remove(v*2,tl,tm,ps,h,val);
	else
		remove(v*2+1,tm+1,tr,ps,h,val);
	t[v]=better(t[v*2],t[v*2+1]);
}

pair<int,int> get(int v,int tl,int tr,int l,int r)
{
	if (l>r)
		return make_pair(1e9+1e6,1e9+1e6);
	if (tl==l&&tr==r)
		return t[v];
	int tm=tl+tr;
	tm/=2;
	pair<int,int> p1=get(v*2,tl,tm,l,min(r,tm));
	pair<int,int> p2=get(v*2+1,tm+1,tr,max(tm+1,l),r);
	return better(p1,p2);
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>h>>w>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>u[i]>>l[i]>>r[i]>>s[i];
		order.push_back(make_pair(u[i],i));
	}

	build(1,1,w);

	sort(order.begin(),order.end());
	reverse(order.begin(),order.end());

	for (int i=1;i<=w;i++)
	{
		add(1,1,w,h+1,i,1);
	}

	for (int i=0;i<order.size();i++)
	{
		qu_res.clear();
		int id=order[i].second;
		THOLD=u[id]+s[id];

		while (true)
		{
			pair<int,int> p=get(1,1,w,l[id],r[id]);
			if (p.second>THOLD||p.second>h+5)
				break;
		//	cout<<p.first<<"@"<<p.second<<endl;

			qu_res.push_back(S[p.first].top());
			remove(1,1,w,p.first,p.second,-1);
		}
		long long s=0;
		for (int j=0;j<qu_res.size();j++)
		{
			s+=qu_res[j].second;
			s%=bs;
		}
		//cout<<s<<endl;

		if (l[id]==1) // 2 at r
		{
			s*=2;
			s%=bs;
			add(1,1,w,u[id],r[id]+1,s);
		}
		else if (r[id]==w) // 2 at l
		{
			s*=2;
			s%=bs;
			add(1,1,w,u[id],l[id]-1,s);
		}
		else
		{
			add(1,1,w,u[id],l[id]-1,s);
			add(1,1,w,u[id],r[id]+1,s);
		}
	}

	qu_res.clear();
	THOLD=1e9+1e8;

	//cout<<"@"<<endl;

	long long ans=0;

	while (true)
	{
		pair<int,int> p=get(1,1,w,1,w);
		if (p.first>1e9+5)
			break;
		//cout<<p.first<<"%"<<p.second<<endl;

		ans+=S[p.first].top().second;
		remove(1,1,w,p.first,p.second,-1);
		ans%=bs;
	}

	cout<<ans<<endl;

	cin.get(); cin.get();
	return 0;
}