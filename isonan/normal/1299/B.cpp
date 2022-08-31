#include <cstdio>

int n,x[100001],y[100001];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",x+i,y+i);
	if(n%2){
		puts("NO");
		return 0;
	}
	for(int i=2;i<=n>>1;i++){
		if(x[i]+x[i+(n>>1)]!=x[i-1]+x[i-1+(n>>1)]){
			puts("NO");
			return 0;
		}
		if(y[i]+y[i+(n>>1)]!=y[i-1]+y[i-1+(n>>1)]){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
}