#include <bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;char ch=getchar();
	while ((ch!='-')&&(!isdigit(ch))) ch=getchar();
	if (ch=='-') f=-1,ch=getchar();
	while (isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
long long tot,n,i,m,ans,w,a[1001010],lsh[1001010],fre[1001010],b[1001010],c[1001010];
void Main(){
	n=read();
	for (i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for (i=1;i<=n;i++) lsh[i]=a[i];
	m=unique(lsh+1,lsh+n+1)-lsh-1;
	if (m==1){
		puts("0");
		return ;
	}
	if (m==2){
		ans=0;
		ans=max(ans,(lsh[2]-lsh[1])*2);
		printf("%lld\n",ans);
		return ;
	}
	ans=lsh[m]-lsh[1];
	for (i=1;i<=m;i++){
		if (i!=m){
			w=0;
			if (i<m-1) c[++w]=lsh[i+1]-lsh[i];
			if (i>1) c[++w]=lsh[i]-lsh[i-1];
			sort(c+1,c+w+1);
			ans=max(ans,c[1]+lsh[m]-lsh[i]);
		}
		if (i!=1){
			w=0;
			if (i>2) c[++w]=lsh[i]-lsh[i-1];
			if (i<m) c[++w]=lsh[i+1]-lsh[i];
			sort(c+1,c+w+1);
			ans=max(ans,c[1]+lsh[i]-lsh[1]);
		}
	}// 
	tot=1e18;
	for (i=2;i<m;i++)
	   tot=min(tot,lsh[i]-lsh[1]+lsh[i]-lsh[m]);
	for (i=1;i<=m-2;i++) ans=max(ans,lsh[i+1]+lsh[m]-2*lsh[i]);
	for (i=3;i<=m;i++) ans=max(ans,2*lsh[i]-lsh[i-1]-lsh[1]);
    ans=max(ans,tot);
	printf("%lld\n",ans);
	return ;
}
int main() {
	int Testing=read();
	for (;Testing;Testing--) Main();
	return 0;
}