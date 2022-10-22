#include<bits/stdc++.h>
using namespace std;
int n,k,lim,m,fa[110000];
bool check(int n){//n=2^k-1
	n++;
	return n==(n&-n);
}
int main(){
	scanf("%d%d",&n,&k); lim=max((n-3)/2,0);
	if (!(n&1)||(k>lim)||(k==check(n))||(n==9&&k==2)){
		puts("NO");
		return 0;
	}
	puts("YES");
	m=max(2*(k-1),0);
	for (int i=1;i<=m;i++)
		if (i&1) fa[i]=max(i-2,0);
		else fa[i]=max(i-1,0);
	for (int i=1;i<=n-m;i++){
		if (i==1) fa[i+m]=max(m-1,0);
		else fa[i+m]=(i>>1)+m;
	}
	if (check(n-m)&&k) fa[n-1]=2,fa[n]=2;
	for (int i=1;i<=n;i++) printf("%d ",fa[i]);
	return 0;
}