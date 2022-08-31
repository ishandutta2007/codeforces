#include <iostream>
#include <cstdio>
#include <queue>

int n,head[101],nxt[201],b[201],k;
int f[101],fa[101];
bool vis[101];
__int128 v[101],Pow[101];
std::priority_queue<__int128>heap;
std::priority_queue<std::pair<__int128,int> >th;
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void write(__int128 x,__int128 p=2){
	if(x>=p)write(x/p,p);
	putchar((x%p)+'0');
}
void getans(int x,int f){
	fa[x]=f;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f)getans(b[i],x);
	v[x]=Pow[n]-1;
	for(int i=n-1;~i;--i){
		v[x]^=Pow[i];
		while(!heap.empty())heap.pop();
		for(int i=head[x];i;i=nxt[i])
			if(b[i]!=f)heap.push(v[b[i]]);
		bool cando=1;
		for(int j=n-1;~j;--j){
			if(!(v[x]&Pow[j])){
				if(!heap.empty()&&(heap.top()&Pow[j])){
					cando=0;
					break;
				}
			}
			else{
				if(!heap.empty()){
					if(heap.top()&Pow[j]){
						__int128 now=heap.top();
						heap.pop();
						heap.push(now^Pow[j]);
						if(heap.top()&Pow[j]){
							cando=0;
							break;
						}
					}
					else{
						heap.pop();
					}
				}
			}
		}
		cando&=(heap.empty());
		if(!cando)v[x]^=Pow[i];
	}
	while(!th.empty())th.pop();
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f)th.push(std::make_pair(v[b[i]],b[i]));
	for(int i=n-1;~i;--i){
		if(v[x]&Pow[i]){
			std::pair<__int128,int>now=th.top();
			th.pop();
			if(now.first&Pow[i]){
				now.first-=Pow[i];
				th.push(now);
			}
			else{
				::f[now.second]=i;
			}
		}
	}
//	printf("%d ",x);
//	write(v[x]);putchar('\n');
}
void del(int x,int f){
	if(vis[x])return;
	vis[x]=1;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			del(b[i],x);
		}
}
int main(){
	scanf("%d",&n);
	Pow[0]=(__int128)1;
	for(int i=1;i<=n;i++)Pow[i]=Pow[i-1]<<(__int128)1;
	for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v),push(u,v),push(v,u);
	getans(1,0);
	for(;;){
		int p=0;
		for(int i=2;i<=n;i++)
			if(!vis[i]&&!vis[fa[i]]&&(!p||f[i]>f[p]))
				p=i;
		if(!p){
			for(int i=1;i<=n;i++)
				if(!vis[i]){
					printf("! %d\n",i);
					fflush(stdout);
					return 0;
				}
		}
		printf("? %d %d\n",p,fa[p]);
		fflush(stdout);
		int tem;
		scanf("%d",&tem);
		if(tem==p)del(fa[p],p);
		else del(p,fa[p]);
	}
//	for(int i=2;i<=n;i++)printf("%d %d\n",i,f[i]);
}