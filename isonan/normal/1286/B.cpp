#include <cstdio>
#include <vector>
#include <cstdlib>

int head[100001],nxt[200001],b[200001],k,p[100001],c[100001],dfn[100001],now,size[100001],ans[100001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
std::vector<int>vec[2001];
void getans(int x){
	dfn[x]=++now;
	size[x]=1;
	for(int i=head[x];i;i=nxt[i]){
		getans(b[i]);
		size[x]+=size[b[i]];
		for(int j=0;j<vec[b[i]].size();j++){
			if(vec[x].size()==c[x])vec[x].push_back(x);
			vec[x].push_back(vec[b[i]][j]);
		}
	}
	if(vec[x].size()==c[x])vec[x].push_back(x);
	if(size[x]-1<c[x]){
		puts("NO");
		exit(0);
	}
}
int n;
int main(){
	scanf("%d",&n);
	int root;
	for(int i=1;i<=n;i++){
		scanf("%d%d",p+i,c+i);
		if(p[i]==0)root=i;
		else push(p[i],i);
	}
	getans(root);
	puts("YES");
	for(int i=0;i<vec[root].size();i++)ans[vec[root][i]]=i+1;
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
}