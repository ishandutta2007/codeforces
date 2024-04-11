#include <cstdio>


int main(){
    int px,py,vx,vy;
    scanf("%d %d %d %d",&px,&py,&vx,&vy);
    if(vx >= px && vy >= py) puts("Polycarp");
    else if(vx < px + py && vy < px + py) puts("Vasiliy");
    else puts("Polycarp");
}