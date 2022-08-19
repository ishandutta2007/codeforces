#include <bits/stdc++.h>

int n,a[1000001],b[1000001];
long long A[1000001],B[1000001];
int hav[1000001],pre[1000001];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		A[i]=A[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		scanf("%d",b+i);
		B[i]=B[i-1]+b[i];
	}
	bool swap=(A[n]>B[n]);
	if(swap)for(int i=1;i<=n;i++)std::swap(a[i],b[i]),std::swap(A[i],B[i]);
	for(int i=1,j=0;i<=n;i++){
		while(B[j]<A[i])++j;
		pre[i]=j;
		if(hav[B[j]-A[i]]||B[j]==A[i]){
			int lA=hav[B[j]-A[i]],lB=pre[lA];
			if(B[j]==A[i])lA=lB=0;
			if(swap){
				printf("%d\n",j-lB);
				for(int k=j;k>lB;k--)printf("%d ",k);putchar('\n');
				printf("%d\n",i-lA);
				for(int k=i;k>lA;k--)printf("%d ",k);putchar('\n');
			}
			else{
				printf("%d\n",i-lA);
				for(int k=i;k>lA;k--)printf("%d ",k);putchar('\n');
				printf("%d\n",j-lB);
				for(int k=j;k>lB;k--)printf("%d ",k);putchar('\n');
			}
			return 0;
		}
		else hav[B[j]-A[i]]=i;
	}
}