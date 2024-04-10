#include <cstdio>
#define Maxn 200
int p[Maxn+5];
int main(){
	int q,n;
	scanf("%d",&q);
	int x;
	bool find;
	while(q--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&p[i]);
		}
		while(p[1]!=1){
			x=p[n];
			for(int i=n;i>1;i--){
				p[i]=p[i-1];
			}
			p[1]=x;
		}
		find=1;
		if(p[2]==2){
			for(int i=3;i<=n;i++){
				if(p[i]!=i){
					find=0;
					break;
				}
			}
		}
		else{
			for(int i=2;i<=n;i++){
				if(p[i]!=n-(i-2)){
					find=0;
					break;
				}
			}
		}
		if(find){
			puts("YES");
		}
		else{
			puts("NO");
		}
	}
	return 0;
}