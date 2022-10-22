// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=1000010;
int i,j,k;
int n,m,a[maxn],b[maxn],t,mm,tt;
int ll[maxn],rr[maxn],mi[maxn];
int l[maxn],r[maxn];
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
void build(int x,int l,int r){
	int mid=(l+r)>>1;
	ll[x]=l; rr[x]=r;
	if (l==r){
		mi[x]=b[l];
		return;
	}
	build(x*2,l,mid); build(x*2+1,mid+1,r);
	mi[x]=min(mi[x*2],mi[x*2+1]);
}
void getans(int x,int l,int r){
	if ((l<=ll[x])&&(rr[x]<=r)){
		t=min(t,mi[x]); return;
	}
	if ((r<ll[x])||(rr[x]<l)) return;
	getans(x*2,l,r); getans(x*2+1,l,r);
}
int main(){
	n=read(); m=read();
	for (i=1;i<=n;i++) a[i]=read();
	for (i=1;i<=n;i++){
		mm=max(mm,a[i]);
		if (a[i]==0){ tt++; b[i]=max(b[i],b[i-1]); }
		else b[i]=a[i];
	}
	for (i=n;i>=1;i--){
		if (a[i]==0) b[i]=max(b[i],b[i+1]);
		else b[i]=a[i];
	}
	if (b[1]==0){
		printf("YES\n");
		for (i=1;i<=n;i++) printf("%d ",m); return 0;
	}
	if (mm!=m){
		if (tt==0){
			printf("NO\n"); return 0;
		}
		else{
			for (i=1;i<=n;i++){
				if (a[i]==0){ b[i]=m; break; }
			}
		}
	}
		build(1,1,n);
		for (i=1;i<=m;i++) l[i]=1e9;
		for (i=1;i<=n;i++){
			l[b[i]]=min(l[b[i]],i);
			r[b[i]]=max(r[b[i]],i);
		}
		for (i=1;i<=m;i++){
			if (l[i]!=1e9){
				t=1e9; getans(1,l[i],r[i]);
				if (t<i){
					printf("NO\n"); return 0;
				}
			}
		}
		printf("YES\n");
		for (i=1;i<=n;i++){
			printf("%d ",b[i]);
		}
	return 0;
}