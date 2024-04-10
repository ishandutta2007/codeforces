#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9;
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int answer[N];
struct node{
	int val,id;
	bool operator<(const node&x)const{
		return val<x.val;
	}
}a[N];
int rt;
inline int min(int &x,int &y){
	return x<y?x:y;
}
inline int max(int &x,int &y){
	return x>y?x:y;
}
struct tree{
	#define ls t[p].l
	#define rs t[p].r
	int idx;
	tree(){
		idx=0;
	}
	struct point{
		int l,r,mx,mn,tag;
		point(){
			l=r=tag=0;
			mx=0,mn=0;
		}
	}t[N<<2];
	inline void f(int p,int tag){
		t[p].mn+=tag;
		t[p].mx+=tag;
		t[p].tag+=tag;
		return;
	}
	inline void push_down(int p){
		f(ls,t[p].tag);
		f(rs,t[p].tag);
		t[p].tag=0;
	}
	inline void push_up(int p){
		t[p].mn=min(t[ls].mn,t[rs].mn);
		t[p].mx=max(t[ls].mx,t[rs].mx);
		return;
	}
	void build(int &p,int l,int r){
		if(!p)p=++idx;
		if(l==r)return;
		int mid=(l+r)>>1;

		build(ls,l,mid);
		build(rs,mid+1,r);
		return;
	}
	void add(int p,int l,int r,int nl,int nr,int val){
		if(nl<=l&&r<=nr){
			t[p].mn+=val;
			t[p].mx+=val;
			t[p].tag+=val;
			return;
		}
		int mid=(l+r)>>1;push_down(p);
		if(mid>=nl)add(ls,l,mid,nl,nr,val);
		if(mid<nr)add(rs,mid+1,r,nl,nr,val);
		push_up(p);
		return;
	}
	int findmn(int p,int l,int r,int nl,int nr){
		if(nl<=l&&r<=nr)return t[p].mn;
		int mid=(l+r)>>1;int res=1e9;
		push_down(p);
		if(mid>=nl)res=min(res,findmn(ls,l,mid,nl,nr));
		if(mid<nr)res=min(res,findmn(rs,mid+1,r,nl,nr));
		push_up(p);
		return res;	
	}
	int findmx(int p,int l,int r,int nl,int nr){
		if(nl<=l&&r<=nr)return t[p].mx;
		int mid=(l+r)>>1;int res=-1e9;
		push_down(p);
		if(mid>=nl)res=max(res,findmx(ls,l,mid,nl,nr));
		if(mid<nr)res=max(res,findmx(rs,mid+1,r,nl,nr));
		push_up(p);
		return res;	
	}
}T1,T2;
signed main(){
	int n=read();
	T1.build(rt=0,1,n),T2.build(rt=0,1,n);
	for(int i=1;i<=n;i++)
		a[i].val=read(),a[i].id=i;
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		T1.add(1,1,n,i,n,-1);
		T2.add(1,1,n,1,i,-1);
	}
	for(int i=1;i<=n;){
		int j=i;
		while(a[j+1].val==a[i].val)j++;
		for(int k=i;k<=j;k++){
			int x=a[k].val;
			int ans=0;
			ans=max(ans,abs(T1.findmn(1,1,n,a[k].id,n)+T2.findmn(1,1,n,1,a[k].id)-
							T1.findmn(1,1,n,a[k].id,a[k].id)-T2.findmn(1,1,n,a[k].id,a[k].id))+1);
			ans=max(ans,abs(T1.findmx(1,1,n,a[k].id,n)+T2.findmx(1,1,n,1,a[k].id)-
							T1.findmx(1,1,n,a[k].id,a[k].id)-T2.findmx(1,1,n,a[k].id,a[k].id)));
			answer[a[k].id]=max(answer[a[k].id],ans);
		}
		for(int k=i;k<=j;k++){
			T1.add(1,1,n,a[k].id,n,2);
			T2.add(1,1,n,1,a[k].id,2);
		}
		for(int k=i;k<=j;k++){
			int x=a[k].val;
			int ans=0;
			ans=max(ans,abs(T1.findmn(1,1,n,a[k].id,n)+T2.findmn(1,1,n,1,a[k].id)-
							T1.findmn(1,1,n,a[k].id,a[k].id)-T2.findmn(1,1,n,a[k].id,a[k].id))+1);
			ans=max(ans,abs(T1.findmx(1,1,n,a[k].id,n)+T2.findmx(1,1,n,1,a[k].id)-
							T1.findmx(1,1,n,a[k].id,a[k].id)-T2.findmx(1,1,n,a[k].id,a[k].id)));
			answer[a[k].id]=max(answer[a[k].id],ans);
		}
		i=j+1;
	}
	for(int i=1;i<=n;i++)printf("%d ",answer[i]/2);
	return 0;
}