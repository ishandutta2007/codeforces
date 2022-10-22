#include<bits/stdc++.h>
using namespace std;
int T,n,a[110];
int myabs(int x){ return x<0?-x:x;}
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n); int x;
		for (int i=1;i<=n;i++){
			scanf("%d",&x);
			a[myabs(x)]++;
		}
		int ans=min(a[0],1); a[0]=0;
		for (int i=1;i<=100;i++){
			ans+=min(a[i],2);
			a[i]=0;
		}
		printf("%d\n",ans);
	}
	return 0;
}