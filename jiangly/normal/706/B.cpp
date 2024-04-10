#include<bits/stdc++.h>
const int N=1e5+5;
int n,q;
int x[N],m[N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&x[i]);
	}
	scanf("%d",&q);
	for(int i=1;i<=q;++i){
		scanf("%d",&m[i]);
	}
	std::sort(x+1,x+n+1);
	for(int i=1;i<=q;++i){
		printf("%d\n",std::upper_bound(x+1,x+n+1,m[i])-x-1);
	}
	return 0;
}