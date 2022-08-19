#include <cstdio>
#include <algorithm>

int k,n,b[200001];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)scanf("%1d",b+i);
	for(int i=0;i<n;i++){
		if(b[i%k]!=b[i]){
			if(b[i%k]<b[i]){
				for(int j=k-1;~j;--j)
					if(b[j]!=9){
						++b[j];
						for(int l=j+1;l<k;l++)b[l]=0;
						break;
					}
			}
			break;
		}
	}
	printf("%d\n",n);
	for(int i=0;i<n;i++)printf("%d",b[i%k]);
}