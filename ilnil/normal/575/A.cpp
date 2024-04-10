#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define ll long long
#define G(L,R)(o=E,pl=L,pr=R,get(1,0,n-1))
using namespace std;
const int N=50005;
ll k;
int mo,n,m,s[N],pl,pr;
struct no{ll i;int v;}a[N];
bool cmp(no a,no b){return a.i<b.i;}
struct mat{int a[2][2];}t[N*4],E={1,0,0,1},an,o,f[66];
mat operator*(const mat &a,const mat &b){
	mat c;
	c.a[0][0]=((ll)a.a[0][0]*b.a[0][0]+(ll)a.a[0][1]*b.a[1][0])%mo;
	c.a[0][1]=((ll)a.a[0][0]*b.a[0][1]+(ll)a.a[0][1]*b.a[1][1])%mo;
	c.a[1][0]=((ll)a.a[1][0]*b.a[0][0]+(ll)a.a[1][1]*b.a[1][0])%mo;
	c.a[1][1]=((ll)a.a[1][0]*b.a[0][1]+(ll)a.a[1][1]*b.a[1][1])%mo;
	return c;
}
void B(int v,int l,int r){
	if(l==r){
		t[v]=(mat){0,s[(l+n-1)%n],1,s[l]};
		return;
	}
	int m=l+r>>1;
	B(v*2,l,m);B(v*2+1,m+1,r);
	t[v]=t[v*2]*t[v*2+1];
}
void get(int v,int l,int r){
	if(pl<=l&&r<=pr){
		o=o*t[v];
		return;
	}
	int m=l+r>>1;
	if(pl<=m)get(v*2,l,m);
	if(m<pr)get(v*2+1,m+1,r);
}
void chs(ll l,ll r){
	--r;
	if(l>r)return;
	if(l/n==r/n){
		G(l%n,r%n);
		an=an*o;
		return;
	}
	G(l%n,n-1);
	an=an*o;
	ll w=r/n-l/n-1;
	fo(i,0,60){
		if((ll)1<<i>w)break;
		if(w&((ll)1<<i))an=an*f[i];
	}
	G(0,r%n);
	an=an*o;
}
int main(){
	cin>>k>>mo>>n;
	if(!k)return printf("0"),0;
	fo(i,0,n-1)scanf("%d",&s[i]);
	cin>>m;
	fo(i,1,m)scanf("%lld%d",&a[i].i,&a[i].v);
	sort(a+1,a+m+1,cmp);
	for(;m&&a[m].i>=k;)--m;
	B(1,0,n-1);
	an=E;
	f[0]=t[1];
	fo(i,1,60){
		if((ll)1<<i>k/n)break;
		f[i]=f[i-1]*f[i-1];
	}
	if(!m){
		chs(1,k);
	}else{
		ll w=1;
		fo(i,1,m){
			if(w<=a[i].i){
				chs(w,a[i].i);w=a[i].i;
				an=an*(mat){0,s[(w+n-1)%n],1,a[i].v};++w;	
			}
			if(w==k)break;
			if(i<m&&a[i+1].i==a[i].i+1){
				an=an*(mat){0,a[i].v,1,a[i+1].v};++w;
				continue;
			}
			an=an*(mat){0,a[i].v,1,s[w%n]};++w;
		}
		if(w<k)chs(w,k);
	}
	cout<<an.a[1][1]%mo;
}