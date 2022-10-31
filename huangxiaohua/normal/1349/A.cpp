#include<stdio.h>
int sushu[203005],s[203005],sn=0,i,j,n,a[200005],max=0,no;
long long int res=1;
int main(){
	int i,j,sum=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>=max){max=a[i];}
	}
	for(i=2;i<=max+100;i++){
		if(sushu[i]==0){
			sn++;s[sn]=i;
			for(j=i+i;j<=203000;j+=i){
				sushu[j]=1;
			}
		}
	}
	for(i=1;s[i]<=max;i++){
		aaa:no=0;for(j=1;j<=n&&no<=1;j++){
			if(a[j]%s[i]==0){
				a[j]/=s[i];
			}
			else{no++;
			}
		}
		if(no<=1){res*=s[i];goto aaa;
		}
	}
	printf("%lld",res);
	return 0;
}