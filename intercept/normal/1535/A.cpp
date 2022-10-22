#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;++i){
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(max(a,b)>min(c,d)&&max(c,d)>min(a,b))printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}