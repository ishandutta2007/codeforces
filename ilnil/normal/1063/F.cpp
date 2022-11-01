#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define add(x,y)(x=((ll)y+x)%mo)
#define ll long long
using namespace std;
const int N=5e5+5;
int n,ans,L;
int rk[N],sa[N],tp[N],t[N],m,h[20][N],lg[N];
int T[N*4],f[N];
char a[N];
void Rsort(){
	fo(i,0,m)t[i]=0;
	fo(i,1,n)t[rk[tp[i]]]++;
	fo(i,1,m)t[i]+=t[i-1];
	fd(i,1,n)sa[t[rk[tp[i]]]--]=tp[i];
}
#define cmp(x,y)(tp[x]==tp[y]&&tp[x+w]==tp[y+w])
void SA(){
	fo(i,1,n)rk[i]=a[i],tp[i]=i;m=255;Rsort();
	for(int w=1,j=1;j<n;w<<=1,m=j){
		j=0;
		fo(i,n-w+1,n)tp[++j]=i;
		fo(i,1,n)if(sa[i]>w)tp[++j]=sa[i]-w;
		Rsort();
		swap(tp,rk);
		rk[sa[1]]=j=1;
		fo(i,2,n)rk[sa[i]]=cmp(sa[i],sa[i-1])?j:++j;
	}
	for(int i=1,k=0;i<=n;h[0][rk[i++]]=k)
		for(k=k?k-1:0;a[i+k]==a[sa[rk[i]+1]+k];++k);
	fo(i,1,lg[n]){
		int nx=1<<i-1;
		fo(j,1,n-nx*2+1)
			h[i][j]=min(h[i-1][j],h[i-1][j+nx]);
	}
}
int qry(int l,int r){
	--r;
	int k=lg[r-l];
	return min(h[k][l],h[k][r-(1<<k)+1]);
}
void ch(int v,int l,int r,int x){
	if(l==r){
		T[v]=T[v]?0:f[sa[x]];
		return;
	}
	int m=l+r>>1;
	if(x<=m)ch(v*2,l,m,x);else ch(v*2+1,m+1,r,x);
	T[v]=max(T[v*2],T[v*2+1]);
}
int qu(int v,int l,int r,int pl,int pr){
	if(pl<=l&&r<=pr)return T[v];
	int m=l+r>>1,a=0,b=0;
	if(pl<=m)a=qu(v*2,l,m,pl,pr);
	if(m<pr)b=qu(v*2+1,m+1,r,pl,pr);
	return max(a,b);
}
void move(int left){
	if(left<L)fd(i,left,L-1)ch(1,1,n,rk[i]);
	if(L<left)fo(i,L,left-1)ch(1,1,n,rk[i]);
	L=left;
}
bool ck2(int x,int k,int lim){
	int le=rk[x],ri=rk[x];
	for(int l=1,r=rk[x]-1,mid;mid=l+r>>1,l<=r;)
		if(qry(mid,rk[x])>=k)le=mid,r=mid-1;else l=mid+1;
	for(int l=rk[x]+1,r=n,mid;mid=l+r>>1,l<=r;)
		if(qry(rk[x],mid)>=k)ri=mid,l=mid+1;else r=mid-1;
	move(lim);
	return qu(1,1,n,le,ri)>=k;
}
bool ck(int x,int k){
	if(k==1)return 1;
	return ck2(x,k-1,x+k)||ck2(x+1,k-1,x+k);
}
int main(){
	scanf("%d\n%s",&n,a+1);
	fo(i,2,n)lg[i]=lg[i>>1]+1;
	SA();
	L=n+1;
	fd(i,1,n){
		fd(j,1,f[i+1]+1)
			if(ck(i,j)){
				f[i]=j;
				ans=max(ans,j);
				break;
			}
	}
	printf("%d\n",ans);
}