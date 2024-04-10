#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;
int n,m,sz;
int root[500010],ls[500010*35],rs[500010*35],sum[500010*35];
inline int read()
{
    char ch=getchar();
    while(!(ch>='0'&&ch<='9'))ch=getchar();
    int x=0;
    while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=getchar();}
    return x;
}
void update(int l,int r,int x,int &y,int v)
{
    y=++sz;
    sum[y]=sum[x]+1;
    if(l==r)return;
    ls[y]=ls[x];rs[y]=rs[x];
    int mid=(l+r)>>1;
    if(v<=mid)update(l,mid,ls[x],ls[y],v);
    else update(mid+1,r,rs[x],rs[y],v);
}
int que(int L,int R,int tmp){
    int l=0,r=inf,mid,x,y,re=0;
    x=root[L];y=root[R];
    while(1){
    	if(l>=tmp){
    		return re+sum[y]-sum[x];
		}
		if(r<tmp){
			return re;
		}
		mid=(l+r)>>1;
		if(mid<tmp){
			l=mid+1;
			x=rs[x];y=rs[y];
		}
		else{
			re+=sum[rs[y]]-sum[rs[x]];
			r=mid;x=ls[x];y=ls[y];
		}
    }
    return re;
}
struct node{
	int s,a;
}a[500005];
bool cmp(node x,node y){
	return x.a<y.a;
}
int F[500005];
int main(){
	int D;
    n=read();D=read();
    for(int i=1;i<=n;){
    	a[i].s=read();
    	a[i].a=read();
    	if(a[i].s<D){
    		n--;
    		i--;
		}
		if(a[i].a<D){
			a[i].a=D;
		}
    	i++;
    }
    if(n==0){
    	puts("0");
    	return 0;
	}
    sort(a+1,a+1+n,cmp);
    int lim=inf;
    for(int i=1;i<=n;++i){
    	update(0,lim,root[i-1],root[i],a[i].s);
	}
	F[0]=0;
	a[0].a=D;
	int l,r,mid;
	for(int i=1;i<=n;++i){
		if(a[i].a==D){
			F[i]=i;
			continue;
		}
		F[i]=F[i-1];
		int L,R;
		L=a[i].s;
		if(a[i].s>=a[i].a){
			L=a[i].a-1;
		}
		l=0;r=n;
		while(l!=r){
			mid=(l+r+1)>>1;
			if(a[mid].a<=L) l=mid;
			else r=mid-1;
		}
		L=l;
		R=a[i].a;
		l=0;r=n;
		while(l!=r){
			mid=(l+r+1)>>1;
			if(a[mid].a<=R) l=mid;
			else r=mid-1;
		}
		R=l;
		int hhh=F[L]+que(L,R,a[i].a)+1;
		if(a[i].s>=a[i].a) --hhh;
		//cout<<hhh<<" "<<L<<" "<<F[L]<<" "<<que(L,R,a[i].a)<<endl;
		F[i]=max(F[i],hhh);
	}
    cout<<F[n]<<endl;
    return 0;
}