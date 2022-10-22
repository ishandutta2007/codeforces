#include <cstdio>
#define Maxn 1000
int x[Maxn+5],y[Maxn+5];
int n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&x[i],&y[i]);
	}
	int num;
	while(1){
		num=0;
		for(int i=1;i<=n;i++){
			if((x[i]+y[i])&1){
				num++;
			}
		}
		if(num>0&&num<n){
			printf("%d\n",num);
			for(int i=1;i<=n;i++){
				if((x[i]+y[i])&1){
					printf("%d ",i);
				}
			}
			puts("");
			break;
		}
		for(int i=1;i<=n;i++){
			int now=y[i];
			y[i]=(y[i]+x[i])>>1;
			x[i]=(x[i]-now)>>1;
		}
	}
	return 0;
}