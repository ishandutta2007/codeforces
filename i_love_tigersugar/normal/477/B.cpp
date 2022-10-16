#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
using namespace std;
int main(void) {
    int n,k;
    scanf("%d%d",&n,&k);
    printf("%d\n",(6*n-1)*k);
    FOR(i,1,n) printf("%d %d %d %d\n",k*(6*i-5),k*(6*i-4),k*(6*i-3),k*(6*i-1));
    return 0;
}