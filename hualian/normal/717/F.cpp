#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e5+9;
inline int read(){
	int x=0,f=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int q,n;
int ppp;
int a[N];
struct point{
	int tag,len;
	int o,d;
	int mno,mnd,mn;
	point(){
		tag=len=o=d=mno=mnd=0;
		mn=1e9+7;
	}
	void re(){
		tag=len=o=d=mno=mnd=0;
		mn=1e9+7;
		return;
	}
}t[N<<2],ans;
point merge(point x,point y){
	point res;
	if(x.len%2){
		swap(y.d,y.o);
		swap(y.mnd,y.mno);
	}	
	res.mn=min(x.mn,y.mn);
	res.d=x.d+y.d;
	res.o=x.o+y.o;
	res.mnd=min(x.mnd,y.mnd+(x.d-x.o));
	res.mno=min(x.mno,y.mno+(x.o-x.d));
	res.len=y.len+x.len;
	return res;
}
struct tree{
	#define ls (p<<1)
	#define rs (p<<1|1)
	void push_up(int p){
		t[p]=merge(t[ls],t[rs]);
		return;
	}
	void f(int p,int tag){
		int len=t[p].len;
		t[p].tag+=tag;
		t[p].d+=(len/2)*tag;
		t[p].o+=(len-len/2)*tag;
		t[p].mno+=tag;
		t[p].mn+=tag;
		if(len!=1)
			t[p].mnd=t[p].mnd;
		else t[p].mnd=0;
		return;
	}
	void push_down(int p){
		if(!t[p].tag)return;
		f(ls,t[p].tag);
		f(rs,t[p].tag);
		t[p].tag=0;return;
	}
	void build(int p,int l,int r){
		if(l==r){
			t[p].mn=a[l];
			t[p].d=0;
			t[p].o=a[l];
			t[p].len=1;
			t[p].mno=a[l];
			return;
		}int mid=(l+r)>>1;
		build(ls,l,mid);
		build(rs,mid+1,r);
		push_up(p);return;
	}
	void add(int p,int l,int r,int nl,int nr,int val){
		if(nl<=l&&r<=nr)return f(p,val);
		int mid=(l+r)>>1;push_down(p);
		if(mid>=nl)add(ls,l,mid,nl,nr,val);
		if(mid<nr)add(rs,mid+1,r,nl,nr,val);
		push_up(p);
		return;
	}
	void get(int p,int l,int r,int nl,int nr){
		if(nl<=l&&r<=nr){ans=merge(ans,t[p]);return;}
		int mid=(l+r)>>1;push_down(p);
		if(mid>=nl)get(ls,l,mid,nl,nr);
		if(mid<nr)get(rs,mid+1,r,nl,nr);
		push_up(p);
		return;
	}
	void print(int p,int l,int r){
		cout<<"P "<<p<<endl;
		if(ppp)printf("l:%lld  r:%lld o:%lld d:%lld mno:%lld mnd:%lld len:%lld\n",l,r,t[p].o,t[p].d,t[p].mno,t[p].mnd,t[p].len);
		if(l==r)return;
		int mid=l+r>>1;push_down(p);
		print(ls,l,mid);
		print(rs,mid+1,r);
		push_up(p);
		return;
	}
}T;
signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read()-1;
	T.build(1,1,n);
	q=read();
	while(q--){
		int op=read(),a,b,k;
		switch(op){
			case 1:{
				a=read()+1,b=read()+1,k=read();
				T.add(1,1,n,a,b,k);
				break;
			}
			case 2:{
				a=read()+1,b=read()+1;
				ans.re();T.get(1,1,n,a,b);
				if(ans.mnd<0||ans.mno<0||ans.mn<0){
					puts("0");continue;
				}
				
				if(ans.o-ans.d==0)puts("1");
				else puts("0");
				break;
			}
		}
	}
	return 0;
}
//never gonna give you up