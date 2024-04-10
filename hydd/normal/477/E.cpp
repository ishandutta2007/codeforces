#include<bits/stdc++.h>
#define ls now<<1
#define rs now<<1|1
using namespace std;
const int INF=0x3f3f3f3f;
int n,Q,a[410000],Log2[410000],Ans[410000];
struct node{
	int r1,c1,r2,c2,id;
	bool operator<(const node &a) const{ return r2<a.r2;}
} q[410000];
struct Segment_Tree{
	int tree[1210000];
	void build(int now,int l,int r){
		tree[now]=INF;
		if (l==r) return;
		int mid=(l+r)>>1;
		build(ls,l,mid); build(rs,mid+1,r);
	}
	void change(int now,int l,int r,int x,int v){
		if (l==r){
			tree[now]=v;
			return;
		}
		int mid=(l+r)>>1;
		if (x<=mid) change(ls,l,mid,x,v);
		else change(rs,mid+1,r,x,v);
		tree[now]=min(tree[ls],tree[rs]);
	}
	int query(int now,int l,int r,int x,int y){
		if (x>y) return INF;
		if (x<=l&&r<=y) return tree[now];
		int mid=(l+r)>>1,res=INF;
		if (x<=mid) res=min(res,query(ls,l,mid,x,y));
		if (y>mid) res=min(res,query(rs,mid+1,r,x,y));
		return res;
	}
} T1,T2;
struct ST{
	int mn[21][410000];
	void init(){
		for (int i=1;i<=n;i++) mn[0][i]=a[i];
		for (int j=1;j<=20;j++)
			for (int i=1;i+(1<<j)-1<=n;i++)
				mn[j][i]=min(mn[j-1][i],mn[j-1][i+(1<<(j-1))]);
	}
	int query(int l,int r){
		if (l>r) swap(l,r);
		int k=Log2[r-l+1];
		return min(mn[k][l],mn[k][r-(1<<k)+1]);
	}
} s;
int top,st[410000];
void push(int x){//x in st   <=>   suffix min
	while (top&&a[st[top]]>a[x]) top--;
	st[++top]=x;
	T1.change(1,1,n,top,-2*x+a[x]);
	T2.change(1,1,n,top,-2*x-a[x]);
}
int find_pos1(int x){
	int l=1,r=top,res=0;
	while (l<=r){
		int mid=(l+r)>>1;
		if (st[mid]<=x) res=mid,l=mid+1;
		else r=mid-1;
	}
	return res;
}
int find_pos2(int x){
	int l=1,r=top,res=top+1;
	while (l<=r){
		int mid=(l+r)>>1;
		if (st[mid]>=x) res=mid,r=mid-1;
		else l=mid+1;
	}
	return res;
}
int find_num(int l,int r,int v){
	int res=r+1;
	while (l<=r){
		int mid=(l+r)>>1;
		if (a[st[mid]]>v) res=mid,r=mid-1;
		else l=mid+1;
	}
	return res;
}
/*
a_i>c_2: 2*(r_1-i)+abs(r_2-r_1)+(a_i-c_2)
a_i<=c_2: 2*(r_1-i)+abs(r_2-r_1)+(c_2-a_i)
*/
void upd(node u){
	int pos=find_pos2(u.r1);//the first (pos>=u.r1) in stack
	int x=find_num(pos+1,top,u.c2);//the first (num>c2) in stack
	int v1=INF,v2=INF;
	if (x>1&&st[x-1]>=u.r1) v1=abs(u.r2-u.r1)+abs(a[st[x-1]]-u.c2)+1;
	if (x<=top&&st[x]>=u.r1) v2=abs(u.r2-u.r1)+abs(a[st[x]]-u.c2)+1;
	Ans[u.id]=min(Ans[u.id],min(v1,v2));
}
void upd1(node u){
	int c=min(u.c1,s.query(u.r1,u.r2)); upd(u);
	int pos=find_pos1(u.r1);//the last (pos<=u.r1) in stack
	int x=find_num(1,pos,c);//the first (num>c) in stack
	int y=find_num(1,pos,u.c2);//the first (num>q.c2) in stack
	int v1=INF,v2=INF;
	if (c>=u.c2){
		//(num>c) is worse than Case 2
		v1=T1.query(1,1,n,y,x-1)+2*u.r1+abs(u.r2-u.r1)-u.c2;//a_i>c2
		v2=T2.query(1,1,n,1,y-1)+2*u.r1+abs(u.r2-u.r1)+u.c2;//a_i<=c2
	} else{
		//Up and not End is worse than Case 2
		//(num<=c) is worse than Case 2
		v1=T1.query(1,1,n,y,pos)+2*u.r1+abs(u.r2-u.r1)-u.c2+1;//a_i>c2
		v2=T2.query(1,1,n,x,y-1)+2*u.r1+abs(u.r2-u.r1)+u.c2+1;//a_i<=c2
	}
	Ans[u.id]=min(Ans[u.id],min(v1,v2));
}
void upd2(node u){
	int c=min(u.c1,s.query(u.r1,u.r2));
	int pos=find_pos1(u.r2);//the last (pos<=u.r2) in stack
	int x=find_num(1,pos,c);//the first (num>c) in stack
	int y=find_num(1,pos,u.c2);//the first (num>q.c2) in stack
	int v1,v2;
	if (c>=u.c2){
		//(num>c) is worse than Case 2
		v1=T1.query(1,1,n,y,x-1)+2*u.r2+abs(u.r2-u.r1)-u.c2;//a_i>c2
		v2=T2.query(1,1,n,1,y-1)+2*u.r2+abs(u.r2-u.r1)+u.c2;//a_i<=c2
	} else{
		//Up and not End is worse than Case 2
		//(num<=c) is worse than Case 2
		v1=T1.query(1,1,n,y,pos)+2*u.r2+abs(u.r2-u.r1)-u.c2+1;//a_i>c2
		v2=T2.query(1,1,n,x,y-1)+2*u.r2+abs(u.r2-u.r1)+u.c2+1;//a_i<=c2
	}
	Ans[u.id]=min(Ans[u.id],min(v1,v2));
}
void solve(){
	s.init();
	for (int i=1;i<=Q;i++){
		int c=s.query(q[i].r1,q[i].r2);
		Ans[q[i].id]=min(Ans[q[i].id],abs(q[i].r2-q[i].r1)+abs(min(c,q[i].c1)-q[i].c2));
		/*
			Case 2-1: Down/up - Left/Right
			(r1,c1)  -Down/up...- (r2,min(c1,c)) -Left/Right...-  (r2,c2)
		*/
	}
	sort(q+1,q+Q+1);
	T1.build(1,1,n); T2.build(1,1,n);
	int j=1; top=0;
	for (int i=1;i<=n;i++){
		push(i);
		for (;j<=Q&&q[j].r2==i;j++)
			if (q[j].r1<=q[j].r2) upd1(q[j]);
			else upd2(q[j]);
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	Log2[1]=0; for (int i=2;i<=n;i++) Log2[i]=Log2[i>>1]+1;
	scanf("%d",&Q);
	for (int i=1;i<=Q;i++){
		scanf("%d%d%d%d",&q[i].r1,&q[i].c1,&q[i].r2,&q[i].c2);
		q[i].id=i; Ans[i]=abs(q[i].r1-q[i].r2)+q[i].c2+1;
		/*
			Case 1: Home - Down/Up - Right
			(r1,c1)  -Home-  (r1,1)  -Down/Up...-  (r2,1)  -Right...-  (r2,c2)
		*/
	}
	/*
		Case 3: Up... - (End) - Down...
		(r1,c1) -Up...- (?,?) -(End) - (?,?) - Down... (r2,c2)
	*/
	solve();
//	for (int i=1;i<=Q;i++) printf("%d ",Ans[i]);

	reverse(a+1,a+n+1);
	for (int i=1;i<=Q;i++){
		q[i].r1=n-q[i].r1+1;
		q[i].r2=n-q[i].r2+1;
	}
	/*
		Case 4: Down... - (End) - Up...
		(r1,c1) -Down...- (?,?) -(End) - (?,?) - Up... (r2,c2)
	*/
	solve();

	for (int i=1;i<=Q;i++) printf("%d\n",Ans[i]);
	return 0;
}