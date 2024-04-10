#include <stdio.h>
#define swap(a,b) a^=b;b^=a;a^=b
#define SWP swap(x1,x2);swap(y1,y2)
long long x1,x2,y1,y2,n,no,k;
int i,j;
void gcd(){
	if(x1<0){x1=-x1;y1=-y1;}
	if(x2<0){x2=-x2;y2=-y2;}
	if(!x2){return;}
	if(x2<x1){SWP;}
	k=x2/x1;x2-=x1*k;y2-=y1*k;
	gcd();
}
 
int main(){
	scanf("%lld%lld%lld%lld%lld",&n,&x1,&y1,&x2,&y2);
	if(!x1){SWP;}
	gcd();
	if(y2<0){y2=-y2;}
	if(n!=x1*y2){puts("NO");return 0;}
	puts("YES");
	for(i=1;i<=x1;i++){
		for(j=1;j<=y2;j++){
			printf("%d %d\n",i-1,j-1);
		}
	}
}