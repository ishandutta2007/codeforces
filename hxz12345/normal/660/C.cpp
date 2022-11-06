#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;char ch=getchar();
	while ((ch!='-')&&(!isdigit(ch))) ch=getchar();
	if (ch=='-') f=-1,ch=getchar();
	while (isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
queue<int> q;
int a[1001010];
int n,K,pos,i,x,num,ans;
int main(){
	n=read();K=read();
	for (i=1;i<=K+1;i++) q.push(0);
	for (i=1;i<=n;i++){
		x=read();a[i]=x;
		if (x==0) q.pop(),q.push(-i);
		num=q.front()+i;
		if (num>ans) ans=num,pos=i;
	}
	printf("%d\n",ans);
	for (i=1;i<=n;i++)
	    if ((i>=pos-ans+1)&&(i<=pos)) printf("1 ");
	    else printf("%d ",a[i]);
	puts("");
	return 0;
}