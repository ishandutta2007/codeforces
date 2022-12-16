#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
const int N=300005,E=524288;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
int n,i,m;
long long f[3005][3005][2];
char a[N],b[N];
long long dfs(int i,int j,int fg)
{
	if(i==0)
		return 1;
	if(f[i][j][fg]!=-1)
		return f[i][j][fg];
	f[i][j][fg]=0;
	if(j>m||a[i]==b[j])
		if(fg)
			f[i][j][fg]+=dfs(i-1,j+1,0)*(n-i+1);
		else
			f[i][j][fg]+=dfs(i-1,j+1,0);
	if(i+j-1>m)
		f[i][j][fg]+=dfs(i-1,j,fg);
	else
	{
		if(a[i]==b[i+j-1])
			if(fg)
				f[i][j][fg]+=dfs(i-1,j,0)*(n-i+1);
			else
				f[i][j][fg]+=dfs(i-1,j,0);
	}
	f[i][j][fg]%=M;
	return f[i][j][fg];
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%s",a+1);
	scanf("%s",b+1);
	n=strlen(a+1),m=strlen(b+1);
	memset(f,-1,sizeof(f));
	cout<<(dfs(n,1,1)%M+M)%M;
}