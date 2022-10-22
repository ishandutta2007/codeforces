#include<bits/stdc++.h>
using namespace std;
int T,n,m,a[1100],b[1100],c[1100],d[1100],tmp[1100];
bitset<1000005> dp[1005];
bool work(int *a,int s,int *b){
	dp[0].reset(); dp[0][0]=1;
	for (int i=1;i<=n;i++) dp[i]=dp[i-1]|(dp[i-1]<<a[i]);
	if (!dp[n][s]) return false;
	int len=0,len2=0;
	for (int i=n;i>=1;i--)
		if (s>=a[i]&&dp[i-1][s-a[i]]) b[++len]=a[i],s-=a[i];
		else tmp[++len2]=-a[i];
	for (int i=1;i<=len2;i++) b[++len]=tmp[i];
	return true;
}
int main(){
	scanf("%d",&T); int p,q;
	while (T--){
		p=0; q=0;
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]),p+=a[i];
		scanf("%d",&m);
		for (int i=1;i<=m;i++) scanf("%d",&b[i]),q+=b[i];
		if ((n!=m)||(p&1)||(q&1)){
			puts("No");
			continue;
		}
		p>>=1; q>>=1;
		
		sort(a+1,a+n+1); sort(b+1,b+n+1);
		if (!work(a,p,c)||!work(b,q,d)){
			puts("No");
			continue;
		}
		puts("Yes"); reverse(d+1,d+n+1);
		p=0; q=0;
		for(int i=1;i<=n;i++){
			p+=c[i]; printf("%d %d\n",p,q);
			q+=d[i]; printf("%d %d\n",p,q);
		}
	}
	return 0;
}