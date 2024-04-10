#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int deg[4],sol[4],a,b,c,d;

int main(){
    scanf("%d%d%d",deg+1,deg+2,deg+3);
    for (a=0; a<=1000000; a++){
        b = deg[1] - a;
        c = deg[2] - a;
        d = deg[3];
        if (b>=0 && c>=0 && d>=0 && d==b+c){
            printf("%d %d %d\n",a,c,b);
            return 0;
        }
    }
    printf("Impossible\n");
    return 0;
}