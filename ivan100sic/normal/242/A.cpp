#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int X,Y,A,B,i,j,k,l,P;

int main(){
    scanf("%d%d%d%d",&X,&Y,&A,&B);
    for (i=A; i<=X; i++){
        for (j=B; j<=Y; j++){
            if (i>j) P++;
        }
    }
    printf("%d\n",P);
    for (i=A; i<=X; i++){
        for (j=B; j<=Y; j++){
            if (i>j) printf("%d %d\n",i,j);
        }
    }
    return 0;
}