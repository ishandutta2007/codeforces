#include <bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;char ch=getchar();
	while ((ch!='-')&&(!isdigit(ch))) ch=getchar();
	if (ch=='-') f=-1,ch=getchar();
	while (isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
long long mid,j,a[1001010],pre[1001010],st1[201010][22],st[201010][22],lg[1001010];
long long n,i,l,r,L,R,down[1001010],up[1001010];
long long findmin(long long l,long long r){
	int len=lg[r-l+1];
	return min(st1[l][len],st1[r-(1<<len)+1][len]);
}
long long findmax(long long l,long long r){
	int len=lg[r-l+1];
	return max(st[l][len],st[r-(1<<len)+1][len]);
}
void Main(){
	n=read();
	for (i=1;i<=n;i++) a[i]=read();
	for (i=1;i<=n;i++) st[i][0]=a[i]; 
	for (j=1;j<=lg[n];j++)
	   for (i=1;i<=n-(1<<j)+1;i++)
	      st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	for (i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	for (i=1;i<=n;i++){
		l=1;r=i-1;down[i]=i;
		while (l<=r){
			mid=(l+r)>>1;
			if (findmax(mid,i)<=a[i]){
				down[i]=mid;r=mid-1;
			}else l=mid+1;
		    }
	    l=i+1;r=n;up[i]=i;
	    while (l<=r){
	    	mid=(l+r)>>1;
	    	if (findmax(i,mid)<=a[i]){
	    		up[i]=mid;l=mid+1;
			}else r=mid-1;
		}
		}
	for (i=1;i<=n;i++) st[i][0]=pre[i]; 
	for (j=1;j<=lg[n];j++)
	   for (i=1;i<=n-(1<<j)+1;i++)
	      st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	
	for (i=1;i<=n;i++) st1[i][0]=pre[i-1]; 
	for (j=1;j<=lg[n];j++)
	   for (i=1;i<=n-(1<<j)+1;i++)
	      st1[i][j]=min(st1[i][j-1],st1[i+(1<<(j-1))][j-1]);
	for (i=1;i<=n;i++){
		R=findmax(i,up[i]);L=findmin(down[i],i);
		if (R-L>a[i]) {
			puts("NO");return ;
		}
	}
	puts("YES");
	return ;
}
int main() {
	int Testing=read();
	for (i=2;i<=1000000;i++) lg[i]=lg[i>>1]+1;
	for (;Testing;Testing--) Main();
	return 0;
}