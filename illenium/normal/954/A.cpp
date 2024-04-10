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
#define maxn 200005
#define re register
#define inf 1e9
#define eps 1e-10
using namespace std;

int n,ans;
char ch[maxn];

int main()
{
	cin>>n;
	ans=n;
	scanf("%s",ch+1);
	for(int i=2;i<=n;i++)
	{
		if(ch[i]=='U'&&ch[i-1]=='R') ans--,i++;
		else if(ch[i]=='R'&&ch[i-1]=='U') ans--,i++;
	}
	cout<<ans;
	return 0;
}