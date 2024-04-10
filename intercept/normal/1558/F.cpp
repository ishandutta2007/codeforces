#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
const int M=2e5+9;
int n;
int a[M],d[M];
int b[2][M];
struct P{
	int v,l;
}t[M<<2],node;
int s[M<<2],S;
void add(int *w,int i,int v){
	for(;i<=n;i+=i&-i)w[i]+=v;
}
int kth(int *w,int k,int p=0){
	for(int i=1<<19;i;i>>=1)
		if(p+i<=n&&k>w[p+i])k-=w[p+=i];
	return p+1;
}
void pu(int now){
	t[now].v=t[now<<1].v+t[now<<1|1].v;
	t[now].l=max(t[now<<1].l,t[now<<1].v+t[now<<1|1].l);
}
void update(int now,int l,int r,int x,int v){
	if(l==r){
		t[now].v=t[now].l=v;
		return;
	}
	int mid=l+r>>1;
	x<=mid?update(now<<1,l,mid,x,v):update(now<<1|1,mid+1,r,x,v);
	pu(now);
}
void query(int now,int l,int r,int x,int y){
	if(x<=l&&r<=y){
		if(node.v==-1e9){
			node=t[now];
			return;
		}
		node.l=max(node.l,node.v+t[now].l);
		node.v=node.v+t[now].v;
		return;
	}
	int mid=l+r>>1;
	
	if(x<=mid)query(now<<1,l,mid,x,y);
	if(y>mid)query(now<<1|1,mid+1,r,x,y);
}
int g=0;
void work(){
	bool bo=0;
	scanf("%d",&n);
	g++;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		if(a[i]<a[i-1])bo=1;
	}
//	if(g==293){
//		cout<<n;
//		for(int i=1;i<=n;++i)cout<<a[i];
//		cout<<endl;
//	}
	for(int i=1;i<n;i+=2){
		if(a[i]>a[i+1])swap(a[i],a[i+1]);
	}
	if(!bo){
		puts("0");
		return;
	}
	for(int i=1;i<=n;++i){
		d[a[i]]=i;
		b[0][i]=0;
		add(b[1],i,1);
		update(1,1,n,i,1);
	}
	int ans=0;
	for(int i=1,x,y;i<=n;++i){
		int mi=0;
		x=kth(b[1],1),y=kth(b[0],i-1);
		node=P{(int)-1e9,0};
		if(x<y){
			if(i==7)y=7;
			query(1,1,n,x,y);
			mi=max(mi,node.l-1+i-x);
		}
		add(b[1],d[i],-1);
		add(b[0],d[i],1);
		update(1,1,n,d[i],-1);
		x=kth(b[1],1),y=kth(b[0],i);
		node=P{(int)-1e9,0};
		if(x<y){
			query(1,1,n,x,y);
			mi=max(mi,node.l-1+i+1-x);
		}
		ans=max(ans,mi);
	}
	printf("%d\n",ans+1);
}
int main(){
	int T;
	for(scanf("%d",&T);T;--T)work();
	return 0;
}
/*
1
7
7 3 4 1 2 5 6
7
3 5 1 2 7 6 4
7
1 6 2 3 5 7 4
9
1 2 7 5 6 8 3 4 9
*/