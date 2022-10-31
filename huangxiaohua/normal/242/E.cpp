#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define b(x) (1<<((x)-1))

int i,j,k,n,m,t,op,a[100500];
ll ans=0;
class SB{
	public:
	int x,y,w,b,f[400500],res;
	bool t[400500];
	#define cl (id<<1)
	#define cr (cl+1)
	#define md ((l+r)>>1)
	#define get() f[id]=f[cl]+f[cr]
	
	void build(int id,int l,int r){
		if(l==r){
			if(a[l]&b)f[id]=1;
			return;
		}
		build(cl,l,md);build(cr,md+1,r);
		get();
	}
	
	void up(int id,int l,int r){
		f[id]=r-l+1-f[id];t[id]^=1;
	}
	
	void upd(int id,int l,int r){
		up(cl,l,md);up(cr,md+1,r);t[id]=0;
	}
	
	void add(int id,int l,int r){
		if(x<=l&&r<=y){
			f[id]=r-l+1-f[id];
			t[id]^=1;return;
		}
		if(t[id])upd(id,l,r);
		if(x<=md)add(cl,l,md);
		if(y>md)add(cr,md+1,r);
		get();
	}
	
	void que(int id,int l,int r){
		if(x<=l&&r<=y){
			res+=f[id];return;
		}
		if(t[id])upd(id,l,r);
		if(x<=md)que(cl,l,md);
		if(y>md)que(cr,md+1,r);
		get();
	}
}sb[25];

int main() {
    scanf("%d",&n);
    for(i=1;i<=n;i++){
    	scanf("%d",&a[i]);
	}
	for(i=1;i<=20;i++)sb[i].b=b(i),sb[i].build(1,1,n);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&op,&j,&k);
		for(i=1;i<=20;i++)sb[i].x=j,sb[i].y=k;
		if(op==2){
			scanf("%d",&k);
			for(i=1;i<=20;i++){
				if(k&b(i))sb[i].add(1,1,n);
			}
		}
		else{
			ans=0;
			for(i=1;i<=20;i++){
				sb[i].res=0;
				sb[i].que(1,1,n);
				ans+=1ll*sb[i].res*b(i);
			}
			printf("%lld\n",ans);
		}
	}
}