#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
ll mod=1000000007;
//ll mod=67280421310721;
//ll mod=998244353;
ll INF=1e18;
struct fli
{
	int d;
	int i;
	int c;
};
bool che(fli a,fli b)
{
	if(a.d==b.d)
	{
		if(a.i==b.i)
		return a.c>b.c;
		return a.i>b.i;
	}
	return a.d<b.d;
}
bool che1(fli a,fli b)
{
	if(a.d==b.d)
	{
		if(a.i==b.i)
		return a.c<b.c;
		return a.i<b.i;
	}
	return a.d>b.d;
}
ll mindc[1000005]={0};
ll minac[1000005]={0};
int main()
{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	int test=1;
//	cin>>test;
	while(test--)
	{
//		cout<<'k';
		int n,m,k;
		cin>>n>>m>>k;
		vector<fli> f1,f2;
		int a,b;
		fli tem;
		FOR(i,0,m)
		{
			cin>>tem.d>>tem.i>>b>>tem.c;
			tem.i--;
			if(tem.i==-1)
			{
				tem.i=b-1;
				f2.pb(tem);
			}
			else
			f1.pb(tem);
		}
//		cout<<'k';
		sort(f1.begin(),f1.end(),che);
		sort(f2.begin(),f2.end(),che1);
		
		int dmi[n]={0};
		int c=0;
		ll to=0;
		int j=0;
		FOR(i,0,1000005)
		{
			while(j<f1.size() && f1[j].d==i)
			{
				tem=f1[j];
				if(dmi[tem.i]==0)
				{
					c++;
					to+=tem.c;
					dmi[tem.i]=tem.c;
				}
				else
				{
					to-=dmi[tem.i];
					dmi[tem.i]=min(dmi[tem.i],tem.c);
					to+=dmi[tem.i];
				}
//				cout<<i<<' ';
				j++;
			}
			if(c==n)
			mindc[i]=to;
			else
			mindc[i]=INF;
		}
		
		int ami[n]={0};
		c=0;
		to=0;
		j=0;
		for(int i=1000004;i>=0;i--)
		{
			while(j<f2.size() && f2[j].d==i)
			{
				tem=f2[j];
				if(ami[tem.i]==0)
				{
					c++;
					to+=tem.c;
					ami[tem.i]=tem.c;
				}
				else
				{
					to-=ami[tem.i];
					ami[tem.i]=min(ami[tem.i],tem.c);
					to+=ami[tem.i];
				}
//				cout<<tem.i<<' ';
				j++;
			}
			if(c==n)
			minac[i]=to;
			else
			minac[i]=INF;
		}
		ll ans=INF;
		FOR(i,0,1000001-k)
		{
			ans=min(ans,mindc[i]+minac[i+k+1]);
		}
//		FOR(i,0,20)cout<<mindc[i]<<'\n';
//		cout<<'\n';
//		FOR(i,0,20)cout<<minac[i]<<'\n';
		if(ans>=INF)
		cout<<-1;
		else
		cout<<ans;
	}
	return 0;
}