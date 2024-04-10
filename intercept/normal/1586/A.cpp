#include<bits/stdc++.h>
using namespace std;
int n;
int a[109];
void work(){
	scanf("%d",&n);
	int sum=0;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	for(int i=2;i<sum;++i){
		if(sum%i==0){
			printf("%d\n",n);
			for(int j=1;j<=n;++j)printf("%d ",j);
			puts("");
			return;
		}
	}
	int p;
	for(int i=1;i<=n;++i){
		if(a[i]%2)p=i;
	}
	printf("%d\n",n-1);
	for(int i=1;i<=n;++i){
		if(i!=p)printf("%d ",i);
	}
	puts("");
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}