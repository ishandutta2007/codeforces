#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000005
int n,i,f[MAXN];
char s[MAXN],t[MAXN];
int main()
{
	scanf("%d%s%s",&n,s+1,t+1);
	for(i=1;i<=n;i++)
	{
		f[i]=f[i-1]+(s[i]^t[i]);
		if(i>1&&s[i]==t[i-1]&&t[i]==s[i-1])f[i]=min(f[i],f[i-2]+1);
	}
	cout<<f[n]<<endl;
	return 0;
}