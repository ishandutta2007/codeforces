#include <cstdio>
#include <queue>
#include <vector>

const int P=1000000007;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
int qsm(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=mul(ans,a);
		a=mul(a,a);
		b>>=1;
	}
	return ans;
}
int lson[8000001],rson[8000001],cnt;
int Pow[100021];
int h[8000001],mx[8000001];
void clear(int &pos,int pre,int l,int r,int e){
	if(r<e)return;
	pos=++cnt;
	lson[pos]=lson[pre];
	rson[pos]=rson[pre];
	h[pos]=h[pre];
	mx[pos]=mx[pre];
	// if(pos==53)printf("\t\t\t***\n");
	if(l>=e){
		pos=0;
		mx[pos]=0;
		return;
	}
	clear(lson[pos],lson[pre],l,(l+r)>>1,e);
	clear(rson[pos],rson[pre],((l+r)>>1)+1,r,e);
	h[pos]=add(mul(h[lson[pos]],Pow[r-((l+r)>>1)]),h[rson[pos]]);
	mx[pos]=(mx[rson[pos]]==(((l+r)>>1)+1)&&mx[lson[pos]])?mx[lson[pos]]:mx[rson[pos]];
}
void Add(int &pos,int pre,int l,int r,int e){
	// printf("Add %d %d %d %d %d %d %d\n",l,r,e,mx[pos],mx[lson[pos]],mx[rson[pos]],pos);
	pos=++cnt;
	lson[pos]=lson[pre];
	rson[pos]=rson[pre];
	h[pos]=h[pre];
	mx[pos]=mx[pre];
	if(l==r){
		h[pos]=1;
		mx[pos]=l;
		return;
	}
	if(e>((l+r)>>1))Add(rson[pos],rson[pre],((l+r)>>1)+1,r,e);
	else if(mx[lson[pos]]&&mx[lson[pos]]<=e){
		clear(lson[pos],lson[pre],l,(l+r)>>1,e);
		Add(rson[pos],rson[pre],((l+r)>>1)+1,r,((l+r)>>1)+1);
	}
	else{
		Add(lson[pos],lson[pre],l,(l+r)>>1,e);
	}
	// if(pos==53)printf("\t\t\t**** %d %d %d %d\n",mx[pos],mx[lson[pos]],mx[rson[pos]],(((l+r)>>1)+1));
	h[pos]=add(mul(h[lson[pos]],Pow[r-((l+r)>>1)]),h[rson[pos]]);
	mx[pos]=(mx[rson[pos]]==(((l+r)>>1)+1)&&mx[lson[pos]])?mx[lson[pos]]:mx[rson[pos]];
}
int cmp(int a,int b,int l,int r){
	if(l==r){
		return h[a]-h[b];
	}
	if(h[rson[a]]==h[rson[b]])return cmp(lson[a],lson[b],l,(l+r)>>1);
	else return cmp(rson[a],rson[b],((l+r)>>1)+1,r);
}
int dis[100001],pre[100001],n,m;
bool vis[100001],vis2[100001];
int head[100001],nxt[200001],b[200001],v[200001],k,s,t;
void push(int s,int t,int val){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
	v[k]=val;
}
struct Cmp{
	bool operator()(std::pair<int,int> a,std::pair<int,int> b){
		int x=cmp(a.second,b.second,1,100021);
		if(x==1)return 1;
		if(x==-1)return 0;
		return a.first<b.first;
	}
};
std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int> >,Cmp>heap;
void debug(int pos,int l,int r){
	if(!pos||!h[pos])return;
	if(l==r){
		printf("%d ",l-1);
		return;
	}
	debug(lson[pos],l,(l+r)>>1);
	debug(rson[pos],((l+r)>>1)+1,r);
}
int fin;
void getv(int pos,int l,int r){
	if(!pos||!h[pos])return;
	if(l==r){
		fin=add(fin,Pow[l-1]);
		return;
	}
	getv(lson[pos],l,(l+r)>>1);
	getv(rson[pos],((l+r)>>1)+1,r);
}
int main(){
	Pow[0]=1;
	for(int i=1;i<=100020;++i)Pow[i]=mul(Pow[i-1],487329851);
	scanf("%d%d",&n,&m);
	for(int i=1,u,v,x;i<=m;++i){
		scanf("%d%d%d",&u,&v,&x);
		++x;
		push(u,v,x);
		push(v,u,x);
	}
	scanf("%d%d",&s,&t);
	vis[s]=1;
	heap.push(std::make_pair(s,0));
	for(;!heap.empty();){
		int p=heap.top().first;
		heap.pop();
		if(vis2[p])continue;
		vis2[p]=1;
		for(int i=head[p];i;i=nxt[i])
			if(!vis2[b[i]]){
				int x;
				Add(x,dis[p],1,100021,v[i]);
				// printf("%d %d:\n",p,b[i]);
				// debug(x,1,100021);putchar('\n');
				if((!vis[b[i]])||(cmp(x,dis[b[i]],1,100021)==-1))vis[b[i]]=1,dis[b[i]]=x,pre[b[i]]=p,heap.push(std::make_pair(b[i],x));
			}
	}
	if(!vis[t]){
		puts("-1");
		return 0;
	}
	// for(int i=1;i<=n;++i){
	// 	printf("%d: %d\n",i,pre[i]);
	// 	debug(dis[i],1,100021);
	// 	putchar('\n');
	// }
	// printf("*%d\n",cmp(dis[2],dis[4],1,100021));
	Pow[0]=1;
	for(int i=1;i<=100020;++i)Pow[i]=mul(Pow[i-1],2);
	getv(dis[t],1,100021);
	printf("%d\n",fin);
	std::vector<int>ans;
	for(;t;){
		ans.push_back(t);
		t=pre[t];
	}
	printf("%d\n",ans.size());
	for(int i=(int)ans.size()-1;~i;--i)printf("%d ",ans[i]);
}