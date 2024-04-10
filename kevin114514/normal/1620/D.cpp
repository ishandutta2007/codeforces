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
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		vector<int> v;
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			v.pb(x);
		}
		int ans=inf;
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
			{
				vector<int> u;
				for(int ii=0;ii<=i;ii++)
					for(int jj=0;jj<=j;jj++)
						u.pb(ii+jj+jj);
//				bool flg=1;
				int mx=0;
				for(auto x:v)
				{
//					bool f=0;
					int mn=inf;
					for(auto y:u)
						if(y<=x&&(x-y)%3==0)
						{
//							f=1;
							mn=min(mn,(x-y+2)/3);
						}
					mx=max(mx,mn);
				}
				ans=min(ans,i+j+mx);
			}
		cout<<ans<<endl;
	}
	return 0;
}