#include <cstdio>
using namespace std;

int A,B,i;

int main(){
    scanf("%d",&A);
    B=1;
    for (i=2; i<=A; i++){
        B+=6*(2*i-2);
    }
    printf("%d\n",B);
    return 0;
}