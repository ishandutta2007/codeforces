#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
int main(void) {
    int n;
    scanf("%d",&n);
    FOR(i,1,100000) {
        if (n<1LL*i*(i+1)/2) {
            printf("%d",i-1);
            return 0;
        }
        n-=1LL*i*(i+1)/2;
    }
    return 1;
}