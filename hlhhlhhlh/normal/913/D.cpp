#include<bits/stdc++.h>
using namespace std;
const int maxn=400010;
int n,m,i,j,k,l,r,mid,ans;
int anss,f[maxn],ff[maxn];
struct node{
	int x,y,z;
}a[maxn];
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c-'0'<0)||(c-'0'>9)){ if(c=='-') fh=-1; c=getchar(); }
	while ((c-'0'>=0)&&(c-'0'<=9)){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
bool cmp(node a,node b){
	return (a.y<b.y);
}
int check(int x){
	int i,t1=0,t2=0;
	for (i=1;i<=n;i++){
		if (a[i].x>=x){
			t1=t1+a[i].y;
			if (t1>m) return 0;
			t2++; ff[t2]=a[i].z;
			if (t2>=x) break;
		}
	}
	if ((t2<x)||(t1>m)) return 0;
	else{
		ans=x;
		anss=ans;
		for (i=1;i<=ans;i++){
			f[i]=ff[i];
		}
		return 1;
	}
}
int main(){
	n=read(); m=read();
	for (i=1;i<=n;i++){
		a[i].x=read(); a[i].y=read(); a[i].z=i;
	}
	sort(a+1,a+n+1,cmp);
	l=0; r=n; ans=0; anss=0;
	while (l<=r){
		mid=(l+r)/2;
		if (check(mid)==1) l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",ans);
	printf("%d\n",anss);
	for (i=1;i<=anss;i++) printf("%d ",f[i]);
	return 0;
}