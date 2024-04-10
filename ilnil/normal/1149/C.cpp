#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;i--)
#define ll long long
#define db long double
#define ls o*2
#define rs o*2+1
#define put putchar
using namespace std;
const int N=2e5+5,mo=1e9+7;
int n,q,x,y;
char c[N];
int ans[N*4],a[N*4],b[N*4],rp[N*4],rm[N*4],lp[N*4],lm[N*4];
void fz(int o,int i){
	a[o]=b[o]=lm[o]=rm[o]=0;
	if(c[i]=='(')b[o]=1,lm[o]=1;
	else a[o]=1,rm[o]=1;
	ans[o]=1;rp[o]=lp[o]=1;
}
void up(int o){
	a[o]=a[ls]+max(a[rs]-b[ls],0);
    b[o]=b[rs]+max(b[ls]-a[rs],0);
    rp[o]=max(rp[rs],max(rp[ls]-a[rs]+b[rs],rm[ls]+a[rs]+b[rs]));
    rm[o]=max(rm[rs],rm[ls]+a[rs]-b[rs]);
    lp[o]=max(lp[ls],max(lp[rs]+a[ls]-b[ls],lm[rs]+a[ls]+b[ls]));
    lm[o]=max(lm[ls],lm[rs]-a[ls]+b[ls]);
    ans[o]=max(max(ans[ls],ans[rs]),max(rp[ls]+lm[rs],rm[ls]+lp[rs]));
}
void B(int o,int l,int r){
	if(l==r){
		fz(o,l);
		return;
	}
	int m=l+r>>1;
	B(ls,l,m);B(rs,m+1,r);
	up(o);
}
void ch(int o,int l,int r,int x){
	if(l==r){
		fz(o,l);
		return;
	}
	int m=l+r>>1;
	if(x<=m)ch(ls,l,m,x);else ch(rs,m+1,r,x);
	up(o);
}
int main(){
	scanf("%d%d",&n,&q);
	scanf("\n%s",c+1);
	c[0]='(';c[n*2-1]=')';
	B(1,1,n*2-2);
	printf("%d\n",ans[1]);
	for(;q--;){
		scanf("%d%d",&x,&y);
		if(c[x]!=c[y]){
			swap(c[x],c[y]);
			ch(1,1,n*2-2,x);
			ch(1,1,n*2-2,y);
		}
		printf("%d\n",ans[1]);
	}
}