#include <bits/stdc++.h>
#define LL long long
#define LD long double
using namespace std;
const LL P=998244353;
const int N=3e5+10;
const int INF=1e9;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void print(LL x){
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
void pls(LL &x,LL y){
    x+=y;if(x>=P)x-=P;
}
const int E=320;
int n,Q;
int a[N],g[N],tag[N],mx[N],b[N];
void init(int i){
	int L=(i-1)*E+1,R=min(n,i*E);
	mx[i]=0;
	for(int j=L;j<=R;++j){
		if(a[j]>mx[i]) mx[i]=a[j];
    	if(a[j]<L) b[j]=j;
    	else b[j]=b[a[j]];
	}
}
void MAIN(){
	int L,R;
    n=read();Q=read();
    for(int i=2;i<=n;++i) a[i]=read();
    a[1]=1;
    for(int i=1;i<=n;++i) g[i]=(i+E-1)/E;
    for(int i=1;i<=g[n];++i) {
    	tag[i]=0;
    	init(i);
	}
    int op,l,r,x;
    while(Q--){
    	op=read();l=read();r=read();
    	if(op==1){
    		x=read();
    		if(g[l]==g[r]){
    			for(int i=l;i<=r;++i){
    				a[i]=max(a[i]-x,1);
				}
				if(mx[g[l]]>(g[l]-1)*E) init(g[l]);
			}
			else{
				for(int i=l;i<=g[l]*E;++i){
					a[i]=max(a[i]-x,1);
				}
				if(mx[g[l]]>(g[l]-1)*E) init(g[l]);
				
				for(int i=(g[r]-1)*E+1;i<=r;++i){
					a[i]=max(a[i]-x,1);
				}
				if(mx[g[r]]>(g[r]-1)*E) init(g[r]);
				
				for(int i=g[l]+1;i<g[r];++i){
					if(mx[i]<(i-1)*E) tag[i]+=x;
					else{
						for(int j=(i-1)*E+1;j<=i*E;++j){
							a[j]=max(a[j]-x,1);
						}
						init(i);
					}
				}
			}
		}
		else{
			while(1){
				if(l==r) break;
				if(l>r) swap(l,r);
				if(g[l]!=g[r]){
					r=max(a[b[r]]-tag[g[r]],1);
					continue;
				}
				if(b[l]!=b[r]){
					l=max(a[b[l]]-tag[g[l]],1);
					r=max(a[b[r]]-tag[g[r]],1);
					continue;
				}
				r=max(a[r]-tag[g[r]],1);
			}
			printf("%d\n",l);
		}
	}
	return;
}

int main(){
    int ttt=1;
    while(ttt--) MAIN();
    return 0;
}