/*
Ah ah ah ow
You walk on like a woman in suffering
Won't even bother now, to tell me why
You come alone, letting all of us savor the moment
Leaving me broken, another time
You come on like a blood stained hurricane
Leave me alone, let me be this time
You carry on like a holy man pushing redemption
I don't want to mention, the reason I know

That I am stricken and can't let you go
When the heart is cold there's no hope
And we know
That I am crippled by all that you've done
Into the abyss will I run

You don't know what your power has done to me
I want to know if I'll heal inside
I can't go on, with a holocaust about to happen
Seeing you laughing, another time
You'll never know how your face has haunted me
My very soul has to bleed this time
Another hole in the wall of my inner defenses
Leaving me breathless, the reason I know

That I am stricken and can't let you go
When the heart is cold there's no hope
And we know
That I am crippled by all that you've done
Into the abyss will I run
Into the abyss will I run

You walk on like a woman in suffering
Won't even bother now, to tell me why
You come alone, letting all of us savor the moment
Leaving me broken, another time
You come on like a blood stained hurricane
Leave me alone, let me be this time
You carry on a holy man pushing redemption
I don't want to mention, the reason I know

That I am stricken and can't let you go
When the heart is cold there's no hope
And we know
That I am crippled by all that you've done
Into the abyss will I run, into the abyss will I run

I can't let you go
Yes I am stricken and can't let you go
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
const int N = 210031;

int n,m,k,c[N];

int mask[N];

vector<pair<int,int> > with_mask[10],order;

int ps_by_id[N];
pair<long long, long long> t[N*4];

long long S[10];

pair<long long, long long> combine(pair<long long, long long> p1,pair<long long, long long> p2){
	p1.first+=p2.first;
	p1.second+=p2.second;
	return p1;
}

void build(int v,int tl,int tr)
{
	if (tl==tr)
	{
		t[v]=make_pair(1,order[tl].first);
		return ;
	}
	int tm=tl+tr;
	tm/=2;
	build(v*2,tl,tm);
	build(v*2+1,tm+1,tr);
	t[v]=combine(t[v*2],t[v*2+1]);
}

void kill(int v,int tl,int tr,int ps)
{
	if (tl==tr)
	{
		t[v]=make_pair(0,0);
		return ;
	}
	int tm=tl+tr;
	tm/=2;
	if (ps<=tm)
		kill(v*2,tl,tm,ps);
	else
		kill(v*2+1,tm+1,tr,ps);
	t[v]=combine(t[v*2],t[v*2+1]);
}

void alive(int v,int tl,int tr,int ps)
{
	if (tl==tr)
	{
		t[v]=make_pair(1,order[tl].first);
		return ;
	}
	int tm=tl+tr;
	tm/=2;
	if (ps<=tm)
		alive(v*2,tl,tm,ps);
	else
		alive(v*2+1,tm+1,tr,ps);
	t[v]=combine(t[v*2],t[v*2+1]);
}

pair<long long, long long> get(int v,int tl,int tr,int l,int r){
	if (l>r)
		return make_pair(0,0);
	if (tl==l&&tr==r)
		return t[v];
	int tm=tl+tr;
	tm/=2;
	pair<long long, long long> p1=get(v*2,tl,tm,l,min(r,tm));
	pair<long long, long long> p2=get(v*2+1,tm+1,tr,max(tm+1,l),r);
	return combine(p1,p2);
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>m>>k;
	for (int i=1;i<=n;i++)
	{
		cin>>c[i];
	}

	int cnt;
	cin>>cnt;
	for (;cnt;--cnt)
	{
		int val;
		cin>>val;
		mask[val]|=1;
	}
	cin>>cnt;
	for (;cnt;--cnt)
	{
		int val;
		cin>>val;
		mask[val]|=2;
	}

	for (int i=1;i<=n;i++)
	{
		order.push_back(make_pair(c[i],i));
	}

	sort(order.begin(),order.end());

	for (int i=1;i<=n;i++)
	{
		with_mask[mask[i]].push_back(make_pair(c[i],i));
	}

	for (int i=0;i<4;i++)
	{
		sort(with_mask[i].begin(),with_mask[i].end());
	}

	for (int i=0;i<order.size();i++)
	{
		ps_by_id[order[i].second]=i;
	}

	build(1,0,n-1);

	for (int i=0;i<with_mask[1].size();i++)
	{
		int id=with_mask[1][i].second;
		int ps=ps_by_id[id];
		S[1]+=with_mask[1][i].first;
		kill(1,0,n-1,ps);
	}
	for (int i=0;i<with_mask[2].size();i++)
	{
		int id=with_mask[2][i].second;
		int ps=ps_by_id[id];
		S[2]+=with_mask[2][i].first;
		kill(1,0,n-1,ps);
	}

	long long ans=1e18;

	long long PEN2=0;

	//pair<long long, long long> p=get(1,0,n-1,0,n-1);
	//cout<<p.first<<"% "<<p.second<<endl;

	for (int doubles=0;doubles<=k;doubles++)
	{

		if (doubles>with_mask[3].size())
			break;

		int rem_ones=k-doubles;

		//cout<<k<<"@"<<doubles<<" "<<rem_ones<<endl;

		//cout<<"@"<<rem_ones<<" "<<with_mask[1].size()<<" "<<with_mask[2].size()<<endl;

		while (with_mask[1].size()>rem_ones)
		{
			int id=with_mask[1].back().second;
			int ps=ps_by_id[id];
			S[1]-=with_mask[1].back().first;
			with_mask[1].pop_back();
			alive(1,0,n-1,ps);
		}
		while (with_mask[2].size()>rem_ones)
		{
			int id=with_mask[2].back().second;
			int ps=ps_by_id[id];
			S[2]-=with_mask[2].back().first;
			with_mask[2].pop_back();
			alive(1,0,n-1,ps);
		}

		if (doubles+rem_ones*2>m)
		{
			if (doubles<with_mask[3].size())
			{
				PEN2+=with_mask[3][doubles].first;
				int id=with_mask[3][doubles].second;
				int ps=ps_by_id[id];
				kill(1,0,n-1,ps);
			}
		}
		else
		{
			if (with_mask[1].size()<rem_ones||with_mask[2].size()<rem_ones) // fake
			{
				if (doubles<with_mask[3].size())
				{
					PEN2+=with_mask[3][doubles].first;
					int id=with_mask[3][doubles].second;
					int ps=ps_by_id[id];
					kill(1,0,n-1,ps);
				}
				continue;
			}

			long long to_pay_already=S[1]+S[2]+PEN2;
			int l,r;
			l=0;
			r=order.size()-1;

			pair<long long, long long> p=get(1,0,n-1,0,n-1);

			//cout<<p.first<<"@"<<p.second<<endl;

			if (p.first+doubles+rem_ones*2<m) // not enough
			{
				if (doubles<with_mask[3].size())
				{
					PEN2+=with_mask[3][doubles].first;
					int id=with_mask[3][doubles].second;
					int ps=ps_by_id[id];
					kill(1,0,n-1,ps);
				}
				continue;
			}
			//cout<<to_pay_already<<endl;

			while (l<r)
			{
				int mid=l+r;
				mid/=2;

				//cout<<"@"<<mid<<endl;

				pair<long long, long long> p=get(1,0,n-1,0,mid);
				//cout<<"@"<<mid<<endl;

				if (p.first+doubles+rem_ones*2>=m)
					r=mid;
				else
					l=mid+1;
			}

//			cout<<"@"<<l<<" "<<rem_ones<<endl;

			if (doubles+2*rem_ones==m)
			{
				ans=min(ans,to_pay_already);
			}
			else
			{
				p=get(1,0,n-1,0,l);
				long long to_pay_total=to_pay_already+p.second;
				ans=min(ans,to_pay_total);
			}

			if (doubles<with_mask[3].size())
			{
				PEN2+=with_mask[3][doubles].first;
				int id=with_mask[3][doubles].second;
				int ps=ps_by_id[id];
				kill(1,0,n-1,ps);
			}
		}
	}

	if (ans>1e17)
		ans=-1;

	cout<<ans<<endl;


	cin.get(); cin.get();
	return 0;
}