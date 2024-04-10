#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int maxn=600010,INF=0x3f3f3f3f;
int n;
int siz[maxn],son[maxn],ans[maxn];
int loc[maxn],cnt[maxn],buc[1<<22];
char s[maxn];
vector<int> v[maxn];
inline int read(){
	int res=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return res;
}
void dfs(int p){
	siz[p]=1;
	for(register int i:v[p]){
		loc[i]=loc[p]^(1<<(s[i]-'a'));
		cnt[i]=cnt[p]+1;
		dfs(i);
		if(siz[i]>siz[son[p]])son[p]=i;
		siz[p]+=siz[i];
	}
}
void clear(int p){
	buc[loc[p]]=-INF;
	for(register int i:v[p])
		clear(i);
}
void push(int p){
	buc[loc[p]]=max(buc[loc[p]],cnt[p]);
	for(register int i:v[p])
		push(i);
}
void query(int p,int rt){
	// 
	ans[rt]=max(ans[rt],cnt[p]+buc[loc[p]]-2*cnt[rt]);
	for(register int i=0;i<22;++i)
		ans[rt]=max(ans[rt],cnt[p]+buc[loc[p]^(1<<i)]-2*cnt[rt]);
	for(register int i:v[p])
		query(i,rt);
}
void dfs2(int p){
	if(!p)return;
	for(register int i:v[p])
		if(i!=son[p]){
			dfs2(i);clear(i);
		}
	dfs2(son[p]);
	// 
	for(register int i:v[p])
		if(i!=son[p])
			query(i,p),push(i);
	buc[loc[p]]=max(buc[loc[p]],cnt[p]);
	//
	ans[p]=max(ans[p],buc[loc[p]]-cnt[p]);
	for(register int i=0;i<22;++i)
		ans[p]=max(ans[p],buc[loc[p]^(1<<i)]-cnt[p]);
}
void dfs3(int p){
	// 
	for(register int i:v[p])
		dfs3(i),ans[p]=max(ans[p],ans[i]);
}
int main(){
	n=read();
	for(register int i=2;i<=n;++i){
		v[read()].push_back(i);
		scanf("%c",s+i);
	}
	for(register int i=0;i<1<<22;++i)
		buc[i]=-INF;
	dfs(1);
	dfs2(1);
	dfs3(1);
	for(register int i=1;i<=n;++i)
		printf("%d ",ans[i]);
	return 0;
}