#include <cstdio>
#include <deque>
#define mp std::make_pair

using std::min;
int rank[1200001],sa[1200001],tax[1200001],tp[1200001],n,m,head[300001],nxt[600001],b[600001],k,dep[300001],fa[300001],size[300001],son[300001],top[300001];
int a[1200001],q,top1,top2,toptem,st[600001][21],loga[600001],dfn[300001],now,height[1200001];
std::pair<int,int> tem[300001],t1[300001],t2[300001];
char str[600001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void dfs1(int x,int f){
	fa[x]=f;
	size[x]=1;
	dep[x]=dep[f]+1;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			dfs1(b[i],x);
			size[x]+=size[b[i]];
			if(size[b[i]]>size[son[x]])son[x]=b[i];
		}
}
void dfs2(int x,int t){
	top[x]=t;
	dfn[x]=++now;
	if(son[x])dfs2(son[x],t);
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=fa[x]&&b[i]!=son[x])
			dfs2(b[i],b[i]);
}
void SetSubStr(int x,int y,std::pair<int,int>*a,int &Top){
	Top=toptem=0;
	while(top[x]!=top[y]){
		if(dep[top[x]]>dep[top[y]]){
			a[++Top]=mp((n<<1)-dfn[x]+1,(n<<1)-dfn[top[x]]+1);
			x=fa[top[x]];
		}
		else{
			tem[++toptem]=mp(dfn[top[y]],dfn[y]);
			y=fa[top[y]];
		}
	}
	if(dfn[x]<dfn[y])a[++Top]=mp(dfn[x],dfn[y]);
	else a[++Top]=mp((n<<1)-dfn[x]+1,(n<<1)-dfn[y]+1);
	for(int i=toptem;i;--i)a[++Top]=tem[i];
}
void Qsort(){
	for(int i=0;i<=m;i++)tax[i]=0;
	for(int i=1;i<=n<<1;i++)tax[rank[i]]++;
	for(int i=1;i<=m;i++)tax[i]+=tax[i-1];
	for(int i=n<<1;i;--i)sa[tax[rank[tp[i]]]--]=tp[i];
}
void buildsa(){
	m=1000;
	for(int i=1;i<=(n<<1);i++)rank[i]=a[i],tp[i]=i;
	Qsort();
	for(int w=1,p=1;p<n<<1;m=p,w<<=1){
		p=0;
		for(int i=1;i<=w;i++)tp[++p]=(n<<1)-w+i;
		for(int i=1;i<=n<<1;i++)if(sa[i]>w)tp[++p]=sa[i]-w;
		Qsort();
		std::swap(rank,tp);
		rank[sa[1]]=p=1;
		for(int i=2;i<=n<<1;i++)
			rank[sa[i]]=(tp[sa[i]]==tp[sa[i-1]]&&tp[sa[i]+w]==tp[sa[i-1]+w])?p:++p;
	}
	int k=0;
	for(int i=1;i<=n<<1;i++){
		int j=sa[rank[i]-1];
		if(k)--k;
		while(a[j+k]==a[i+k])++k;
		height[rank[i]]=st[rank[i]][0]=k;
	}
	loga[0]=-1;
	for(int i=1;i<=n<<1;i++)loga[i]=loga[i>>1]+1;
	for(int j=1;(1<<j)<=n<<1;j++)
		for(int i=1;i+(1<<j)-1<=n<<1;i++)
			st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
}
int LCP(int l,int r){
	if(l==r)return n<<2;
	l=rank[l];
	r=rank[r];
	if(l>r)std::swap(l,r);
	++l;
	int k=loga[r-l+1];
	return min(st[l][k],st[r-(1<<k)+1][k]);
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
int main(){
	n=read();
	scanf("%s",str+1);
	for(int i=1,s,t;i<n;i++){
		s=read(),t=read();
		push(s,t);
		push(t,s);
	}
	dfs1(1,0);
	dfs2(1,1);
	q=read();
	for(int i=1;i<=n;i++)a[dfn[i]]=a[(n<<1)-dfn[i]+1]=str[i];
	buildsa();
	for(int i=1,a,b,c,d;i<=q;i++){
		a=read(),b=read(),c=read(),d=read();
		SetSubStr(a,b,t1,top1);
		SetSubStr(c,d,t2,top2);
//		for(int j=1;j<=top1;j++)printf("(%d %d)",t1[j].first,t1[j].second);putchar('\n');
//		for(int j=1;j<=top2;j++)printf("(%d %d)",t2[j].first,t2[j].second);putchar('\n');
		int now1=1,now2=1,l1=t1[1].first,l2=t2[1].first,ans=0;
		for(;now1<=top1&&now2<=top2;){
			int tem=LCP(l1,l2);
			if(!tem)break;
			int length1=t1[now1].second-l1+1,length2=t2[now2].second-l2+1;
			tem=min(tem,min(length1,length2));
			ans+=tem;
			if(length1==tem)++now1,l1=t1[now1].first;
			else l1+=tem;
			if(length2==tem)++now2,l2=t2[now2].first;
			else l2+=tem;
		}
		write(ans),putchar('\n');
	}
}