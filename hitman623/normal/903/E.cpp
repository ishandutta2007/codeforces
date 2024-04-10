#include "bits/stdc++.h"

#ifdef PRINTERS
#include "printers.hpp"
using namespace printers;
#define tr(a)		cerr<<#a<<" : "<<a<<endl
#else
#define tr(a)    
#endif

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii 		vector<pii>
#define mi 			map<int,int>
#define mii			map<int,pii>	
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)	for(int i=a;i<b;i++)
using namespace std;
void solve()
{
	vector<string> s;
	int k,n,good=1;
	cin>>k>>n;
	rep(i,0,k)
	{
		string temp;
		cin>>temp;
		int g=0;
		rep(j,0,sz(s))
		if(s[j]==temp) g=1;	
		if(!g) s.pb(temp);
	}
	rep(i,0,sz(s))
		rep(j,i+1,sz(s))
		{
			string t1=s[i];
			string t2=s[j];
			sort(all(t1));
			sort(all(t2));
			if(t1!=t2) good=0;
		}
	if(!good) {cout<<-1;return;}
	int v[26]={0},ans=0,flag=0;
	rep(i,0,n)
		{
			v[s[0][i]-'a']++;
			if(v[s[0][i]-'a']>1) flag=1;
		}
	if(sz(s)==1)
	{
		swap(s[0][1],s[0][0]);
		cout<<s[0];
		return;
	}
	int p1;
	rep(i,0,n)
		if(s[0][i]!=s[1][i]){
			p1=i;
			break;
		}
	rep(i,0,n)
	{
		if(i==p1) continue;
		int f=1;
		string temp=s[0];
		swap(temp[p1],temp[i]);		
		set<pii> st;
		rep(j,0,sz(s))
		{
			int cnt=0;
			vi vv;
			if(s[j]==temp) 
			{
				if(!flag){
					f=0;
					break;
				}
				continue;
			}
			rep(l,0,n)
			if(s[j][l]!=temp[l])
			vv.pb(l);
			if(sz(vv)>2) {f=0;break;}
			if(st.count({vv[0],vv[1]}))
				{f=0;break;}
			st.insert({vv[0],vv[1]});
			st.insert({vv[1],vv[0]});
		}
		if(!f) continue;
		cout<<temp;
		return;
	}
	swap(s[0],s[1]);
	rep(i,0,n)
	{
		if(i==p1) continue;
		int f=1;
		string temp=s[0];
		swap(temp[p1],temp[i]);		
		set<pii> st;
		rep(j,0,sz(s))
		{
			int cnt=0;
			vi vv;
			if(s[j]==temp) 
			{
				if(!flag){
					f=0;
					break;
				}
				continue;
			}
			rep(l,0,n)
			if(s[j][l]!=temp[l])
			vv.pb(l);
			if(sz(vv)>2) {f=0;break;}
			if(st.count({vv[0],vv[1]}))
				{f=0;break;}
			st.insert({vv[0],vv[1]});
			st.insert({vv[1],vv[0]});
		}
		if(!f) continue;
		cout<<temp;
		return;
	}
	cout<<-1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)
		solve();
	return 0;
}