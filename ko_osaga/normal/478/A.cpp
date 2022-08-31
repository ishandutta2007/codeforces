#include <cstdio>

int main(){
    int r = 0,t;
    for (int i=0; i<5; i++) {
        scanf("%d",&t);
        r += t;
    }
    if(r == 0 || r%5) puts("-1");
    else printf("%d",r/5);
}