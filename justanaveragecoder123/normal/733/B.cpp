#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

#define mp make_pair
#define xx first
#define yy second
#define pb push_back
#define sz(x) (int)((x).size())

int main() {
	int n;cin>>n;
	vector<pair<int,int>> t;
	int L=0,R=0;
	for(int i=0;i<n;++i)
	{
		int l,r;cin>>l>>r;
		t.pb({l,r});
		L+=l;
		R+=r;
	}
	int ans=abs(R-L), ansi=0;
	for(int i=0;i<n;++i)
	{
		L-=t[i].xx;
		R+=t[i].xx;
		R-=t[i].yy;
		L+=t[i].yy;
		
		if(abs(R-L)>ans)
		{
			ans=abs(R-L);
			ansi=i+1;
		}
		
		L+=t[i].xx;
		R-=t[i].xx;
		R+=t[i].yy;
		L-=t[i].yy;
	}
	
	cout<<ansi<<"\n";
	return 0;
}