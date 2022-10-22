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

char s[maxn];
vector <int> vec;

int main()
{
	int T=read();
	while(T--)
	{
		int n=read(); vec.clear();
		scanf("%s",s+1);
		for(int i=1;i<=n;i++) if(s[i]=='A') vec.push_back(i);
		vec.push_back(n+1);
		int ans=0;
		for(int i=1;i<vec.size();i++) ans=max(ans,vec[i]-vec[i-1]-1);
		cout<<ans<<endl;
	}
	return 0;
}