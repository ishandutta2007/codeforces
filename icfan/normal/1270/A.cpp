#include <cstdio>
#define Maxn 100
int n,k1,k2;
int a,b;
bool win;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&k1,&k2);
		for(int i=1;i<=k1;i++){
			scanf("%d",&a);
			if(a==n){
				win=1;
			}
		}
		for(int i=1;i<=k2;i++){
			scanf("%d",&b);
			if(b==n){
				win=0;
			}
		}
		if(win){
			puts("YES");
		}
		else{
			puts("NO");
		}
	}
	return 0;
}