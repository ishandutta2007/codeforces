#include<stdio.h>
using namespace std;
int n,k,a[210000],tot;
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		tot+=(a[i]&1);
	}
	if (k==n){
		if (tot&1) puts("Stannis");
		else puts("Daenerys");
		return 0;
	}
	if ((n-k)/2>=tot) puts("Daenerys");
	else{
		if ((n-k)/2>=n-tot)
			if (k&1) puts("Stannis");
			else puts("Daenerys");
		else
			if ((n-k)&1) puts("Stannis");
			else puts("Daenerys");
	}
	return 0;
}