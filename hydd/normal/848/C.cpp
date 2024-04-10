#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,m,Q,cnt,a[110000];
int pre[110000],nxt[110000];
ll tree[110000],ans[110000];
set<int> s[110000];
struct node{
	int op,x,y,z;
	bool operator<(const node &a) const{
		if (op!=a.op) return op<a.op;
	    if (op) return y<a.y;
	    else return x<a.x;
	}
} q[1100000];
void change(int now,int lst,int op){
	if (now==n+1) return;
	q[++cnt]=(node){0,now,lst,(now-lst)*op};
//	printf("c:%d %d %d\n",now,lst,(now-lst)*op);
}
void query(int x,int y,int now){
	q[++cnt]=(node){1,x,y,now};
}
int getpre(int x){
	return *--s[a[x]].lower_bound(x);
}
int getnxt(int x){
	return *s[a[x]].upper_bound(x);
}
void add(int x,int y){
	if (!x||!y) return;
	for (;x<=n;x+=x&-x) tree[x]+=y;
}
ll getsum(int x){
	ll sum=0;
	for (;x;x-=x&-x) sum+=tree[x];
	return sum; 
}
void solve(int l,int r){
    if (l==r) return;
    int mid=(l+r)>>1;
    solve(l,mid); solve(mid+1,r);
    int j=l;
    for (int i=mid+1;i<=r;i++)
    	if (q[i].op){
	        for (;j<=mid&&(q[j].op||q[j].x<=q[i].y);j++)
	            if (!q[j].op) add(q[j].y,q[j].z);
	        ans[q[i].z]+=getsum(n)-getsum(q[i].x-1);
    	}
    for (int i=l;i<j;i++)
    	if (!q[i].op) add(q[i].y,-q[i].z);
    sort(q+l,q+r+1);
}
int main(){
	scanf("%d%d",&n,&Q);
	for (int i=1;i<=n;i++) s[i].insert(0);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[a[i]].insert(i);
	}
	for (int i=1;i<=n;i++) s[i].insert(n+1);
	for (int i=1;i<=n;i++){
		pre[i]=getpre(i);
		nxt[i]=getnxt(i);
		change(i,pre[i],1);
	}
	int op,x,y;
	while (Q--){
		scanf("%d%d%d",&op,&x,&y);
		if (op==1){
			change(x,pre[x],-1);
			if (nxt[x]<=n) change(nxt[x],x,-1);
			if (pre[x]>=1) nxt[pre[x]]=nxt[x];
			if (nxt[x]<=n) pre[nxt[x]]=pre[x];
			if (nxt[x]<=n) change(nxt[x],pre[x],1);
			s[a[x]].erase(x);
			a[x]=y;
			s[a[x]].insert(x);
			pre[x]=getpre(x); nxt[x]=getnxt(x);
			if (nxt[x]<=n) change(nxt[x],pre[x],-1);
			if (nxt[x]<=n) pre[nxt[x]]=x;
			if (pre[x]>=1) nxt[pre[x]]=x;
			change(x,pre[x],1);
			if (nxt[x]<=n) change(nxt[x],x,1);
		} else query(x,y,++m);
	}
	solve(1,cnt);
	for (int i=1;i<=m;i++) printf("%lld\n",ans[i]);
	return 0;
}