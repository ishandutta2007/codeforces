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

int mp[30][30],vis[30],v2[30];
char s[maxn];
vector <int> p[30];
vector <int> ans;

inline void wk(int u)
{
	ans.push_back(u); v2[u]=1;
	for(int i=0;i<p[u].size();i++)
	{
		int v=p[u][i];
		if(v2[v]) continue; wk(v);
	}
}

int main()
{
	int T=read();
	while(T--)
	{
		scanf("%s",s+1); int len=strlen(s+1);
		for(int i=0;i<=25;i++) vis[i]=0,p[i].clear(),v2[i]=0;
		for(int i=0;i<=25;i++) for(int j=0;j<=25;j++) mp[i][j]=0;
		int f=0;
		for(int i=2;i<=len;i++)
		{
			if(s[i]==s[i-1]) continue;
			if(vis[s[i]-'a']&&vis[s[i-1]-'a'])
			{
				if(mp[s[i]-'a'][s[i-1]-'a']==0) {f=1; break;}
				else continue;
			}
			vis[s[i]-'a']=1; vis[s[i-1]-'a']=1;
			mp[s[i]-'a'][s[i-1]-'a']=1;
			mp[s[i-1]-'a'][s[i]-'a']=1;
			p[s[i]-'a'].push_back(s[i-1]-'a');
			p[s[i-1]-'a'].push_back(s[i]-'a');
		}
		//for(int i=0;i<=25;i++) cout<<p[i].size()<<" "; cout<<endl;
		for(int i=0;i<=25;i++) if(p[i].size()>=3) {f=1; break;}
		if(f==1) {puts("NO"); continue;}
		puts("YES");
		vector <int> vec; vec.clear(); ans.clear();
		for(int i=0;i<=25;i++) if(p[i].size()==1) vec.push_back(i);
		for(int i=0;i<vec.size();i++) if(v2[vec[i]]==0) wk(vec[i]);
		for(int i=0;i<=25;i++) if(p[i].size()==0) ans.push_back(i);
		for(int i=0;i<ans.size();i++) printf("%c",ans[i]+'a'); puts("");
	}
	return 0;
}