// user:halahen
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=100010;
ll i,j,k;
ll n,m,a[maxn],b[maxn],mx,f[maxn],g[maxn];
ll l,r,mid,ans;
ll read(){
	ll tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int work1(ll x,ll mid){
	ll i,r=0,z;
	for (i=x;i<=m;i++){
		r++; b[r]=a[i];
	}
	for (i=1;i<x;i++){
		r++; b[r]=a[i]+n;
	}
	b[r+1]=b[1]+n;
	for (i=1;i<=r+1;i++){
		f[i]=-1e18*9; g[i]=f[i];
	}
	f[1]=-mid; g[1]=1;
	for (i=1;i<=r;i++){
		if (f[i]>=0) g[i]=max(g[i],mid+1);
		if (f[i]>=-mid) g[i]=max(g[i],(ll)1);
		if (f[i]-(b[i+1]-b[i])>=-mid) g[i+1]=max(g[i+1],mid-(b[i+1]-b[i])+1);
		f[i+1]=max(f[i+1],g[i]-(b[i+1]-b[i]));
	}
	if (f[r+1]>=-mid) return 1;
	return 0;
}
int work2(ll x,ll mid){
	ll i,r=0,z;
	for (i=x;i<=m;i++){
		r++; b[r]=a[i];
	}
	for (i=1;i<x;i++){
		r++; b[r]=a[i]+n;
	}
	b[r+1]=b[1]+n;
	for (i=1;i<=r+1;i++){
		f[i]=-1e18*9; g[i]=f[i];
	}
	f[1]=-mid+(b[2]-b[1]);
	for (i=1;i<=r;i++){
		if (f[i]>=0) g[i]=max(g[i],mid+1);
		if (f[i]>=-mid) g[i]=max(g[i],(ll)1);
		if (f[i]-(b[i+1]-b[i])>=-mid) g[i+1]=max(g[i+1],mid-(b[i+1]-b[i])+1);
		f[i+1]=max(f[i+1],g[i]-(b[i+1]-b[i]));
	}
	if (f[r+1]>=-mid+(b[2]-b[1])) return 1;
	return 0;
}
int check(ll mid){
	ll i,x=0;
	for (i=1;i<m;i++){
		if (a[i+1]-a[i]-1==mx) x=i+1;
	}
	if (x==0) x=1;
	if ((work1(x,mid)==1)||(work2(x,mid)==1)) return 1; else return 0;
}
int main(){
	n=read(); m=read();
	if (m==1){
		printf("%lld\n",n-1); return 0;
	}
	n=n;
	for (i=1;i<=m;i++){
		a[i]=read();
	}
	sort(a+1,a+m+1);
	for (i=1;i<m;i++){
		mx=max(a[i+1]-a[i]-1,mx);
	}
	mx=max(mx,n-a[m]+a[1]-1);
	l=mx/2; r=mx;
	while (l<=r){
		mid=(l+r)>>1;
		if (check(mid)==1){
			ans=mid; r=mid-1;
		}
		else l=mid+1;
	}
	printf("%lld\n",ans);
	return 0;
}