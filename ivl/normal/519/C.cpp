#include<cstdio>

using namespace std;

int a, b, x;

int main(){
    scanf("%d%d", &a, &b);
    if((a == 1) && (b == 1)){printf("0");return 0;}
    if((a == 2) && (b == 2)){printf("1");return 0;}
    
    while((a != 0) && (b != 0)){
        if(a >= b){a -= 2; b -= 1; x++;}
        else{a -= 1; b -= 2; x++;}
        if((a == 1) && (b == 1))break;
    }
    
    printf("%d", x);
    
    return 0;
}