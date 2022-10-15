#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
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
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define lb(v,x) (lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (upper_bound(ALL(v),x)-v.begin())
void die(string S){puts(S.c_str());exit(0);}
int imp[10100];
int sta[10100];
int n;
int query(int a,int b,int c)
{
	cout<<"? "<<a<<" "<<b<<" "<<c<<endl;
	fflush(stdout);
	int x;
	cin>>x;
	if(x==-1)
		exit(114514);
	return x;
}
void answer()
{
	vector<int> v;
	for(int i=1;i<=n;i++)
		if(!imp[i])
			v.pb(i);
	cout<<"! "<<sz(v)<<" ";
	for(auto x:v)
		cout<<x<<" ";
	puts("");
	fflush(stdout);
}
int md(int x)
{
	return (x-1+n)%n+1;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			imp[i]=2;
		for(int i=1;i<=n;i++)
			sta[i]=query(md(i),md(i+1),md(i+2));
		for(int i=1;i<=n;i++)
			if(sta[i]!=sta[md(i+1)])
				imp[i]=sta[i],
				imp[md(i+3)]=sta[md(i+1)];
		int n0=1,n1=n;
		for(int i=1;i<=n;i++)
			if(imp[i]==0)
				n0=i;
			else if(imp[i]==1)
				n1=i;
		for(int i=1;i<=n;i++)
			if(imp[i]==2)
				imp[i]=query(i,n0,n1);
		answer();
	}
	return 0;
}