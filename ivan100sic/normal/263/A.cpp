#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int x,y,i,j,k;

int main(){
    for (i=1; i<=5; i++){
        for (j=1; j<=5; j++){
            scanf("%d",&k);
            if (k!=0){
                x = i;
                y = j;
            }
        }
    }
    printf("%d\n",abs(x-3)+abs(y-3));
    return 0;
}