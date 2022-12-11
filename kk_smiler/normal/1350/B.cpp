#include <bits/stdc++.h>
#define ope operator
#define re register
#define il inline
using namespace std;
int T,n,m,k,q,a[100010],f[100010];
int main(){
	scanf("%d",&T);
	while(T--){
		int ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]),f[i]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j*i<=n;j++){
				if(a[i]<a[i*j]) f[i*j]=max(f[i*j],f[i]+1);
			}
			ans=max(ans,f[i]);
		}
		printf("%d\n",ans);
	}
}