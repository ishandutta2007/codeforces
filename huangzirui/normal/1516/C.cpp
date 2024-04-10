#include<stdio.h>
const int maxn=105,maxV=200005;
int n,sum;
int f[maxV],a[maxn];
int main(){
	scanf("%d",&n);
	f[0]=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]),sum+=a[i];
		for(int j=200000;j>=a[i];j--)
			f[j]+=f[j-a[i]];
	}
	if(sum%2||f[sum/2]==0){
		puts("0");
		return 0;
	}
	puts("1");
	for(int i=0;i<=15;i++)
		for(int j=1;j<=n;j++)
			if((a[j]>>i)&1){
				printf("%d\n",j);
				return 0;
			}
	return 0;
}