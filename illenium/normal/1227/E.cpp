#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#define ll long long
#define maxn 1000005
#define re register
#define inf 1e9
#define eps 1e-10
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int n,m,ans2;
vector <vector <int> > mp,sum,tmp1,tmp2,ans,sum2,tmp4;
char s[maxn];

inline int gets1(int a,int b,int c,int d)
{
	return sum[c][d]-sum[c][b-1]-sum[a-1][d]+sum[a-1][b-1];
}

inline bool jud(int x)
{
	for(int i=0;i<=n;i++) for(int j=0;j<=m;j++)
		tmp1[i][j]=0,tmp4[i][j]=0,tmp2[i][j]=0,sum2[i][j]=0;
	for(int i=x+1;i+x<=n;i++)
	{
		for(int j=x+1;j+x<=m;j++)
		{
			if(gets1(i-x,j-x,i+x,j+x)==(2*x+1)*(2*x+1)) tmp1[i][j]=1;
		}
	}
	for(int i=x+1;i+x<=n;i++)
	{
		for(int j=x+1;j+x<=m;j++)
		{
			if(tmp1[i][j]==1)
			{
				tmp2[i+x+1][j+x+1]++;
				tmp2[i+x+1][j-x]--;
				tmp2[i-x][j+x+1]--;
				tmp2[i-x][j-x]++;
			}
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//			cout<<tmp2[i][j]<<" ";
//		cout<<endl;
//	}
//	cout<<endl;
	//cout<<x<<" "<<n<<" "<<m<<endl;
	for(int i=1;i<=n;i++)
	{
		int tmp3=0;
		for(int j=1;j<=m;j++)
		{
			tmp3+=tmp2[i][j];
			sum2[i][j]=sum2[i-1][j]+tmp3; //cout<<sum2[i][j]<<" ";
		}
		//cout<<endl;
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(sum2[i][j]!=0) tmp4[i][j]=1;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(tmp4[i][j]!=mp[i][j]) return false;
	return true;
}

int main()
{
	n=read(); m=read();
	vector <int> v;
	for(int i=0;i<=m+1;i++) v.push_back(0);
	mp.push_back(v);
	for(int i=1;i<=n;i++)
	{
		vector <int> vec; vec.clear(); vec.push_back(0);
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)
		{
			if(s[j]=='X') vec.push_back(1);
			else vec.push_back(0);
		}
		vec.push_back(0);
		mp.push_back(vec);
	}
	mp.push_back(v);
	for(int i=0;i<=n+1;i++)
		sum.push_back(v),tmp1.push_back(v),tmp4.push_back(v),
		sum2.push_back(v),ans.push_back(v),tmp2.push_back(v);
	for(int i=1;i<=n;i++)
	{
		int tmp=0;
		for(int j=1;j<=m;j++)
		{
			tmp+=mp[i][j];
			sum[i][j]=sum[i-1][j]+tmp;
		}
	}
	int l=0,r=min(n,m);
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(jud(mid))
		{
			for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) ans[i][j]=tmp1[i][j];
			l=mid+1; ans2=mid;
		}
		else r=mid-1;
	}
	cout<<ans2<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			if(ans[i][j]==1) printf("X");
			else printf(".");
		puts("");
	}
	return 0;
}