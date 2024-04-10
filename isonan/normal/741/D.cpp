#include <bits/stdc++.h>

int tag[4194304],mx[4194304],now,n,fin[500001];
int ans;
int val[500001];
int head[500001],nxt[1000001],b[1000001],k,size[500001],son[500001];
int dep[500001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
int &gmx(int x){
	if(tag[x]<now)mx[x]=-0x7f7f7f7f,tag[x]=now;
	return mx[x];
}
void dfs1(int x,int f){
	size[x]=1;
	dep[x]=dep[f]+1;
	for(int i=head[x];i;i=nxt[i]){
		dfs1(b[i],x);
		size[x]+=size[b[i]];
		if(size[son[x]]<size[b[i]])son[x]=b[i];
	}
}
void chk(int x,int del){
	ans=std::max(ans,gmx(x)+del);
	for(int i=0;i<22;i++)ans=std::max(ans,gmx(x^(1<<i))+del);
}
void add(int x,int v){
	gmx(x)=std::max(gmx(x),v);
}
void chktot(int x,int f,int rt){
	chk(val[x],dep[x]-(dep[rt]<<1));
	for(int i=head[x];i;i=nxt[i])
		chktot(b[i],x,rt);
}
void addtot(int x,int f){
	add(val[x],dep[x]);
	for(int i=head[x];i;i=nxt[i])
		addtot(b[i],x);
}
void getans(int x,int f){
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=son[x]){
			getans(b[i],x);
			++now;
			fin[x]=std::max(fin[x],fin[b[i]]);
			ans=0;
		}
	if(son[x]){
		getans(son[x],x);
		fin[x]=std::max(fin[x],fin[son[x]]);
	}
	chk(val[x],-dep[x]);
	add(val[x],dep[x]);
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=son[x]){
			chktot(b[i],x,x);
			addtot(b[i],x);
		}
	fin[x]=std::max(fin[x],ans);
}
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d",&n);
	for(int i=2,a,b;i<=n;i++){
		scanf("%d %c",&a,&b);
		push(a,i);
		val[i]=val[a]^(1<<(b-'a'));
	}
	++now;
	dfs1(1,0);
	getans(1,0);
	for(int i=1;i<=n;i++)printf("%d ",fin[i]);
}