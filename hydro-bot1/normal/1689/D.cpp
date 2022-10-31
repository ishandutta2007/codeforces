#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)
	{
		int n,m;
		cin>>n>>m;
		vector<int> mxd(4,-1e9);
		for(int i=1;i<=n;i++)
		{
			string s;
			cin>>s;
			for(int j=1;j<=m;j++)
			{
				if(s[j-1]=='B')
				{
					mxd[0]=max(mxd[0],i+j);
					mxd[1]=max(mxd[1],-i+j);
					mxd[2]=max(mxd[2],i-j);
					mxd[3]=max(mxd[3],-i-j);
				}
			}
		}
//		for(int i=0;i<4;i++)cerr<<i<<' '<<mxd[i]<<endl;
		pair<int,int> ans{0,0};
		int dis=1e9;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				int d=max({abs(mxd[0]-(i+j)),abs(mxd[1]-(-i+j)),abs(mxd[2]-(i-j)),abs(mxd[3]-(-i-j))});
//				cerr<<i<<' '<<j<<' '<<d<<endl;
				if(d<dis)
				{
//					cerr<<i<<' '<<j<<' '<<d<<endl;
					ans=make_pair(i,j);
					dis=d;
				}
			}
		}
		cout<<ans.first<<' '<<ans.second<<endl;
	}
	
	return 0;
}