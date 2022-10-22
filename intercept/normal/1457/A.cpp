#include<bits/stdc++.h>
using namespace std;
int n;
int ans;
int main(){
	scanf("%d",&n);
	for(int i=1,x,y,c,r;i<=n;++i){
		scanf("%d%d%d%d",&x,&y,&c,&r);
		ans=max({c-1+r-1,x-c+r-1,c-1+y-r,x-c+y-r});
		printf("%d\n",ans);
	}
	return 0;
}