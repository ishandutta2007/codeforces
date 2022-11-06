#include <bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;char ch=getchar();
	while ((ch!='-')&&(!isdigit(ch))) ch=getchar();
	if (ch=='-') f=-1,ch=getchar();
	while (isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
long long i,up[1001010],down[1001010],a[1001010],b[1001010],n,m,Q,l,r,mid,ans;
bool check(int mid){
	int i;
	for (i=1;i<=n;i++) down[i]=1e9,up[i]=-1e9;
	long long x,y;
	for (i=1;i<=mid;i++){
		x=(a[i]+1)/2,y=(b[i]+1)/2;
		if ((a[i] % 2==1)) down[x]=min(down[x],y);
		else up[x]=max(up[x],y);
	}
for (i=n-1;i>=1;i--) up[i]=max(up[i+1],up[i]);
for (i=1;i<=n;i++)
   if (up[i]>=down[i]) return false;
return true;
}
void Main(){
	n=read();m=read();Q=read();
	for (i=1;i<=Q;i++) a[i]=read(),b[i]=read();
	l=1;r=Q;ans=0;
	while (l<=r){
		mid=(l+r)/2;
		if (check(mid)){
			ans=mid;l=mid+1;
		}else r=mid-1;
	}
	for (i=1;i<=ans;i++) puts("YES");
	for (i=ans+1;i<=Q;i++) puts("NO");
}
int main() {
	int Testing=1;
	for (;Testing;Testing--) Main();
	return 0;
}