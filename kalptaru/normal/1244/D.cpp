#include <bits/stdc++.h>
#include <string>
#include <cmath>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
ll mod=1000000007;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t=1;
//	cin>>t;
	while ( t-- ) 
	{
		int n,u,v;
		cin>>n;
		ll c1[n],c2[n],c3[n];
		FOR(i,0,n)
		cin>>c1[i];
		FOR(i,0,n)
		cin>>c2[i];
		FOR(i,0,n)
		cin>>c3[i];
		vector<int > tree[n];
		FOR(i,1,n)
		{
			cin>>u>>v;
			tree[u-1].pb(v-1);
			tree[v-1].pb(u-1);
		}
		int o=-1;
		FOR(i,0,n)
		{
			if(tree[i].size()==1 && o==-1)
			o=i;
			if(tree[i].size()>2)
			{
				cout<<-1;
				return 0;
			}
		}
//cout<<o<<"scwedf\n";
		int pos[n],p=-1;//poa[n];
		ll a[3]={0},ar[3]={0};
		FOR(i,0,n)
		{
//			cout<<o<<' ';
			a[i%3]+=c1[o];
			a[(1+i)%3]+=c2[o];
			a[(2+i)%3]+=c3[o];
			ar[(300000-i)%3]+=c1[o];
			ar[(300000-i+1)%3]+=c2[o];
			ar[(300000-i+2)%3]+=c3[o];
			pos[o]=i%3;
//			poa[o]=(n-i)%3;
			if(tree[o][0]==p && i<n-1)
			{
				p=o;
				o=tree[o][1];
			}
			else
			{
				p=o;
				o=tree[o][0];
			}
		}
		ll m=1e18;
		FOR(i,0,3)
		{
			if(a[i]<m)
			{
				m=a[i];
				o=3+i;
			}
		}
		bool f=1;
		FOR(i,0,3)
		{
			if(ar[i]<m)
			{
				m=ar[i];
				o=i;
				f=0;
//				cout<<o;
			}
		}
		cout<<m<<'\n';
		if(f)
		{
			FOR(i,0,n)
			{
				cout<<(o-pos[i])%3+1<<' ';
			}
			return 0;
		}
		FOR(i,0,n)
		{
			cout<<(pos[i]+o)%3+1<<' ';
		}
//		cout<<o;
	}
	return 0;
}