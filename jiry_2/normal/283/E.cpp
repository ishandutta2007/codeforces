#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
int a[1000000],b[1000000],n,m,w[100100],r[100100],l[100010];
struct atom{
	int l,r;
}x[100100];
int getl(int k){
	int l=1,r=n+1,ans;
	while (l<r){
		int mid=l+r>>1;
		if (w[mid]<k) l=mid+1; else {r=mid; ans=mid;}
	}
	return ans;
}
int getr(int k){
	int l=1,r=n+1,ans;
	while (l<r){
		int mid=l+r>>1;
		if (w[mid]>k) r=mid; else {l=mid+1; ans=mid;}
	}
	return ans;
}
int compare(atom k1,atom k2){
	return k1.l<k2.l;
}
void addin(int k1,int k2,int k3){
	b[k1]^=1; a[k1]=k3-k2+1-a[k1];
}
void pushdown(int k1,int k2,int k3){
	if (b[k1]){
		int mid=k2+k3>>1; addin(k1*2,k2,mid); addin(k1*2+1,mid+1,k3); b[k1]=0;
	}
}
void add(int k1,int k2,int k3,int k4,int k5){
	if (k2>k5||k3<k4) return;
	if (k2>=k4&&k3<=k5){addin(k1,k2,k3); return;}
	pushdown(k1,k2,k3); int mid=k2+k3>>1;
	add(k1*2,k2,mid,k4,k5); add(k1*2+1,mid+1,k3,k4,k5);
	a[k1]=a[k1*2]+a[k1*2+1];
}
int find(int k1,int k2,int k3,int k4,int k5){
	if (k2>k5||k3<k4) return 0;
	if (k2>=k4&&k3<=k5) return a[k1];
	pushdown(k1,k2,k3); int mid=k2+k3>>1;
	return find(k1*2,k2,mid,k4,k5)+find(k1*2+1,mid+1,k3,k4,k5);
}
int compare1(atom k1,atom k2){
	return k1.l<k2.l;
}
int compare2(atom k1,atom k2){
	return k1.r>k2.r;
}
int main(){
	scanf("%d%d",&n,&m); for (int i=1;i<=n;i++) scanf("%d",&w[i]);
	sort(w+1,w+n+1);
	for (int i=1;i<=m;i++) scanf("%d%d",&x[i].l,&x[i].r);
	for (int i=1;i<=m;i++){x[i].l=getl(x[i].l); x[i].r=getr(x[i].r);}
	sort(x+1,x+m+1,compare1);
	memset(a,0x00,sizeof a);
	memset(b,0x00,sizeof b);
	int now=1; long long ans=0;
	for (int i=1;i<=n;i++){
		while (now<=m&&x[now].l<=i){
			if (x[now].l<x[now].r) add(1,1,n,x[now].l,x[now].r); now++;
		}
		r[i]=find(1,1,n,i+1,n);
	}
	memset(a,0x00,sizeof a);
	memset(b,0x00,sizeof b);
	now=1; sort(x+1,x+m+1,compare2);
	for (int i=n;i;i--){
		while (now<=m&&x[now].r>=i){
			if (x[now].l<x[now].r) add(1,1,n,x[now].l,x[now].r); now++;
		}
		l[i]=find(1,1,n,1,i-1);
	}
	for (int i=1;i<=n;i++) r[i]=n-i-r[i];
	ans=1ll*n*(n-1)*(n-2)/6;
	for (int i=1;i<=n;i++) ans=ans-1ll*(l[i]+r[i])*(l[i]+r[i]-1)/2; cout<<ans<<endl; 
	return 0;
}