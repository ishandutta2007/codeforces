#include<bits/stdc++.h>
#define LL long long
#define LD long double
using namespace std;
const LL P=998244353;
const int N=3e5+10;
const int INF=1e9;
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
void print(LL x){
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
void pls(LL &x,LL y){
    x+=y;if(x>=P)x-=P;
}
int n,m;
struct Seg{
	int l,r; 
}a[N];
bool cmp(Seg x,Seg y){
	return x.l<y.l;
}
multiset<int> ed[2];
multiset<int>::iterator it;
int cnt;
struct Query{
	int st,op,l,r;
}q[N<<1];
struct Node{
	int l,r;
	LL num[2];
	LL sum[2];
	bool laz[2];
}d[N<<2];
#define ls id<<1
#define rs id<<1|1
void pushup(int id){
	if(d[id].l==d[id].r) return;
	d[id].num[0]=d[ls].num[0]+d[rs].num[0];
	d[id].num[1]=d[ls].num[1]+d[rs].num[1];
	d[id].sum[0]=d[ls].sum[0]+d[rs].sum[0];
	d[id].sum[1]=d[ls].sum[1]+d[rs].sum[1];
	return;
}
void pushdown(int id){
	if(d[id].l==d[id].r) return;
	if(!d[id].laz[0]){
		d[id].laz[0]=1;
		d[ls].num[0]=d[rs].num[0]=0;
		d[ls].sum[0]=d[rs].sum[0]=0;
		d[ls].laz[0]=d[rs].laz[0]=0;
	}
	if(!d[id].laz[1]){
		d[id].laz[1]=1;
		d[ls].num[1]=d[rs].num[1]=0;
		d[ls].sum[1]=d[rs].sum[1]=0;
		d[ls].laz[1]=d[rs].laz[1]=0;
	}
	return;
}
void build(int l,int r,int id){
	d[id].l=l;d[id].r=r;
	d[id].num[0]=d[id].num[1]=d[id].sum[0]=d[id].sum[1]=0;
	d[id].laz[0]=d[id].laz[1]=1;
	if(l==r){
		d[id].num[l&1]++;
		d[id].sum[l&1]+=l;
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,id<<1);
	build(mid+1,r,id<<1|1);
	pushup(id);
	return;
}

void update(int l,int r,int id,int op){
	pushdown(id);
	if(d[id].l==l&&d[id].r==r){
		d[id].num[op]=d[id].sum[op]=0;
		d[id].laz[op]=0;
		return;
	}
	if(r<=d[ls].r) update(l,r,ls,op);
	else if(l>d[ls].r) update(l,r,rs,op);
	else{
		update(l,d[ls].r,ls,op);
		update(d[rs].l,r,rs,op);
	}
	pushup(id);
	return;
}

LL res[2][2];

void ask(int l,int r,int id){
	pushdown(id);
	if(d[id].l==l&&d[id].r==r){
		res[0][0]+=d[id].num[0];
		res[1][0]+=d[id].num[1];
		res[0][1]+=d[id].sum[0];
		res[1][1]+=d[id].sum[1];
		return;
	}
	if(r<=d[ls].r) ask(l,r,ls);
	else if(l>d[ls].r) ask(l,r,rs);
	else{
		ask(l,d[ls].r,ls);
		ask(d[rs].l,r,rs);
	}
	return;
}

void MAIN(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d%d",&a[i].l,&a[i].r);
	}
	sort(a+1,a+1+n,cmp);
	cnt=0;
	int cur,L,R;
	for(int i=1,j=1;i<=m;++i){
		while(j<=n&&a[j].l==i){
			ed[a[j].r&1].insert(a[j].r);
			++j;
		}
		while(!ed[0].empty()){
			it=ed[0].begin();
			if((*it)<i) ed[0].erase(it);
			else break;
		}
		while(!ed[1].empty()){
			it=ed[1].begin();
			if((*it)<i) ed[1].erase(it);
			else break;
		}
		R=m;L=R+1;
		if((!ed[1].empty())||(!ed[0].empty())) L=i;
		if(j<=n) L=min(L,a[j].l);
		cur=i&1;
		if(ed[cur^1].empty()){
			q[++cnt]=(Query){i,cur,L,R};
		}
		else{
			it=ed[cur^1].begin();
			q[++cnt]=(Query){i,cur,L,(*it)};
		}
		if(!ed[cur^1].empty()){
			continue;
		}
		if(ed[cur].empty()){
			q[++cnt]=(Query){i,cur^1,L,R};
		}
		else{
			it=ed[cur].end();
			--it;
			q[++cnt]=(Query){i,cur^1,max(L,(*it)+1),R};
		}
	}
	build(1,m,1);
	LL ans=0;
	for(int i=cnt,j=n;i>=1;--i){
		while(j>=1&&a[j].l>q[i].st){
			cur=a[j].l&1;
			if((a[j].r-a[j].l)&1){
				if(a[j].r+1<=m) update(a[j].r+1,m,1,cur);
				update(a[j].l,m,1,cur^1);
			}
			else{
				update(a[j].l,a[j].r,1,cur^1);
			}
			--j;
		}
		res[0][0]=res[0][1]=res[1][0]=res[1][1]=0;
		if(q[i].l<=q[i].r){
			ask(q[i].l,q[i].r,1);
			ans+=res[q[i].op][1];
			ans-=(LL)(q[i].st-1)*res[q[i].op][0];
		}
	}
	printf("%lld\n",ans);
	return;
}
int main(){
	int ttt=1;
	while(ttt--) MAIN();
	return 0;	
}