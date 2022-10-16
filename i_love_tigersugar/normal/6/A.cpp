#include<bits/stdc++.h>
const char tri[]="TRIANGLE";
const char seg[]="SEGMENT";
const char imp[]="IMPOSSIBLE";
int a[13];
int i,j,k;
int main(void) {    
    for (i=1;i<=4;i=i+1) scanf("%d",&a[i]); 
    for (i=1;i<=4;i=i+1)
        for (j=i+1;j<=4;j=j+1)
            for (k=j+1;k<=4;k=k+1) {
                if (a[i]+a[j]>a[k] && a[k]>=a[i] && a[k]>=a[j]) {
                    printf("%s",tri);
                    return 0;
                }
                if (a[j]+a[k]>a[i] && a[i]>=a[j] && a[i]>=a[k]) {
                    printf("%s",tri);
                    return 0;
                }
                if (a[k]+a[i]>a[j] && a[j]>=a[k] && a[j]>=a[i]) {
                    printf("%s",tri);
                    return 0;
                }
            }
    for (i=1;i<=4;i=i+1)
        for (j=i+1;j<=4;j=j+1)
            for (k=j+1;k<=4;k=k+1) {
                if (a[i]+a[j]==a[k]) {
                    printf("%s",seg);
                    return 0;
                }
                if (a[j]+a[k]==a[i]) {
                    printf("%s",seg);
                    return 0;
                }
                if (a[k]+a[i]==a[j]) {
                    printf("%s",seg);
                    return 0;
                }
            }
    printf("%s",imp);
    return 0;
}