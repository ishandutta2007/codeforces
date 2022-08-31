#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <set>

int n,m,head[200001],nxt[400001],b[400001],k;
int stk[200001],top,fa[200001],id[200001],dep[200001];
std::pair<int,int> vec[200001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
void write(int x){
	if(x>9)write(x/10);
	putchar((x%10)+'0');
}
void dfs(int x,int f){
	dep[x]=dep[f]+1;
	fa[x]=f;
	std::pair<int,int>tem=std::make_pair(0,0);
	for(int i=head[x];i;i=nxt[i])
		if(!dep[b[i]]){
			dfs(b[i],x);
			if(vec[b[i]].first&&dep[vec[b[i]].first]<dep[x]){
				if(!vec[x].first)vec[x]=vec[b[i]];
				else{tem=vec[b[i]];break;}
			}
		}
		else if(dep[b[i]]<dep[x]-1){
			if(!vec[x].first)vec[x]=std::make_pair(b[i],x);
			else{tem=std::make_pair(b[i],x);break;}
		}
	if(tem.first){
		puts("YES");
		std::pair<int,int> a=vec[x],b=tem;
		if(dep[a.first]<dep[b.first])std::swap(a,b);
		int start=a.first;
		top=0;
		stk[++top]=start;
		int tem=a.second;
		for(;;){stk[++top]=tem;if(tem==x)break;tem=fa[tem];}
		write(top),putchar(' ');
		for(int i=top;i;i--)write(stk[i]),putchar(' ');putchar('\n');
		tem=start;
		top=0;
		for(;;){stk[++top]=tem;if(tem==b.first)break;tem=fa[tem];}
		tem=b.second;
		for(;;){stk[++top]=tem;if(tem==x)break;tem=fa[tem];}
		write(top),putchar(' ');
		for(int i=top;i;i--)write(stk[i]),putchar(' ');putchar('\n');
		top=0;
		tem=x;
		for(;;){stk[++top]=tem;if(tem==start)break;tem=fa[tem];}
		write(top),putchar(' ');
		for(int i=1;i<=top;i++)write(stk[i]),putchar(' ');putchar('\n');
		exit(0);
	}
}
int main(){
//	freopen("in.txt","r",stdin);
	n=read(),m=read();
	for(int i=1,u,v;i<=m;i++){
		u=read(),v=read();
		push(u,v);
		push(v,u);
	}
	for(int i=1;i<=n;i++)
		if(!dep[i])dfs(i,0);
	puts("NO");
}