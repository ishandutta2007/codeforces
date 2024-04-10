#include<stdio.h>
#include<math.h>
#define PI 3.1415926535897932384626
int i,n,m;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&m);

		printf("%.9lf\n",1/tan(PI/2/m));
	}
}