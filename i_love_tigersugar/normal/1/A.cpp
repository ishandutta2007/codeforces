#include<bits/stdc++.h>
long long m,n,a;
int main(void) {
    scanf("%I64d",&m);
    scanf("%I64d",&n);
    scanf("%I64d",&a);
    if (n%a==0) n=n/a; else n=n/a+1;
    if (m%a==0) m=m/a; else m=m/a+1;
    printf("%I64d",m*n);
    return 0;
}