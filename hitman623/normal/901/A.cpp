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
	int n,c=0,f=1;
	cin>>n;
	vi x(n);
	rep(i,0,n+1){
		cin>>x[i];
		if(i && x[i]!=1 && x[i-1]!=1) 
			f=0;
	}
	if(f)
	{
		cout<<"perfect";
		return;
	}
	cout<<"ambiguous\n";
	int cur=0;
	rep(i,0,n+1){
		rep(j,0,x[i])
			cout<<cur<<" ";
		cur+=x[i];
	}
	cout<<endl;
	cur=0;
	rep(i,0,n+1){
		if(i==0 || x[i]==1 || x[i-1]==1)
		rep(j,0,x[i])
			cout<<cur<<" ";
		else 
		{
			rep(j,0,x[i]-1)
			cout<<cur<<" ";
			cout<<cur-1<<" ";
		}
		cur+=x[i];
	}
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