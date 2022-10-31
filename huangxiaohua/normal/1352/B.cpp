#include<stdio.h>
int i,j,n,a,b;

int main() {
    scanf("%d",&n);
    for(i=1; i<=n; i++) {
        scanf("%d%d",&a,&b);

        if(a%2==1&b%2==0) {
            printf("NO\n");
            continue;
        }
        if(a<b) {
            printf("NO\n");
            continue;
        }
        if(a==b) {
            printf("YES\n");
            for(j=1; j<=a; j++) {
                printf("1 ");
            }
            printf("\n");
            continue;
        }
        if(a%2==1&b%2==1) {
            printf("YES\n");
            printf("%d ",a-b+1);
            for(j=1; j<=b-1; j++) {
                printf("1 ");
            }
            printf("\n");
            continue;
        }
        if(a%2==0&b*2<=a) {
            printf("YES\n");
            for(j=1; j<=b-1; j++) {
                printf("2 ");
            }
            printf("%d\n",a-b*2+2);
            continue;
        }

        else {
        	if(b%2==0){
        		printf("YES\n");
        		for(j=1; j<=b-1; j++) {
                printf("1 ");
            	}
            	printf("%d\n",a-b+1);
			}
            else{
            	printf("NO\n");
          	  continue;
			}
        }
    }

    return 0;
}