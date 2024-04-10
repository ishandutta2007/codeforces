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

string s;
int ans;

inline bool check(int x,int y)
{
	int len=y-x+1;
	for(int i=0;i<len;i++)
		if(s[y-i]!=s[x+i]) return true;
	return false;
}

int main()
{
	cin>>s; int len=s.length();
	for(int i=0;i<len;i++)
		for(int j=i+1;j<len;j++)
			if(check(i,j)) ans=max(ans,j-i+1);
	cout<<ans;
	return 0;
}