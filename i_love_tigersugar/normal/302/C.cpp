#include<cstdio>
#define MAX   333
int a[MAX];
int n,neg,min;
bool zero;
void process(void) {
    scanf("%d",&n);
    int i;
    for (i=1;i<2*n;i=i+1) {
        scanf("%d",&a[i]);
        if (a[i]==0) zero=true;
        if (a[i]<0) {
            neg++;
            a[i]=-a[i];
        }
    }
    if ((neg%2==0) || ((neg+n)%2==0) || zero) min=0;
    else {
        min=220797;
        for (i=1;i<2*n;i=i+1)
            if (min>a[i]) min=a[i];
    }
    int sum=0;
    for (i=1;i<2*n;i=i+1)
        sum=sum+a[i];
    printf("%d",sum-2*min);
}
int main(void) {
    process();
    return 0;
}