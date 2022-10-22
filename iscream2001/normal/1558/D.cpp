#include<bits/stdc++.h>
#define LL long long
#define LD long double
#define pa pair<int,int>
using namespace std;
const LL P=998244353;
const int INF=1e9;
const int N=3e5+10;
int n,m;
int has=0,sz=0,root=0;
inline int HAS(){return has>0?has=has*109%100003:has=107;}
struct Treap{
    int ch[2],rnd,v,sum,siz;
    Treap(int vv=0){ch[0]=ch[1]=0;v=vv;sum=vv;siz=1;rnd=HAS();}
}tr[N];
inline void update(int x){
	tr[x].sum=tr[tr[x].ch[0]].sum+tr[tr[x].ch[1]].sum+tr[x].v;
    tr[x].siz=tr[tr[x].ch[0]].siz+tr[tr[x].ch[1]].siz+1;
}
int Merge(int x,int y){
    if(!x) return y;
    if(!y) return x;
    if(tr[x].rnd<tr[y].rnd){
        tr[x].ch[1]=Merge(tr[x].ch[1],y);update(x);return x;
    }
    else{
        tr[y].ch[0]=Merge(x,tr[y].ch[0]);update(y);return y;
    }
}
pa Split(int x,int k){
    if(!x) return pa(0,0);
    pa y;
    if(tr[tr[x].ch[0]].siz>=k){
        y=Split(tr[x].ch[0],k);
        tr[x].ch[0]=y.second;update(x);y.second=x;
    }
    else{
        y=Split(tr[x].ch[1],k-tr[tr[x].ch[0]].siz-1);
        tr[x].ch[1]=y.first;update(x);y.first=x;
    }
    return y;
}
int Getkth(int x,int v){
    if(!x) return 0;
    if(tr[tr[x].ch[0]].sum>=v) return Getkth(tr[x].ch[0],v);
    if(tr[x].sum-tr[tr[x].ch[1]].sum>=v) return tr[tr[x].ch[0]].siz+1;
    return Getkth(tr[x].ch[1],v-tr[tr[x].ch[0]].sum-tr[x].v)+tr[tr[x].ch[0]].siz+1;
}
LL fac[N+N],inv[N+N];
LL qpow(LL x,LL y){
	LL re=1;
	while(y){
		if(y&1) re=re*x%P;
		x=x*x%P;y>>=1;
	}
	return re;
}
LL C(int x,int y){
	if(x<y) return 0;
	return fac[x]*inv[y]%P*inv[x-y]%P;
}
void init(){
	fac[0]=fac[1]=inv[0]=inv[1]=1;
	for(LL i=2;i<=400000;++i){
		fac[i]=fac[i-1]*i%P;
	}
	inv[400000]=qpow(fac[400000],P-2);
	for(LL i=400000;i>1;--i){
		inv[i-1]=inv[i]*i%P;
	}
	return;
}
struct edge{
	int r,l;
}e[200005];
void MAIN(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		scanf("%d%d",&e[i].r,&e[i].l);
	}
	has=0;sz=1;root=1;
	tr[1]=Treap(1);
	pa X,Y;
	int u,v;
	for(int i=2,j=1;i<=n;){
		if(j>m||e[j].r!=i){
			X=Split(root,sz-1);
			v=X.second;
			if(j>m){
				tr[v].v+=n-i+1;
				tr[v].sum+=n-i+1;
				root=Merge(X.first,v);
				i=n+1;
				continue;
			}
			tr[v].v+=e[j].r-i;
			tr[v].sum+=e[j].r-i;
			root=Merge(X.first,v);
			i=e[j].r;
			continue;
		}
		//cout<<sz<<endl;
		else{
			if(e[j].l==1){
				tr[++sz]=Treap(1);
				root=Merge(sz,root);
			}
			else{
				u=Getkth(root,e[j].l-1);
				X=Split(root,u);
				u=X.first;
				v=tr[u].sum-(e[j].l-1);
				Y=Split(u,tr[u].siz-1);
				u=Y.second;
				if(v>0){
					tr[u].v-=v;
					tr[u].sum-=v;
					++tr[u].v;
					++tr[u].sum;
					tr[++sz]=Treap(v);
					u=Merge(u,sz);
				}
				else{
					++tr[u].v;
					++tr[u].sum;
				}
				root=Merge(Merge(Y.first,u),X.second);
			}
			++j;++i;
		}
		
	}
	//cout<<sz<<endl;
	printf("%lld\n",C(n+n-sz,n));
	return;
} 

int main(){
	init();
	tr[0].siz=0;tr[0].rnd=INF;
	int ttt=1;scanf("%d",&ttt);
	while(ttt--) {
		MAIN();
	}
	return 0;
}
/*
3
3 2
2 1
3 1
*/