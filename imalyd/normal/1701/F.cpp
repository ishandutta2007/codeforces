#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int n=200001,MN=n+5;
inline ll C2(ll a){
	return ((a*(a-1ll))>>1);
}
struct node{
	ll len,tb,a,b,b2,ab,ab2;
	inline void inc(){
		++a;
		ab+=b;
		ab2+=b2;
	}
	inline void dec(){
		--a;
		ab-=b;
		ab2-=b2;
	}
	/*
	inline void pta(ll c){
		ta+=c;
		c*=len;
		a+=c;
		ab2+=c*b2;
	}*/
	inline void ptb(ll c){
		tb+=c;
		ll cc=C2(c);
		ab2+=ab*c+a*cc;
		ab+=a*c;
		b2+=b*c+len*cc;
		b+=len*c;
	}
	inline void incb(){
		++tb;
		ab2+=ab;
		ab+=a;
		b2+=b;
		b+=len;
	}
	inline void decb(){
		--tb;
		b-=len;
		b2-=b;
		ab-=a;
		ab2-=ab;
	}
}t[1<<19];

inline void pd(int v){
	if(t[v].tb){
		t[v<<1  ].ptb(t[v].tb);
		t[v<<1|1].ptb(t[v].tb);
		t[v].tb=0ll;
	}
}

inline void pu(int v){
	node &tv=t[v],&l=t[v<<1],&r=t[v<<1|1];
	tv.a=l.a+r.a;
	tv.b=l.b+r.b;
	tv.b2=l.b2+r.b2;
	tv.ab=l.ab+r.ab;
	tv.ab2=l.ab2+r.ab2;
}

#define ls o<<1,l,mid
#define rs o<<1|1,mid+1,r

int LL,RR;
inline void inc(int o,int l,int r){
	if(l==r){t[o].inc();return;}
	pd(o);
	int mid=((l+r)>>1);
	if(LL<=mid)inc(ls);else inc(rs);
	pu(o);
}
inline void dec(int o,int l,int r){
	if(l==r){t[o].dec();return;}
	pd(o);
	int mid=((l+r)>>1);
	if(LL<=mid)dec(ls);else dec(rs);
	pu(o);
}
void build(int o,int l,int r){
	t[o].len=r-l+1;
	if(l==r){return;
	}
	int mid=((l+r)>>1);
	build(ls);
	build(rs);
}
void debug(int o,int l,int r){
	printf("%d [%d,%d] tb=%lld %lld %lld %lld %lld\n",o,l,r,t[o].tb,t[o].a,t[o].b,t[o].b2,t[o].ab2);
	if(l==r){return;}
	int mid=((l+r)>>1);
	debug(ls);
	debug(rs);
}
void incb(int o,int l,int r){
	if(LL<=l&&r<=RR){
		//printf("+ %d %d %d\n",o,l,r);
		t[o].incb();return;
	}
	pd(o);
	int mid=((l+r)>>1);
	if(LL<=mid)incb(ls);
	if(RR> mid)incb(rs);
	pu(o);
}

void decb(int o,int l,int r){
	if(LL<=l&&r<=RR){
		//printf("- %d %d %d\n",o,l,r);
		t[o].decb();return;
	}
	pd(o);
	int mid=((l+r)>>1);
	if(LL<=mid)decb(ls);
	if(RR> mid)decb(rs);
	pu(o);
}

set<int> S;
int main(){
	build(1,1,n);
	int q,d,a;
	cin>>q>>d;while(q--){
		cin>>a;++a;
		if(S.find(a)==S.end()){
			S.insert(a);
			LL=a;
			inc(1,1,n);
			LL=max(a-d,1);RR=a-1;
			//printf("rrr %d %d\n",LL,RR);
			incb(1,1,n);
		}else{
			S.erase(a);
			LL=a;
			dec(1,1,n);
			LL=max(a-d,1);RR=a-1;
			//printf("ddd %d %d\n",LL,RR);
			decb(1,1,n);
		}
		printf("%lld\n",t[1].ab2);
		//debug(1,1,n);
	}
	return 0;
}
//use long long