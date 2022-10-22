#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 200005
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

string s[2005];
map <string,int> mp;

int main()
{
	int n=read(),k=read();
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		for(int j=0;j<s[i].length();j++)
			if(s[i][j]=='S') s[i][j]='1';
			else if(s[i][j]=='E') s[i][j]='2';
			else if(s[i][j]=='T') s[i][j]='3';
		mp[s[i]]++;
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		string s1;
		for(int j=i+1;j<=n;j++)
		{
			s1.clear();
			for(int p=0;p<k;p++)
			{
				if(s[i][p]==s[j][p]) s1.push_back(s[i][p]);
				else
				{
					int tmp=(6-(s[i][p]-'0')-(s[j][p]-'0'));
					s1.push_back(tmp+'0');
				}
			}
			if(s1==s[i]) ans--;
			if(s1==s[j]) ans--;
			ans+=mp[s1];
		}
		mp[s[i]]--;
	}
	cout<<ans/2<<endl;
	return 0;
}