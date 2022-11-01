#include <stdio.h>

int main(){
    int len1 = 0, len2 = 0, all0_1 = 1, all0_2 = 1, c;
    while((c = getchar()) != '\n'){
        if( c != '0')
            all0_1 = 0;
        len1++;
    }
    while((c = getchar()) != '\n'){
        if( c != '0')
            all0_2 = 0;
        len2++;
    }
    printf(len1 == len2 && all0_1 == all0_2 ? "YES\n" : "NO\n");
    return 0;
}