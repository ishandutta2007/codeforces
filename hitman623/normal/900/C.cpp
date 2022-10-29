#include "bits/stdc++.h"
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
	int n;
	cin>>n;
	set<int>s;
	vi p(n),d(n);
	rep(i,0,n){
		cin>>p[i];
		d[i]=p[i];
		s.insert(d[i]);
	}
	rep(i,0,n){
		if(i)
		d[i]=max(d[i-1],p[i]);
	}
	int in=0,ans=0,num;
	while(in<n)
	{
		int g=d[in],cur,cnt=-1;
		if(in==0) cur=0;
		else cur=d[in-1];
		in++;
		while(d[in]==g){
			if(p[in]>cur)
				cur=p[in],cnt++;
			in++;
		}
		if(ans<cnt)
			ans=cnt,num=g;
		else if(ans==cnt) num=min(num,g);
	}
	if(ans==0){
		rep(i,0,n)
			if(p[i]!=i+1)
				{cout<<i+1;return;}
		cout<<1;
	}
	else 
		cout<<num;
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