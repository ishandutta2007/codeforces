#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 200005
#define inf 1073741824
#define eps 1e-10
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int ans=0,a[maxn],fl;
set <int> s,tp2;
vector <int> vec;
map <int,int> p;

inline void dfs(int dep,int val,vector <int> tmp)
{
	if(dep==-1)
	{
		ans=min(ans,val);
		return;
	}
	
	int cnt=0;
	for(int i=0;i<tmp.size();i++) cnt+=(p[tmp[i]&(1<<dep)]==1);
	//cout<<dep<<" "<<cnt<<" "<<tmp.size()<<endl;
	if(cnt==0||cnt==tmp.size()) dfs(dep-1,val,tmp);
	
	else
	{
		//cout<<dep<<" "<<val<<endl;
		vector <int> v1,v2; v1.clear(); v2.clear(); val+=(1<<dep);
		for(int i=0;i<tmp.size();i++)
		{
			if(tmp[i]&(1<<(dep))) v1.push_back(tmp[i]);
			else v2.push_back(tmp[i]);
		}
		dfs(dep-1,val,v1); dfs(dep-1,val,v2);
	}
}

int main()
{
	int n=read(); ans=inf;
	for(int i=0;i<=30;i++) p[(1<<i)]=1;
	for(int i=1;i<=n;i++) a[i]=read(),vec.push_back(a[i]);
	dfs(30,0,vec);
	cout<<ans<<endl;
	return 0;
}