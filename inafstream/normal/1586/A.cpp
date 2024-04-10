#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define per(i,n) for ((i)=n;(i)>=(1);(i)--)
using namespace std;

int n,i,f[105][20005],pre[105][20005],a[105];

vector<int> res;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		cin>>n;
		memset(f,-0x3f,sizeof(f));
		f[0][0]=0;
		rep(i,n)
		{
			int x,j;
			cin>>x;a[i]=x;
			for(j=20000;j>=0;j--)
			{
				if(j<x||f[i-1][j]>f[i-1][j-x]+1)
				{
					f[i][j]=f[i-1][j];
					pre[i][j]=0;
				}
				else
				{
					f[i][j]=f[i-1][j-x]+1;
					pre[i][j]=1;
				}
			}
		}
		
		int ans=0,s=0;
		rep(i,20000)if(f[n][i]>ans)
		{
			bool fl=0;
			int j;
			for(j=2;j*j<=i;j++)
			{
				if(i%j==0)
				{
					fl=1;break;
				}
			}
			if(fl)
			{
				ans=f[n][i];
				s=i;
			}
		}
		
		res.clear();
		for(i=n;i>=1;i--)
		{
			if(pre[i][s])
			{
				s-=a[i];
				res.push_back(i);
			}
		}
		
		printf("%d\n",res.size());
		rep(i,res.size()) printf("%d ",res[i-1]);
		puts("");
	}
	return 0;
}