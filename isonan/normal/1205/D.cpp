#include <cstdio>
#include <vector>

int n,head[1001],nxt[2001],b[2001],k,size[1001],mx[1001],root;
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void getroot(int x,int f){
	size[x]=1,mx[x]=0;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			getroot(b[i],x);
			size[x]+=size[b[i]];
			mx[x]=std::max(mx[x],size[b[i]]);
		}
	mx[x]=std::max(mx[x],n-size[x]);
	if(mx[x]<mx[root])root=x;
}
void get(int x,int f){
	size[x]=1;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			get(b[i],x);
			size[x]+=size[b[i]];
		}
}
int A,B;
std::vector<int>t1,t2;
void dfs(int x,int f,int mul){
	int tem=1;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			printf("%d %d %d\n",b[i],x,tem*mul);
			dfs(b[i],x,mul);
			tem+=size[b[i]];
		}
}
int main(){
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		push(u,v);
		push(v,u);
	}
	mx[root=0]=n;
	getroot(1,0);
	get(root,0);
	for(int i=head[root];i;i=nxt[i])
		if(A<B)A+=size[b[i]],t1.push_back(b[i]);
		else B+=size[b[i]],t2.push_back(b[i]);
	int tem=1;
	for(int i=0;i<t1.size();i++)
		printf("%d %d %d\n",root,t1[i],tem),dfs(t1[i],root,1),tem+=size[t1[i]];
	tem=1;
	for(int i=0;i<t2.size();i++)
		printf("%d %d %d\n",root,t2[i],tem*(A+1)),dfs(t2[i],root,A+1),tem+=size[t2[i]];
}