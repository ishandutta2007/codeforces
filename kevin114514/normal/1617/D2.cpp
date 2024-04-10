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
	vector<int> v;
	if(imp[a]!=2)
		v.pb(imp[a]);
	if(imp[b]!=2)
		v.pb(imp[b]);
	if(imp[c]!=2)
		v.pb(imp[c]);
	if(sz(v)==3)
		return (imp[a]+imp[b]+imp[c])/2;
	else if(sz(v)==2&&v[0]==v[1])
		return v[0];
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
		int im=1,cr=n;
		for(int i=1;i<=n;i+=3)
			sta[i]=query(md(i),md(i+1),md(i+2));
		for(int i=1;i<=n;i+=3)
			if(sta[i]!=sta[md(i+3)])
			{
				for(int j=i+1;j<=i+2;j++)
					sta[md(j)]=query(md(j),md(j+1),md(j+2));
				for(int j=i;j<=i+2;j++)
					if(sta[md(j)]!=sta[md(j+1)])
					{
						imp[md(j)]=sta[md(j)];
						imp[md(j+3)]=sta[md(j+1)];
						if(!imp[md(j)])
						{
							im=md(j);
							cr=md(j+3);
						}
						else
						{
							im=md(j+3);
							cr=md(j);
						}
						break;
					}
				break;
			}
		for(int i=1;i<=n;i+=3)
			if(!sta[i])
			{
				int status=query(cr,md(i),md(i+1));
				if(!status)
				{
					imp[md(i)]=imp[md(i+1)]=0;
					imp[md(i+2)]=query(im,cr,md(i+2));
				}
				else
				{
					imp[md(i)]=query(md(i),im,cr);
					imp[md(i+1)]=1-imp[md(i)];
					imp[md(i+2)]=0;
				}
			}
			else
			{
				int status=query(im,md(i),md(i+1));
				if(status)
				{
					imp[md(i)]=imp[md(i+1)]=1;
					imp[md(i+2)]=query(im,cr,md(i+2));
				}
				else
				{
					imp[md(i)]=query(md(i),im,cr);
					imp[md(i+1)]=1-imp[md(i)];
					imp[md(i+2)]=1;
				}
			}
		answer();
	}
	return 0;
}