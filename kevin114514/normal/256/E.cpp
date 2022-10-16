#include<bits/stdc++.h>
using namespace std;
const long long mod=777777777;
const int delta=131072;
long long dp[262144][4][4];
int val[100100];
bool ok[4][4];
void fresh(int x,int l,int r)
{
	if(l==r)
	{
		dp[x][1][1]=dp[x][2][2]=dp[x][3][3]=true;
		return ;
	}
	else
	{
		int mid=(l+r)/2;
		fresh(x+x,l,mid);
		fresh(x+x+1,mid+1,r);
		for(int c1=1;c1<=3;c1++)
		for(int c2=1;c2<=3;c2++)
		for(int c3=1;c3<=3;c3++)
		for(int c4=1;c4<=3;c4++)
			if(ok[c2][c3])
				dp[x][c1][c4]=(dp[x][c1][c4]+dp[x+x][c1][c2]*dp[x+x+1][c3][c4]%mod)%mod;
	}
}
void refresh(int x,int l,int r,int p,int v)
{
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			dp[x][i][j]=0;
	if(l==r)
	{
		if(!v)
			dp[x][1][1]=dp[x][2][2]=dp[x][3][3]=true;
		else	dp[x][v][v]=true;
		return ;
	}
	else
	{
		int mid=(l+r)/2;
		if(p<=mid)
		refresh(x+x,l,mid,p,v);
		else
		refresh(x+x+1,mid+1,r,p,v);
		for(int c1=1;c1<=3;c1++)
		for(int c2=1;c2<=3;c2++)
		for(int c3=1;c3<=3;c3++)
		for(int c4=1;c4<=3;c4++)
			if(ok[c2][c3])
				dp[x][c1][c4]=(dp[x][c1][c4]+dp[x+x][c1][c2]*dp[x+x+1][c3][c4]%mod)%mod;
	}
}
int count(int c1,int c2)
{
	if(!c1)
		return ((count(1,c2)+count(2,c2))%mod+count(3,c2))%mod;
	if(!c2)
		return ((count(c1,1)+count(c1,2))%mod+count(c1,3))%mod;
	return dp[1][c1][c2];
}
int main()
{
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
			cin>>ok[i][j];
	fresh(1,1,n);
	while(q--)
	{
		int p,v;
		cin>>p>>v;
		refresh(1,1,n,p,v);
		val[p]=v;
		cout<<count(val[1],val[n])<<endl;
	}
	return 0;
}