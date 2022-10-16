#include<bits/stdc++.h>
int res[]={2,3,1,2,1};
int main(void) {
    int x;
    scanf("%d",&x);x--;
    assert(res[x]>=0);
    printf("%d",res[x]);
    return 0;
}