#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
#define sz(x) (int)(x.size())
void die(string S=""){puts(S.c_str());exit(0);}
vector<int> v;
map<int,bool> Mp;
int a[2020],n,s;
int st[2020],nd[2020];
int lf[2020],rf[2020];
int _prev[2020];
vector<int> G[2020];
//O(N) version
int main()
{
	memset(_prev,-1,sizeof(_prev));
	cin>>n>>s;
	s--;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(!Mp[a[i]])
			v.pb(a[i]);
		Mp[a[i]]=1;
	}
	int c=sz(v);
	srt(v);
	for(int i=0;i<n;i++)
		a[i]=lower_bound(ALL(v),a[i])-v.begin();
	for(int i=0;i<2020;i++)
		st[i]=nd[i]=1e9;
	for(int i=0;i<n;i++)
		G[a[i]].pb(i);
	for(int i=0;i<c;i++)
		srt(G[i]);
	for(int i=0;i<c;i++)
		for(int j=0;j<sz(G[i]);j++)
			lf[G[i][j]]=G[i][(j-1+sz(G[i]))%sz(G[i])],
			rf[G[i][(j-1+sz(G[i]))%sz(G[i])]]=G[i][j];
	for(int i=0;i<n;i++)
		if(!a[i])
			st[i]=min(abs(s-i),n-abs(s-i));
	for(int color=0;color<c;color++)
	{
		for(int j=0;j<sz(G[color]);j++)
		{
			int i=G[color][j];
			if(lf[i]==i)
				nd[i]=min(nd[i],st[i]);
			else
			{
				nd[lf[i]]=min(nd[lf[i]],st[i]+n-(i+n-lf[i])%n);
				nd[rf[i]]=min(nd[rf[i]],st[i]+n-(rf[i]+n-i)%n);
			}
		}
		vector<pair<int,int> > val;
		for(int i=0;i<sz(G[color]);i++)
			val.pb(mp(G[color][i],0));
		for(int i=0;i<sz(G[color+1]);i++)
			val.pb(mp(G[color+1][i],1));
		int tmp=sz(val);
		srt(val);
		for(int i=0;i<tmp;i++)
			val.pb(mp(val[i].first,val[i].second));
		int mn=1e9;
		int _tmp=0;
		for(int j=0;j<tmp+tmp;j++)
		{
			int i=val[j].first;
			if(!val[j].second)
			{
				if(nd[i]<mn+(j?(val[j].first-val[j-1].first+n)%n:0))
					_tmp=i;
				mn=min(mn+(j?(val[j].first-val[j-1].first+n)%n:0),nd[i]);
			}
			else mn+=(j?(val[j].first-val[j-1].first+n)%n:0);
			if(val[j].second)
			{
				if(mn<st[i])
				{
					st[i]=mn;
					_prev[i]=_tmp;
				}
			}
		}
		mn=1e9;
		_tmp=0;
		for(int j=tmp+tmp-1;j>=0;j--)
		{
			int i=val[j].first;
			if(!val[j].second)
			{
				if(nd[i]<mn+(j<tmp+tmp-1?(val[j+1].first-val[j].first+n)%n:0))
					_tmp=i;
				mn=min(mn+(j<tmp+tmp-1?(val[j+1].first-val[j].first+n)%n:0),nd[i]);
			}
			else mn+=(j<tmp+tmp-1?(val[j+1].first-val[j].first+n)%n:0);
			if(val[j].second)
			{
				if(mn<st[i])
				{
					st[i]=mn;
					_prev[i]=_tmp;
				}
			}
		}
	}
	
	int ans=1e9;
	int lst=0;
	for(int i=0;i<n;i++)
		if(a[i]==c-1)
			if(nd[i]<ans)
			{
				ans=nd[i];
				lst=i;
			}
	cout<<ans<<endl;
	vector<int> v1;
//	cout<<lst<<endl;
	for(int color=c-1;color>=0;color--)
	{
		if(lf[lst]!=lst)
		{
			if(nd[lst]==st[lf[lst]]+n-(lst-lf[lst]+n)%n)
			{
				int finish=lf[lst];
				while(lst!=finish)
				{
					v1.pb(lst-rf[lst]);
					lst=rf[lst];
//					cout<<lst<<endl;
				}
			}
			else
			{
				int finish=rf[lst];
				while(lst!=finish)
				{
					v1.pb(lst-lf[lst]);
					lst=lf[lst];
//					cout<<lst<<endl;
				}
			}
		}
		if(!color)
		{
			v1.pb(lst-s);
			break;
		}
		int i=_prev[lst];
		v1.pb(lst-i);
		lst=i;
	}
	rev(v1);
	for(int i=0;i<sz(v1);i++)
		if(abs(v1[i])>n-abs(v1[i]))
		{
			if(v1[i]<0)
				v1[i]+=n;
			else	v1[i]-=n;
		}
	for(int i=0;i<sz(v1);i++)
	{
		if(v1[i]>=0)
			cout<<"+";
		cout<<v1[i]<<endl;
	}
	return 0;
}
/*
20 7
0 6 0 0 0 -7 -8 9 -7 4 7 2 -4 4 -5 2 6 8 -2 -7
8 169 1011 3  1    215 18 12 614  5 1317   7  4    */