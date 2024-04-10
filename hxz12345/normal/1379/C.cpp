#include <bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;char ch=getchar();
	while ((ch!='-')&&(!isdigit(ch))) ch=getchar();
	if (ch=='-') f=-1,ch=getchar();
	while (isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
//a[i]+b[i]*x[i]-b[i]
//a[i]-b[i]+b[i]*x[i]
struct node{
	long long l,r,val;
} a[1001010];
long long l,r,mid,G,pre[1001010],n,m,i,now,ans;
bool cmp(node a,node b){return a.l>b.l;}
void Main(){
	n=read();m=read();
	for (i=1;i<=m;i++) a[i].l=read(),a[i].r=read(),a[i].val=a[i].l-a[i].r;
	sort(a+1,a+m+1,cmp);
	for (i=1;i<=m;i++) pre[i]=pre[i-1]+a[i].l;
	//0i-1 
	ans=0;
	for (i=1;i<=m;i++){
		//now,x(0<=x<i)
		//pre[x]+a[i].r*(n-x)+a[i].val
		//pre[x]+a[i].r*n-a[i].r*x+a[i].val
		//pre[x]-a[i].r*x->max 
		l=1;r=m;G=0;
		while (l<=r){
			mid=(l+r)/2;
			if (a[mid].l>=a[i].r){
				G=mid;l=mid+1;
			}
		else r=mid-1;
		}
		if (G<i) G=min(G,n-1),ans=max(ans,a[i].r*(n-1)-a[i].r*G+pre[G]+a[i].l);
		else 
		   G=min(G,n),ans=max(ans,a[i].r*(n)-a[i].r*G+pre[G]);
	}
printf("%lld\n",ans);
return ;
}
int main() {
	int Testing=read();
	for (;Testing;Testing--) Main();
	return 0;
}