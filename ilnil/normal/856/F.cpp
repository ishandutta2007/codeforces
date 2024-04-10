#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define P pair<ll,ll>
#define ll long long
#define down(v)(t[v].ad?dw(v),0:0)
#define vl t[v].s[0]
#define vr t[v].s[1]
#define ul unsigned long long
#define rd()(A=A*B+CC)
using namespace std;
const int N=2e5+5;
ll A=1e9+7,B=998244353,CC=12345678;
int n,m,ww,ct[N*4],ts,rt,p,q;
ll C,w[N*4],x,y,d1,d2,dt,ydt;
struct no{ll x,y;}a[N],b[N];
struct tree{
	int s[2];
	ul ky;
	ll x,d,ad,mx,mx1;
	void add(ll a){
		x+=a;ad+=a;
		mx+=a;mx1+=a;
	}
	void init(ll _x,ll _d){
		x=_x;d=_d;mx=x-d+C;mx1=x;ky=rd();
	}
}t[N*8];
void up(int v){
	t[v].mx=max(t[v].x-t[v].d+C,max(t[vl].mx,t[vr].mx));
	t[v].mx1=max(t[v].x,max(t[vl].mx1,t[vr].mx1));
}
void dw(int v){
	if(vl)t[vl].add(t[v].ad);
	if(vr)t[vr].add(t[v].ad);
	t[v].ad=0;
}
template<class I>
void R(I &n){
	char c;for(n=0;(c=getchar())<'0'||c>'9';);
	for(;c<='9'&&c>='0';c=getchar())n=n*10+c-48;
}
void split(int v,int &v1,int &v2,ll d){
	if(!v){v1=v2=0;return;}down(v);
	if(t[v].d+dt<=d){
		v1=v;
		split(vr,vr,v2,d);
	}else{
		v2=v;
		split(vl,v1,vl,d);
	}
	up(v);
}
int mer(int v,int v1){
	if(!v||!v1)return v^v1;
	down(v);down(v1);
	if(t[v].ky<t[v1].ky){
		t[v].s[1]=mer(t[v].s[1],v1);
		up(v);
		return v;
	}
	t[v1].s[0]=mer(v,t[v1].s[0]);
	up(v1);
	return v1;
}
void get(){
	split(rt,rt,p,-C-1);
	split(p,p,q,C);
	if(rt){
		t[++ts].init(t[rt].mx1,-C-dt);
		rt=mer(rt,ts);
	}
	rt=mer(rt,p);
	if(q){
		t[++ts].init(t[q].mx-dt,C-dt);
		rt=mer(rt,ts);
		rt=mer(rt,q);
	}
}
int main(){
	R(n);R(m);R(C);
	fo(i,1,n)R(x),R(y),a[i]=(no){x,y},w[++ww]=x,w[++ww]=y;
	fo(i,1,m)R(x),R(y),b[i]=(no){x,y},w[++ww]=x,w[++ww]=y;
	sort(w+1,w+ww+1);ww=unique(w+1,w+ww+1)-w-1;
	fo(i,1,n)ct[lower_bound(w+1,w+ww+1,a[i].x)-w]++,ct[lower_bound(w+1,w+ww+1,a[i].y)-w]--;
	fo(i,1,m)ct[lower_bound(w+1,w+ww+1,b[i].x)-w]+=2,ct[lower_bound(w+1,w+ww+1,b[i].y)-w]-=2;
	w[ww+1]=w[ww];rt=ts=1;t[1].init(0,0);
	t[0].mx=t[0].mx1=-4e18;
	fo(i,1,ww){
		ll d=w[i+1]-w[i];
		ct[i]+=ct[i-1];
		if(ct[i]==1)d1+=d;
		if(ct[i]==2)d2+=d;
		if(ct[i]<3&&i<ww)continue;
		if(d1){
			t[rt].add(d1);dt+=d1;
			get();d1=0;
		}
		if(d2){
			dt-=d2;
			get();d2=0;
		}
		if(d){
			split(rt,rt,p,-C-1);
			split(p,p,q,C);
			if(rt)t[rt].add(d);
			if(p)t[p].add(d*2);
			if(q)t[q].add(d);
			rt=mer(rt,p);
			rt=mer(rt,q);
			get();
		}
	}
	printf("%I64d",t[rt].mx1);
}