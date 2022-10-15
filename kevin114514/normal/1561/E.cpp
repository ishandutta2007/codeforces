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
void die(string S){puts(S.c_str());exit(0);}
int x[3030];
int a[3030];
int p[3030];
int n;
vector<int> res;
void Rev(int r)
{
	res.pb(r);
	for(int i=1;i<=r/2;i++)
		swap(a[i],a[r+1-i]);
	for(int i=1;i<=n;i++)
		p[a[i]]=i;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		x[i]=i;
		p[a[i]]=i;
	}
	res.clear();
	for(int i=1;i<=n;i++)
		if((p[i]-i)%2)
		{
			puts("-1");
			return ;
		}
	for(int i=n;i>1;i-=2)
	{
		int x=0;
		for(int j=1;j<=n;j++)
			if(a[j]==i)
				x=j;
		Rev(x);
		for(int j=1;j<=n;j++)
			if(a[j]==i-1)
				x=j;
		Rev(x-1);
		Rev(x+1);
		Rev(3);
		Rev(i);
	}
//	cout<<sz(res)<<endl;
	int P=0;
	vector<int> v;
	while(P<sz(res))
	{
		if(P<sz(res)-1)
			if(res[P]==res[P+1])
			{
				P+=2;
				continue;
			}
		if(res[P]>1)
			v.pb(res[P]);
		P++;
	}
//	rev(res);
	cout<<sz(v)<<endl;
	for(int i=0;i<sz(v);i++)
		cout<<v[i]<<" ";
	puts(""); 
}
int main()
{
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}