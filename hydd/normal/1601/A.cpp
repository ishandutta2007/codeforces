#include<bits/stdc++.h>
using namespace std;
int T,n,a[210000];
int gcd(int a,int b){
	if (!b) return a;
	return gcd(b,a%b);
}
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		int ans=0;
		for (int j=0;j<30;j++){
			int tot=0;
			for (int i=1;i<=n;i++) tot+=((a[i]>>j)&1);
			ans=gcd(ans,tot);
		}
		for (int i=1;i<=n;i++)
			if (ans%i==0) printf("%d ",i);
		putchar('\n');
	}
	return 0;
}