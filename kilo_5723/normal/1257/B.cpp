#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int tt;
    int x,y;
    scanf("%d",&tt);
    while (tt--){
        scanf("%d%d",&x,&y);
        if (x==1){
            puts(y==1?"YES":"NO");
            continue;
        }
        if (x<4){
            puts(y<4?"YES":"NO");
            continue;
        }
        puts("YES");
    }
    return 0;
}