#include<bits/stdc++.h>
using namespace std;
int T,n,a[95];
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		int ans=max(n-2,0);
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++){
				int res=0;
				for (int k=1;k<=n;k++)
					if ((k-i)*(a[j]-a[i])%(j-i)) res++;
					else res+=((k-i)*(a[j]-a[i])/(j-i)+a[i]!=a[k]);
				ans=min(ans,res);
			}
		printf("%d\n",ans);
	}
	return 0;
}