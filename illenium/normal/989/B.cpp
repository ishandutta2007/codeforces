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
	int n,p;
	string s;
	cin>>n>>p>>s;
	int f=0;
	for(int i=0;i+p<n;i++)
	{
		if(s[i]!='.'&&s[i+p]!='.')
			{
				if(s[i]!=s[i+p]) f=1;
			}
			else
			{
				f=1;
				if(s[i]=='.')s[i]=(s[i+p]=='0'?'1':'0');
				if(s[i+p]=='.')s[i+p]=('0'+(1-(s[i]-'0')));
			}
	}
	if(f)
	{
		for(int i=0;i<n;i++)if(s[i]=='.')s[i]='1'; cout<<s;
	}
	else cout<<"No";
}