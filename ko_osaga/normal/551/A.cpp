#include <cstdio>

int main(){
	int n;
	int a[2005];
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d",a+i);
	}
	for(int i=0; i<n; i++){
		int r = 1;
		for(int j=0; j<n; j++){
			if(a[j] > a[i]) r++;
		}
		printf("%d ",r);
	}
}