#include <cstdio>
#include <vector>

int n,q,a[200001],L[200001],R[200001],f[200001],g[200001];
int find(int x){return f[x]?f[x]=find(f[x]):x;}
std::vector<int>set[1000001];
void update(int root,int l,int r,int el,int er,int x){
	if(el>r||er<l)return;
	if(el<=l&&er>=r){
		set[root].push_back(x);
		return;
	}
	update(root<<1,l,(l+r)>>1,el,er,x);
	update(root<<1|1,((l+r)>>1)+1,r,el,er,x);
}
void query(int root,int l,int r,int e,int x){
	if(set[root].size()){
	for(int i=0;i<set[root].size();i++){
		int fu=find(set[root][i]),fv=find(x);
		if(fu!=fv)f[fu]=fv,g[fv]=std::max(g[fv],g[fu]);
	}
	set[root].clear();
	set[root].push_back(find(x));
	}
	if(l==r)return;
	if((l+r)>>1>=e)query(root<<1,l,(l+r)>>1,e,x);
	else query(root<<1|1,((l+r)>>1)+1,r,e,x);
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		if(!L[a[i]])L[a[i]]=i;
		R[a[i]]=i;
		++g[a[i]];
	}
	for(int i=1;i<=200000;i++){
		if(L[i])update(1,1,n,L[i],R[i],i);
	}
	for(int i=1;i<=n;i++){
		query(1,1,n,i,a[i]);
	}
	int ans=n;
	for(int i=1;i<=200000;i++)
		if(L[i]&&!f[i])ans-=g[i];
	printf("%d\n",ans);
}