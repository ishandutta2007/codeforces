#include<bits/stdc++.h>
using namespace std;

#define N 100005
#define ll long long
#define ls (k<<1)
#define rs (k<<1|1)
#define mid (l+r>>1)

struct node{ll mat[2][2];}s[N<<2],e,tmp,ano,ee;
struct dif{ll pos;int v;}a[N];

int S[N],p,n,m,i,j,now,nxt;

bool cmp(dif aa,dif bb){return aa.pos<bb.pos;}

node mul(node aa,node bb){
	struct node ret;int i,j,k;
	for(i=0;i<2;++i)for(j=0;j<2;++j)
		for(ret.mat[i][j]=k=0;k<2;++k)(ret.mat[i][j]+=aa.mat[i][k]*bb.mat[k][j])%=p;
	return ret;
}

void build(int k,int l,int r){
	if(l==r){s[k].mat[0][0]=S[l];s[k].mat[1][0]=S[l-1];s[k].mat[0][1]=1;}
	else build(ls,l,mid),build(rs,mid+1,r),s[k]=mul(s[ls],s[rs]);
}

node prod(int k,int l,int r,int x,int y){
	if(x<=l&&r<=y)return s[k];
	if(x>r||y<l)return e;
	return mul(prod(ls,l,mid,x,y),prod(rs,mid+1,r,x,y));
}

node ksm(node aa,ll mi){
	struct node ret=e;
	for(;mi;mi>>=1,aa=mul(aa,aa))if(mi&1)ret=mul(ret,aa);return ret;
}

node cheng(ll l,ll r){
	if(l>r)return e;
	ll l_=(l-1)/n,r_=(r-1)/n;l=l-l_*n;r=r-r_*n;
//	cout<<l<<" "<<r<<" "<<l_<<" "<<r_<<"\n"; 
	if(l_==r_){return prod(1,1,n,l,r);}
	if(r_==l_+1){return mul(prod(1,1,n,l,n),prod(1,1,n,1,r));}
	return mul(mul(prod(1,1,n,l,n),ksm(prod(1,1,n,1,n),r_-l_-1)),prod(1,1,n,1,r));
}

ll F[2][2],k;

main(){
	e.mat[0][0]=e.mat[1][1]=1;
	cin>>k>>p>>n;for(i=0;i<n;++i)cin>>S[i];cin>>m;for(i=1;i<=m;++i){cin>>a[i].pos>>a[i].v;if(a[i].pos>=k)--m,--i;}S[n]=S[0];
	if(k==0)return cout<<0,0;
	sort(a+1,a+m+1,cmp);build(1,1,n);
	F[0][0]=1;
	for(i=1;i<=m;++i){
		ee.mat[0][0]=a[i].v;
		if(a[i-1].pos==a[i].pos-1){ee.mat[1][0]=a[i-1].v;}
		else ee.mat[1][0]=S[(a[i].pos-1)%n];
		ee.mat[0][1]=1;
		tmp=mul(cheng(a[i-1].pos+2-(i==1),a[i].pos-1),ee);
		if(a[i+1].pos!=a[i].pos+1&&a[i].pos+1!=k){
			ee.mat[0][0]=S[(a[i].pos+1)%n];
			ee.mat[0][1]=1;
			ee.mat[1][0]=a[i].v;
			tmp=mul(tmp,ee);
		}
		nxt=now^1;F[nxt][0]=(F[now][0]*tmp.mat[0][0]+F[now][1]*tmp.mat[1][0])%p;
		F[nxt][1]=(F[now][0]*tmp.mat[0][1]+F[now][1]*tmp.mat[1][1])%p;
		now=nxt;
	}tmp=cheng(a[m].pos+2-(m==0),k-1);
	cout<<(F[now][0]*tmp.mat[0][0]+F[now][1]*tmp.mat[1][0])%p;
}