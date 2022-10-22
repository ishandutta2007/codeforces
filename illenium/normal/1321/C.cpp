#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
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

string s;
int vis[maxn],ans;

int main()
{
	int n=read(); cin>>s;
	for(int j=25;j>=1;j--)
	{
		for(int T=1;T<=100;T++)
		{
			string tmp="";
			for(int i=0;i<s.length();i++)
			{
				if(s[i]-'a'==j)
				{
					if(i!=0&&s[i-1]-'a'==j-1) vis[i]=1;
					if(i!=s.length()&&s[i+1]-'a'==j-1) vis[i]=1;
				}
			}
			for(int i=0;i<s.length();i++)
			{
				if(vis[i]==0) tmp+=s[i];
				else ans++; vis[i]=0;
			}
			s=tmp; //cout<<tmp<<endl;
		}
		
	}
	cout<<ans<<endl;
	return 0;
}