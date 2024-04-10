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

int n,m,pos[maxn],cnt;
map <int,int> p;
vector <int> ans;
ll tmp;
set <int> s,tmp2;

int main()
{
	n=read(); m=read();
	for(int i=1;i<=n;i++) pos[i]=read(),p[pos[i]]=1,s.insert(pos[i]);
	for(int i=1;cnt<m;i++)
	{
		tmp2=s;
		for(set <int>::iterator it=s.begin();it!=s.end();it++)
		{
			int tp=*it;
			if(p[tp+i]&&p[tp-i]) tmp2.erase(tp);
			else
			{
				if(p[tp+i]==0) p[tp+i]=1,cnt++,ans.push_back(tp+i),tmp+=i;
				if(cnt==m) break;
				if(p[tp-i]==0) p[tp-i]=1,cnt++,ans.push_back(tp-i),tmp+=i;
				if(cnt==m) break;
			}
			//cout<<tp<<" "<<cnt<<" "<<s.size()<<endl;
		}
		s=tmp2;
	}
	cout<<tmp<<endl;
	for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
	return 0;
}