#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define ll long long
#define F(x) *lower_bound(p,p+9,x)-x
#define vl v*2
#define vr v*2+1
using namespace std;
const int N=1e5+5;
int n,q,a[N];
int op,z,z2,pl,pr;
ll p[10];
struct tr{
	ll a,ad,mi,is,fl,fl2;
}t[N*4];
void up(int v){
	t[v].mi=min(t[vl].mi,t[vr].mi);
	t[v].is=t[vl].is==t[vr].is?t[vl].is:0;
}
void B(int v,int l,int r){
	if(l==r){
		t[v].is=t[v].a=a[l];
		t[v].mi=F(a[l]);
		return;
	}
	int m=l+r>>1;
	B(vl,l,m);B(vr,m+1,r);
	up(v);
}
void add2(int v,ll x){
	t[v].a+=x;
	t[v].is?t[v].is+=x:0;
	t[v].mi-=x;
	t[v].ad+=x;
}
void fill2(int v,ll fl,ll fl2){
	t[v].a=t[v].is=fl;
	t[v].ad=0;
	t[v].mi=fl2;
	t[v].fl=fl;
	t[v].fl2=fl2;
}
void dw(int v){
	if(t[v].fl){
		fill2(vl,t[v].fl,t[v].fl2);
		fill2(vr,t[v].fl,t[v].fl2);
		t[v].fl=t[v].fl2=0;
	}
	if(t[v].ad){
		add2(vl,t[v].ad);
		add2(vr,t[v].ad);
		t[v].ad=0;
	}
}
ll qu(int v,int l,int r,int x){
	if(l==r)return t[v].a;
	dw(v);
	int m=l+r>>1;
	return x<=m?qu(vl,l,m,x):qu(vr,m+1,r,x);
}
void fill(int v,int l,int r){
	if(pl<=l&&r<=pr){
		fill2(v,z,z2);
		return;
	}
	dw(v);
	int m=l+r>>1;
	if(pl<=m)fill(vl,l,m);
	if(m<pr)fill(vr,m+1,r);
	up(v);
}
void add(int v,int l,int r){
	if(pl<=l&&r<=pr){
		add2(v,z);
		return;
	}
	dw(v);
	int m=l+r>>1;
	if(pl<=m)add(vl,l,m);
	if(m<pr)add(vr,m+1,r);
	up(v);
}
void deal(int v,int l,int r){
	if(t[v].is){
		fill2(v,t[v].is,F(t[v].is));
		return;
	}
	dw(v);
	int m=l+r>>1;
	if(t[vl].mi<0)deal(vl,l,m);
	if(t[vr].mi<0)deal(vr,m+1,r);
	up(v);
}
int main(){
	cin>>n>>q;
	fo(i,1,n)scanf("%d",&a[i]);
	p[0]=1;
	fo(i,1,9)p[i]=p[i-1]*42;
	B(1,1,n);
	for(;q--;){
		scanf("%d%d",&op,&pl);
		if(op==1){
			printf("%lld\n",qu(1,1,n,pl));
			continue;
		}
		scanf("%d%d",&pr,&z);
		if(op==2)
			z2=F(z),fill(1,1,n);
		else
			for(;add(1,1,n),(t[1].mi<0?deal(1,1,n),0:0),t[1].mi==0;);
	}
}