#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
const int MAX=(int)2e9;
int main(void) {
    int s=1;
    int a;
    scanf("%d",&a);
    FOR(i,1,a-1) s+=12*i;
    printf("%d",s);
    return 0;
}