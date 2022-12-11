#include <bits/stdc++.h>
using namespace std;
int T,n,m,p,k,a[200010];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		int cnt=1,tmp=a[1],ans=0;
		for(int i=2;i<=n+1;i++){
			if(cnt>=tmp){
				cnt=1,tmp=a[i];
				ans++;
				continue;
			}
			else cnt++,tmp=max(tmp,a[i]);
		}
		printf("%d\n",ans);
	}
}