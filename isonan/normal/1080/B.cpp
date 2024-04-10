#include <cstdio>

int ans(int x){
	if(x%2)return -(x-(x/2));
	return (x/2);
}
int q,l,r;
int main(){
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d%d",&l,&r);
		printf("%d\n",ans(r)-ans(l-1));
	}
}