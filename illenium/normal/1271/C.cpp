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

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

vector <int> ans1,ans2,ans3,ans4;

int main()
{
	int n=read(),tx=read(),ty=read();
	for(int i=1;i<=n;i++)
	{
		int x=read(),y=read();
		if(y<ty) ans1.push_back(i);
		if(y>ty) ans2.push_back(i);
		if(x>tx) ans3.push_back(i);
		if(x<tx) ans4.push_back(i);
	}
	int f=0,ans=0;
	if(ans1.size()>ans) f=1,ans=ans1.size();
	if(ans2.size()>ans) f=2,ans=ans2.size();
	if(ans3.size()>ans) f=3,ans=ans3.size();
	if(ans4.size()>ans) f=4,ans=ans4.size();
	if(f==1)
	{
		cout<<ans1.size()<<endl;
		cout<<tx<<" "<<ty-1;
	}
	else if(f==2)
	{
		cout<<ans2.size()<<endl;
		cout<<tx<<" "<<ty+1;
	}
	else if(f==3)
	{
		cout<<ans3.size()<<endl;
		cout<<tx+1<<" "<<ty;
	}
	else if(f==4)
	{
		cout<<ans4.size()<<endl;
		cout<<tx-1<<" "<<ty;
	}
	return 0;
}