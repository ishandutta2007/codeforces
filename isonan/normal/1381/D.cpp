#include <cstdio>
#include <cstring>
#include <algorithm>

int t,n,a,B,head[100001],nxt[200001],b[200001],k,node[200001],top,g[200001],m[200001],h[200001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
int getmx(int x,int f){
	int ans=-1;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			ans=std::max(ans,getmx(b[i],x));
		}
	g[x]=ans+1;
	return ans+1;
}
void getpath(int x,int f,int end){
	node[++top]=x;
	if(x==end)return;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			getpath(b[i],x,end);
			if(node[top]==end)return;
		}
	--top;
}
bool getans(int x,int f,int f2){
	int cnt=0;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f&&b[i]!=f2){
			if(getans(b[i],x,f2))return 1;
			if(g[b[i]]>=top-2)++cnt;
		}
//	printf("getans %d %d %d %d\n",x,f,f2,cnt);
	if(cnt>=2)return 1;
	return 0;
}
int se[2000001],mx[2000001],mx2[2000001];
void build(int root,int l,int r){
	if(l==r){
		se[root]=(l==1||l==top)?-0x7f7f7f7f:m[l];
		mx[root]=-std::min(std::max(l+top-1-m[l],l+1),top);
		mx2[root]=std::max(std::min(l+m[l]-top+1,l-1),1);
		return;
	}
	build(root<<1,l,(l+r)>>1);
	build(root<<1|1,((l+r)>>1)+1,r);
	se[root]=std::max(se[root<<1],se[root<<1|1]);
	mx[root]=std::max(mx[root<<1],mx[root<<1|1]);
	mx2[root]=std::max(mx2[root<<1],mx2[root<<1|1]);
}
int query(int root,int l,int r,int el,int er,int *se){
	if(el>r||er<l)return -0x7f7f7f7f;
	if(el<=l&&er>=r)return se[root];
	return std::max(query(root<<1,l,(l+r)>>1,el,er,se),query(root<<1|1,((l+r)>>1)+1,r,el,er,se));
}
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d%d%d",&n,&a,&B);
		memset(h,0,sizeof h);
		memset(g,0,sizeof g);
		memset(m,0,sizeof m);
		memset(node,0,sizeof node);
		for(int i=1;i<=n;i++)head[i]=0;
		k=0;
		for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v),push(u,v),push(v,u);
		top=0;
		getpath(a,0,B);
		int all=top+(m[1]=getmx(a,node[2]))+(m[top]=getmx(B,node[top-1]));
		bool cando=0;
		for(int i=2;i<top;i++)
			for(int j=head[node[i]];j;j=nxt[j])
				if(b[j]!=node[i-1]&&b[j]!=node[i+1]){
					int v=getmx(b[j],node[i]);
//					printf("%d %d\n",b[j],v);
					m[i]=std::max(m[i],v+1);
				}
		for(int i=2;i<top;i++)h[i]=getans(node[i],node[i-1],node[i+1]);
//		for(int i=1;i<=top;i++)printf("%d ",h[i]);putchar('\n');
		for(int i=1;i<=top;i++)h[i]+=h[i-1];
		if(getans(a,node[2],0)||getans(B,node[top-1],0)){
			puts("YES");
			continue;
		}
//		putchar('*');
		build(1,1,top);
		int l=m[top]+1,r=m[1]+1;
//		for(int i=1;i<=top;i++)printf("%d\n",m[i]);
		for(;;){
//			printf("&%d %d\n",l,r);
			if((h[l]>0)||(h[top]>h[top-r])){
				cando=1;
				break;
			}
//			putchar('*');
			int oy=r,ox=l;
			r=std::max(r,top+query(1,1,top,1,l,mx)+1);
			l=std::max(l,query(1,1,top,top-r+1,top,mx2));
			r=std::min(r,top);
			l=std::min(l,top);
			if(oy==r&&ox==l)break;
		}
//		printf("%d\n",top);
		r=top-r+1;
//		printf("%d %d %d\n",l,r,cando);
//		for(int i=1;i<=top;i++)printf("%d %d\n",m[i],node[i]);putchar('\n');
		if(r<=l&&query(1,1,top,r,l,se)>=top-1)cando=1;
		if(cando)puts("YES");
		else puts("NO");
	}
}