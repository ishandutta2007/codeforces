#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=101000;
int n,m;
int q1t,q2t,fil;
int fa[maxn],dfn[maxn],dfe[maxn],tsp;
int tr[maxn],ans[maxn];
bool exisfa[maxn];
vector <int> v[maxn];
struct note{
	int op,x,y;
	bool operator <(note b){
		return y<b.y;
	}
}q1[maxn],q2[maxn];
inline int read(){
	int res=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return res;
}
int getfa(int x){
	return fa[x]==x?x:(fa[x]=getfa(fa[x]));
}
void add(int p,int x){
	if(!p)return;
	for(register int i=p;i<=n;i+=i&-i)
		tr[i]+=x;
}
int query(int p){
	int res=0;
	for(register int i=p;i;i-=i&-i)
		res+=tr[i];
	return res;
}
void dfs(int p){
	dfn[p]=++tsp;
	for(register int i=0;i<v[p].size();++i)
		dfs(v[p][i]);
	dfe[p]=tsp;
}
int main()
{
	n=read();m=read();
	for(register int i=0,o;i<m;++i){
		o=read();
		if(o==1){
			q1[++q1t].op=1;
			q1[q1t].x=read();q1[q1t].y=read();
			v[q1[q1t].y].push_back(q1[q1t].x);
			exisfa[q1[q1t].x]=true;
		}
		else if(o==2){
			q1[++q1t].op=2;
			q1[q1t].x=read();q1[q1t].y=++fil;
		}
		else{
			++q2t;
			q2[q2t].op=q2t;
			q2[q2t].x=read();q2[q2t].y=read();
		}
	}
	sort(q2+1,q2+1+q2t);
	for(register int i=1;i<=n;++i){
		fa[i]=i;
		if(!exisfa[i])
			dfs(i);
	}
	for(register int i=1,j=1;i<=q1t&&j<=q2t;++i){
		if(q1[i].op==1)
			fa[q1[i].x]=q1[i].y;
		else{
			add(dfn[q1[i].x],1);
			add(dfn[getfa(q1[i].x)]-1,-1);
			while(j<=q2t&&q1[i].y==q2[j].y){
				ans[q2[j].op]=query(dfe[q2[j].x])-query(dfn[q2[j].x]-1);
				++j;
			}
			add(dfn[q1[i].x],-1);
			add(dfn[getfa(q1[i].x)]-1,1);
		}
	}
	for(register int i=1;i<=q2t;++i)
		puts(ans[i]>0?"YES":"NO");
	return 0;
}