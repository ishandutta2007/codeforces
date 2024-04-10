#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
using namespace std;
int main(void) {
    int n;
    scanf("%d",&n);
    if (n<=2) printf("1\n1\n");
    else if (n==3) printf("2\n1 3\n");
    else if (n==4) printf("4\n2 4 1 3\n");
    else {
        queue<int> q[2];
        FOR(i,1,n-n/2) q[1].push(i);
        FOR(i,n-n/2+1,n) q[0].push(i);
        printf("%d\n",n);
        FOR(i,1,n) {
            printf("%d ",q[i&1].front());q[i&1].pop();
        }
        printf("\n");
    }
    return 0;
}