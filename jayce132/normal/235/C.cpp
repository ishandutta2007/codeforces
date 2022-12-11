#include<unordered_map>
#include<unordered_set>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<cassert>
#include<vector>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,a) for(int i=start[(a)];i;i=e[i].next)
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
#define fi first
#define se second
#define mkr(a,b) make_pair(a,b)
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int maxn=1e6+20;

struct node {
	int len,fa,ch[26],size;
};
node t[maxn<<2];
int tot,last;
int tag[maxn],per[maxn<<2],Mx,len,vis[maxn<<2],tim;

char str[maxn];

int n;
char T[maxn<<1];

inline void Add(int x)
{
	int p=last,np=last=++tot;
	t[np].size=1; t[np].len=t[p].len+1;
	while(p && !t[p].ch[x])t[p].ch[x]=np,p=t[p].fa;
	if(!p)t[np].fa=1;
	else {
		int q=t[p].ch[x];
		if(t[q].len==t[p].len+1)t[np].fa=q;
		else {
			int nq=++tot;
			t[nq].fa=t[q].fa;memcpy(t[nq].ch,t[q].ch,sizeof(int)*26);
			t[nq].len=t[p].len+1; 
			t[np].fa=t[q].fa=nq;
			while(p && t[p].ch[x]==q)t[p].ch[x]=nq,p=t[p].fa;
		}
	}
}


inline void init()
{
	scanf("%s",str+1); len=strlen(str+1);
	n=read();
	tot=last=1;
	REP(i,1,len)Add(str[i]-'a');

	
	REP(i,1,tot)tag[t[i].len]++;
	REP(i,1,len)tag[i]+=tag[i-1];
	DREP(i,tot,1)per[--tag[t[i].len]]=i;
	DREP(i,tot,2)t[t[per[i]].fa].size+=t[per[i]].size;
	
}

inline void doing()
{
	REP(QUERY,1,n)
	{
		scanf("%s",T+1);
		int now=1,m=strlen(T+1),len=0,ans=0;
		REP(i,1,m-1)T[i+m]=T[i];
		REP(i,1,(m<<1)-1)
		{
			int x=T[i]-'a';
			if(t[now].ch[x])now=t[now].ch[x],len++;
			else {
				while(now && !t[now].ch[x])now=t[now].fa,len=t[now].len;
				if(!now)now=1,len=0;
				else now=t[now].ch[x],len++;
			}
			if(len==m)
			{
				//ans+=t[now].size;
				(vis[now]!=QUERY?(ans+=t[now].size,vis[now]=QUERY):0);
				len--;
				if(t[t[now].fa].len>=len)now=t[now].fa;
			}
		}
		printf("%d\n",ans);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("cls.in","r",stdin);
	freopen("cls.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}