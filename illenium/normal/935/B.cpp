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

int main()
{
	int n; cin>>n;
	string s; cin>>s;
	int x=0,y=0,ans=0;
	if(s[0]=='R') y++;
	else x++;
	for(int i=1;i<n;i++)
	{
		if(s[i]=='R')
		{
			if(x==y&&s[i]==s[i-1]) ans++;
			y++;
		}
		else
		{
			if(x==y&&s[i]==s[i-1]) ans++;
			x++;
		}
	}
	cout<<ans;
	return 0;
}