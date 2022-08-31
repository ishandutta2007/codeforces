#include<bits/stdc++.h>
int n,ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		int x=0,y;
		for(int j=1;j<=3;++j){
			scanf("%d",&y);
			x+=y;
		}
		ans+=x>=2;
	}
	printf("%d\n",ans);
	return 0;
}