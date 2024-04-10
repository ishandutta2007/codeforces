#include <cstdio>
#include <cstring>
#include <algorithm>

using std::min;
using std::max;

int head[5000010],nxt[5000010],b[5000010],k,size[5000001],S,ans[5000001],q[5000010],h,t,f[5000010];
int val[5000010],dfn[5000010],low[5000010],now,stk[5000010],top;
int con[5000010][2],ct,value[5000010];
bool ins[5000010];
int n,m,d;
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
	++ct;
	con[ct][0]=s;
	con[ct][1]=t;
}
void push1(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
int hash(int x,int y){
	return (x-1)*d+y+1;
}
void tarjan(int x){
	dfn[x]=low[x]=++now;
	stk[++top]=x;
	ins[x]=1;
	for(int i=head[x];i;i=nxt[i])
		if(!dfn[b[i]])tarjan(b[i]),low[x]=min(low[x],low[b[i]]);
		else if(ins[b[i]])low[x]=min(low[x],dfn[b[i]]);
	if(low[x]==dfn[x]){
		++S;
		do{
			ins[stk[top]]=0;
			ans[stk[top]]=S;
			value[S]+=val[stk[top]];
			--top;
		}while(stk[top+1]!=x);
	}
}
int get(){
	char ch=getchar();
	while(ch!='0'&&ch!='1')ch=getchar();
	return ch=='1';
}
int main(){
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1,s,t;i<=m;i++){
		scanf("%d%d",&s,&t);
		for(int j=0;j<d;j++){
			push(hash(s,j),hash(t,(j+1)%d));
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<d;j++)val[hash(i,j)]=get();
	}
	for(int i=1;i<=n*d;i++)if(!dfn[i])tarjan(i);
	memset(head,0,sizeof head);
	k=0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<d;j++)
			if(val[hash(i,j)])
			for(int k=j+1;k<d;k++)
				if(ans[hash(i,j)]==ans[hash(i,k)]&&val[hash(i,k)]){
					val[hash(i,k)]=0;
					--value[ans[hash(i,j)]];
				}
	for(int i=1;i<=ct;i++)
		if(ans[con[i][0]]!=ans[con[i][1]])push1(ans[con[i][0]],ans[con[i][1]]);
	for(int i=1;i<=S;i++)f[i]=-0x7f7f7f7f;
	f[ans[hash(1,0)]]=0;
	int _ans=0;
	for(int i=S;i;--i){
		f[i]+=value[i];
		_ans=max(_ans,f[i]);
		for(int j=head[i];j;j=nxt[j]){
			f[b[j]]=max(f[b[j]],f[i]);
		}
	}
	printf("%d",_ans);
}