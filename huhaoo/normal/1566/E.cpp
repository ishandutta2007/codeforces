#include<bits/stdc++.h>
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
#define i64 long long
int read()
{
	int r=0,t=1,c=getchar();
	while(c<'0'||c>'9'){ t=c=='-'?-1:1; c=getchar(); }
	while(c>='0'&&c<='9'){ r=(r<<3)+(r<<1)+(c^48); c=getchar(); }
	return r*t;
}
const int N=200010;
int n;
int c1,c2;
std::vector<int> e[N];
int dfs(int u,int f)
{
	int c=0;
	for(auto v:e[u]) if(v!=f) c+=dfs(v,u);
	if(c){ c1++; c2+=c; return 0; }
	else return 1;
}
int main()
{
	fr(T,1,read())
	{
		n=read(); c1=c2=0;
		fr(i,1,n) e[i].clear();
		fr(i,1,n-1){ int u=read(),v=read(); e[u].push_back(v); e[v].push_back(u); }
		printf("%d\n",dfs(1,0)?c2-(c1-1):c2-(c1-1));
	}
	return 0;
}