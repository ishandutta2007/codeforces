#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5,M=1.5e7+5;
int n,g,ans,a[N],cc[M],np[M];

int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d",a+i),g=__gcd(a[i],g);
	for (int i=1;i<=n;++i) ++cc[a[i]/g];
	for (int i=2;i<M;++i) {
		if (!np[i]) {
			int res=0;
			for (int j=i;j<M;j+=i) np[j]=1,res+=cc[j];
			ans=max(ans,res);
		}
	}
	printf("%d\n",ans?n-ans:-1);
}