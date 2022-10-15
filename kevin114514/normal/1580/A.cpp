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
int grid[440][440];
int rsum[440][440];
int csum[440][440];
int psum[440][440];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			string S;
			cin>>S;
			for(int j=1;j<=m;j++)
			{
				grid[i][j]=S[j-1]-'0';
				rsum[i][j]=rsum[i][j-1]+grid[i][j];
				csum[i][j]=csum[i-1][j]+grid[i][j];
				psum[i][j]=psum[i-1][j]+psum[i][j-1]-psum[i-1][j-1]+grid[i][j];
			}
		}
		int res=1e9;
		for(int l=1;l<=m;l++)
			for(int r=l+3;r<=m;r++)
			{
				int mn=1e9;
				int ans=1e9;
				for(int i=1;i<=n;i++)
				{
					if(i>=5)
					{
						int tmp=(r-l-1)-(rsum[i-4][r-1]-rsum[i-4][l]);
//						cout<<tmp<<endl;
						tmp+=psum[i-1][r-1]-psum[i-4][r-1]-psum[i-1][l]+psum[i-4][l];
//						cout<<tmp<<endl;
						tmp+=3-(csum[i-1][l]-csum[i-4][l]);
//						cout<<tmp<<endl;
						tmp+=3-(csum[i-1][r]-csum[i-4][r]);
//						cout<<tmp<<endl;
						mn=min(mn,tmp);
					}
					ans=min(ans,mn+(r-l-1)-(rsum[i][r-1]-rsum[i][l]));
//					cout<<i<<" "<<l<<" "<<r<<" "<<ans<<endl;
					mn+=rsum[i][r-1]-rsum[i][l];
					mn+=(1-grid[i][r]);
					mn+=(1-grid[i][l]); 
				}
				res=min(res,ans);
			}
		cout<<res<<endl;
	}
	return 0;
}