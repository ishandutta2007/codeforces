#include<bits/stdc++.h>
using namespace std;
int T;
int main(){
	scanf("%d",&T); int x,y;
	while (T--){
		scanf("%d%d",&x,&y);
		if (x>y) printf("%d\n",x+y);
		else if (x==y) printf("%d\n",x);
		else printf("%lld\n",(1ll*y/x*x+y)>>1);
	}
	return 0;
}