#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long PN[2][4];
int N,i,j,k,nu,ol;

int main(){
    scanf("%d",&N);
    PN[0][0] = 1;
    for (i=1; i<=N; i++){
        nu = i%2;
        ol = 1-nu;
        PN[nu][0] = PN[ol][1]+PN[ol][2]+PN[ol][3];
        PN[nu][2] = PN[ol][0]+PN[ol][1]+PN[ol][3];
        PN[nu][1] = PN[ol][0]+PN[ol][2]+PN[ol][3];
        PN[nu][3] = PN[ol][0]+PN[ol][1]+PN[ol][2];
        for (j=0; j<4; j++) PN[nu][j] %= 1000000007;
    }
    printf("%I64d\n",PN[N%2][0]);
    return 0;
}