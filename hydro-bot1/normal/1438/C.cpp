// Hydro submission #61c2b85168363316e14b1dcf@1640151121843
#include<bits/stdc++.h>
using namespace std;
int _,n,m;
int main(){
	scanf("%d",&_);
	while(_--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++,puts(""))for(int j=1;j<=m;j++){
			int x;
			scanf("%d",&x);
			if(((i+j)&1)!=(x&1))printf("%d ",x+1);
			else printf("%d ",x);
		}
	}
}