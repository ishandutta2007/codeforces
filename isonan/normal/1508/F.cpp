#include <unordered_map>
#include <algorithm>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <cmath> 

int n,q,a[25001],ord[25001];
int pos[25001],bl;
struct query{
	int l,r,ord;
}num[100010];
bool cmp(query a,query b){return (pos[a.l]!=pos[b.l])?pos[a.l]<pos[b.l]:((a.r<b.r)^(pos[a.l]&1));}
int exi[20000001],cnt,now,ll[20000001],rr[20000001],end[20000001];
std::unordered_map<int,int>map[25001];
std::vector<std::pair<int,int> >L[25001],R[25001];
std::vector<std::pair<int,int> >Q[25001];
void Add(int l,int r){
	if(l>r)std::swap(l,r);
	int &p=map[l][r];
	if(!p)p=++cnt,L[l].push_back(std::make_pair(r,p)),R[r].push_back(std::make_pair(l,p)),ll[p]=l,rr[p]=r;
}
void check(int x,int l,int r){
	if(l>r)return;
	if(x<r)Q[x].push_back(std::make_pair(r,0));
	else Q[x].push_back(std::make_pair(l,0));
}
int Cnt[100010];
std::vector<std::pair<int,int> >vec[25001],vec2[25001];
int Log[161];
struct rmq{
	int st[9][161];
	void clear(){memset(st,0x7f,sizeof st);}
	void upd(int x,int y){
		for(int i=0;(1<<i)<=160;++i)
			for(int j=x;j>0&&j+(1<<i)-1>=x;--j)
				st[i][j]=std::min(st[i][j],y);
	}
	int query(int l,int r){
		if(l>r)return 0x7f7f7f7f;
		int k=Log[r-l+1];
//		printf("query %d %d\n",l,r);
		return std::min(st[k][l],st[k][r-(1<<k)+1]);
	}
};
struct sqrt_min{
	rmq bl[161],tot;
	void clear(){
		tot.clear();
		for(int i=1;i<=pos[n];++i)bl[i].clear();
	}
	void upd(int x,int y){
		tot.upd(pos[x],y);
		bl[pos[x]].upd(x-(pos[x]-1)*::bl,y);
	}
	int query(int l,int r){
		if(pos[l]==pos[r])return bl[pos[l]].query(l-(pos[l]-1)*::bl,r-(pos[r]-1)*::bl);
		else return std::min(bl[pos[l]].query(l-(pos[l]-1)*::bl,::bl),std::min(tot.query(pos[l]+1,pos[r]-1),bl[pos[r]].query(1,r-(pos[r]-1)*::bl)));
	}
}ds;
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
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)a[i]=read(),ord[a[i]]=i;
//	for(int i=1;i<=n;++i)printf("%d ",ord[i]);putchar('\n');
	for(int i=1;i<=q;++i)num[i].l=read(),num[i].r=read(),num[i].ord=i,vec[num[i].l].push_back(std::make_pair(num[i].r,num[i].ord));
	bl=std::max(1,(int)((double)n/sqrt(q)));
	for(int i=1;i<=n;++i)pos[i]=(i-1)/bl+1;
	std::sort(num+1,num+q+1,cmp);
	for(int i=1,l=1,r=0;i<=q;++i){
		now=i;
		while(l>num[i].l)check(l-1,l,r),--l;
		while(r<num[i].r)check(r+1,l,r),++r;
		while(l<num[i].l)++l,check(l-1,l,r);
		while(r>num[i].r)--r,check(r+1,l,r);
	}
	bl=(int)sqrt(n);
	for(int i=1;i<=n;++i)pos[i]=(i-1)/bl+1;
	for(int i=2;i<=160;++i)Log[i]=Log[i>>1]+1;
	ds.clear();
	for(int i=n;i;--i){
//		printf("*%d\n",ord[i]);
		for(int j=0;j<Q[ord[i]].size();++j){
			int l=ord[i],r=Q[ord[i]][j].first;
			if(l>r)std::swap(l,r);
			Q[ord[i]][j].second=ds.query(l,r);
		}
		ds.upd(ord[i],i);
	}
	ds.clear();
	for(int i=1;i<=n;++i){
		for(int j=0;j<Q[ord[i]].size();++j){
			int l=ord[i],r=Q[ord[i]][j].first;
			if(l>r)std::swap(l,r);
			int t1=ds.query(l,r),t2=Q[ord[i]][j].second;
//			printf("%d %d %d %d\n",l,r,t1,t2);
			if(t1<=n)Add(ord[n-t1+1],ord[i]);
			if(t2<=n)Add(ord[t2],ord[i]);
			if(t1<=n&&t2<=n)Add(ord[n-t1+1],ord[t2]);
		}
		ds.upd(ord[i],n-i+1);
	}
	ds.clear();
	for(int i=1;i<=n;++i){
		for(int j=0;j<L[i].size();++j){
			int l=a[i],r=a[L[i][j].first];
			if(l>r)std::swap(l,r);
			int t=ds.query(l,r);
			if(t<=n)vec2[n-t+1].push_back(L[i][j]);
		}
		ds.upd(a[i],n-i+1);
	}
	ds.clear();
	for(int i=n;i;--i){
		for(int j=0;j<R[i].size();++j){
			int l=a[i],r=a[R[i][j].first];
			if(l>r)std::swap(l,r);
			int t=ds.query(l,r);
//			printf("%d %d %d\n",i,R[i][j].first,t);
			if(t<=n)vec2[R[i][j].first].push_back(std::make_pair(t,R[i][j].second));
		}
		ds.upd(a[i],i);
	}
	ds.clear();
	memset(end,0x7f,sizeof end);
	for(int i=1;i<=n;++i){
		for(int j=0;j<vec[i].size();++j)
			ds.upd(vec[i][j].first,vec[i][j].second);
//		printf("%d\n",i);
		for(int j=0;j<L[i].size();++j){
//			printf("%d %d %d\n",L[i][j].first,L[i][j].second,ds.query(L[i][j].first,n));
			exi[L[i][j].second]=ds.query(L[i][j].first,n);
		}
		for(int j=0;j<vec2[i].size();++j){
//			printf("%d %d %d\n",vec2[i][j].second,i,vec2[i][j].first);
			if(vec2[i][j].first)end[vec2[i][j].second]=std::min(end[vec2[i][j].second],ds.query(vec2[i][j].first,n));
		}
	}
	for(int i=1;i<=cnt;++i){
		if(exi[i]<=q){
			++Cnt[exi[i]];
//		fprintf(stderr,"*%d %d %d %d\n",ll[i],rr[i],exi[i],end[i]);
			if(end[i]<=q)--Cnt[end[i]];
		}
//		else{
//			fprintf(stderr,"%d %d %d\n",ll[i],rr[i],exi[i]);
//		}
	}
	for(int i=1;i<=q;++i)write(Cnt[i]+=Cnt[i-1]),putchar('\n');
}