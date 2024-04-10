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
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> v;
		int mx=0,mn=1,xo=0;
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
//			mx=max(mx,x);
			xo^=x;
//			mn=min(mn,x);
			v.pb(x);
		}
		if(xo==1||mn+mx==2)
			puts("NO");
		else if(n%2)
		{
			puts("YES");
			cout<<n-2<<endl;
			for(int i=1;i<n-1;i+=2)
				cout<<i<<" ";
			for(int i=n-4;i>0;i-=2)
				cout<<i<<" ";
			puts("");
		}
		else
		{
			int Xo=0;
			bool flag=true;
			for(int i=0;i<n;i++)
			{
				Xo^=v[i];
//				cout<<i<<" "<<Xo<<endl;
				if(!Xo&&i%2==0)
				{
					puts("YES");
					flag=false;
					vector<int> res;
					int nn=i+1;
//					cout<<nn<<endl;
					for(int j=1;j<nn-1;j+=2)
						res.pb(j);
					for(int j=nn-4;j>0;j-=2)
						res.pb(j);
					for(int j=nn+1;j<n-1;j+=2)
						res.pb(j);
					for(int j=n-4;j>nn;j-=2)
						res.pb(j);
					cout<<sz(res)<<endl;
					for(int j=0;j<sz(res);j++)
						cout<<res[j]<<" ";
					puts("");
					break;
				}
			}
			if(flag)
				puts("NO");
		}
	}
	return 0;
}