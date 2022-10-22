#include <cstdio>
#define Maxn 200000
int a[Maxn+5];
int n;
int mx(int a,int b){
	return a>b?a:b;
}
int mn(int a,int b){
	return a<b?a:b;
}
int main(){
	int t;
	scanf("%d",&t);
	int tmp;
	bool find;
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		find=0;
		tmp=1;
		for(int i=2;i<=n;i++){
			if(a[i]>=(a[tmp]-tmp)+i+1){
				puts("YES");
				printf("%d %d\n",tmp,i);
				find=1;
				break;
			}
			if(a[i]-i<a[tmp]-tmp){
				tmp=i;
			}
		}
		if(!find){
			tmp=n;
			for(int i=n-1;i>0;i--){
				if(a[i]>=(a[tmp]+tmp)-i+1){
					puts("YES");
					printf("%d %d\n",i,tmp);
					find=1;
					break;
				}
				if(i+a[i]<a[tmp]+tmp){
					tmp=i;
				}
			}
		}
		if(!find){
			puts("NO");
		}
	}
	return 0;
}
/*
a[right]-a[left]>=right-left+1
a[right]>=(a[left]-left)+(right+1)
a[left]-a[right]>=right-left+1
a[left]>=(a[right]+right)-left+1
*/