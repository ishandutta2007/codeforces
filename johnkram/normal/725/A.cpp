#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define ll long long
#define MAXN 200005
int n,i,ans;
char s[MAXN];
int main()
{
	scanf("%d%s",&n,s+1);
	for(i=1;i<=n;i++)if(s[i]=='>')break;
	ans+=i-1;
	for(i=n;i;i--)if(s[i]=='<')break;
	ans+=n-i;
	cout<<ans<<endl;
	return 0;
}