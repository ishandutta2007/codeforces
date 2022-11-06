#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int N=2e5+10;
int a[N],b[N],c[N],n,m,q;
int nex[N],nx[N][20],la[N];
int ans[N];
int main(){
	cin>>n>>m>>q;
	for (int i=1;i<=n;i++)scanf("%d",&c[i]),nex[c[i-1]]=c[i];
	nex[c[n]]=c[1];
	for (int i=1;i<=m;i++)scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)la[i]=m+1;
	ans[m+1]=m+1;
	for (int i=0;i<20;i++)nx[m+1][i]=m+1;
	for (int i=m;i>=1;i--){
		nx[i][0]=la[nex[a[i]]];
		la[a[i]]=i;
		for (int u=1;u<20;u++)nx[i][u]=nx[nx[i][u-1]][u-1];
		int x=n-1,p=i;
		for (int u=19;~u;u--)
			if (x>=(1<<u))x-=(1<<u),p=nx[p][u];
		ans[i]=min(p,ans[i+1]);
	}
	while (q--){
		int l,r;
		scanf("%d%d",&l,&r);
		putchar('0'+(ans[l]<=r));
	}
}