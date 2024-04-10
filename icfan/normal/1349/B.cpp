#include <cstdio>
const int Maxn=100000;
int n,k;
int a[Maxn+5];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		bool flag=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]==k){
				flag=1;
			}
		}
		if(!flag){
			puts("no");
			continue;
		}
		if(n==1){
			puts("yes");
			continue;
		}
		flag=0;
		for(int i=1;i<n;i++){
			if(a[i]>=k&&a[i+1]>=k){
				flag=1;
				break;
			}
		}
		if(flag){
			puts("yes");
			continue;
		}
		for(int i=2;i<n;i++){
			if(a[i-1]>=k&&a[i+1]>=k){
				flag=1;
				break;
			}
		}
		if(flag){
			puts("yes");
			continue;
		}
		puts("no");
	}
	return 0;
}