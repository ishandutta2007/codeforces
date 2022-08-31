#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
int n,k;
char buf[200005],*str;
struct node{int ch[26],pre,ml;}t[200005];int ndtot;
int s,last;
void add(int c){
	int p=last;
	if(!t[p].ch[c]){
		int np=++ndtot;
		t[np].ml=t[p].ml+1;
		for (;p && !t[p].ch[c];p=t[p].pre)t[p].ch[c]=np;
		if(!p)t[np].pre=s;
		else{
			int q=t[p].ch[c];
			if(t[q].ml==t[p].ml+1)t[np].pre=q;
			else{
				int nq=++ndtot;
				t[nq]=t[q];t[nq].ml=t[p].ml+1;
				t[np].pre=t[q].pre=nq;
				for (;p && t[p].ch[c]==q;p=t[p].pre)t[p].ch[c]=nq;
			}
		}
		last=np;
	}else{
		int q=t[p].ch[c];
		if(t[q].ml==t[p].ml+1)last=q;
		else{
			int nq=++ndtot;
			t[nq]=t[q];t[nq].ml=t[p].ml+1;
			t[q].pre=nq;
			for (;p && t[p].ch[c]==q;p=t[p].pre)t[p].ch[c]=nq;
			last=nq;
		}
	}
}
struct edge{int v,next;}e[400005];int etot=0;
int col[200005],g[200005];
void ae(int *g,int u,int v){e[etot].v=v;e[etot].next=g[u];g[u]=etot++;}
int las[200005]={0},dfn[200005];int ind=0;
int stk[200005],top=0;
int su[200005]={0},tmp[200005]={0};
void dfs(int u){
	dfn[stk[++top]=u]=++ind;
	tmp[top]=0;
	for (int i=col[u];~i;i=e[i].next){
		int c=e[i].v;
		int l=0,r=top-1,mid;
		while(l<=r){
			mid=l+r>>1;
			if(dfn[stk[mid]]<=las[c])l=mid+1;
			else r=mid-1;
		}
		tmp[r]--;tmp[top]++;
		las[c]=ind;
	}
	for (int i=g[u];~i;i=e[i].next)dfs(e[i].v);
	su[u]=tmp[top];
	tmp[top-1]+=tmp[top];
	top--;
}
typedef long long ll;
ll sum[200005]={0};
void dfs2(int u){
	sum[u]=sum[t[u].pre]+(t[u].ml-t[t[u].pre].ml)*(su[u]>=k);
	for (int i=g[u];~i;i=e[i].next)dfs2(e[i].v);
}
int main()
{
	scanf("%d%d",&n,&k);
	str=buf;
	s=ndtot=1;
	memset(col,-1,sizeof(col));
	memset(g,-1,sizeof(g));
	for (int i=1;i<=n;i++){
		scanf("%s",str);
		last=s;
		int j;
		for (j=0;str[j];j++){
			add(str[j]-'a');
			ae(col,last,i);
		}
		str+=j+1;
	}
	for (int i=2;i<=ndtot;i++)ae(g,t[i].pre,i);
	dfs(s);
	dfs2(s);
	str=buf;
	for (int i=1;i<=n;i++){
		ll ans=0;
		int len=0,p=s;
		int j;
		for (j=0;str[j];j++){
			while(p && !t[p].ch[str[j]-'a'])p=t[p].pre,len=t[p].ml;
			if(!p)p=s,len=0;
			else p=t[p].ch[str[j]-'a'],len++;
			ans+=sum[t[p].pre]+(len-t[t[p].pre].ml)*(su[p]>=k);
		}
		str+=j+1;
		printf("%I64d\n",ans);
	}
	return 0;
}