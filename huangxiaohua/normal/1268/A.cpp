#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[200500],b[200500];

int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%1d",&a[i]);
		if(i<=m){b[i]=a[i];}
		else{b[i]=b[i-m];}
	}
	for(i=1;i<=n;i++){
		if(a[i]==b[i]){continue;}
		if(b[i]>a[i]){
			printf("%d\n",n);
			for(j=1;j<=n;j++){
				printf("%d",b[j]);
			}
			return 0;
		}
		else{
			b[m]++;
			for(j=m;j>=1;j--){
				if(b[j]>9){b[j]=0;b[j-1]++;}
			}
			
			if(b[0]){
				printf("%d\n",n+1);
				for(j=0;j<=n;j++){
					if(j>=m){b[j]=b[j-m];}
					printf("%d",b[j]);
				}
			}
			else{
				printf("%d\n",n);
				for(j=1;j<=n;j++){
					if(j>m){b[j]=b[j-m];}
					printf("%d",b[j]);
				}
			}
			return 0;
		}
	}
	printf("%d\n",n);
	for(j=1;j<=n;j++){
		printf("%d",b[j]);
	}
}