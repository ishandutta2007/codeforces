#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[6];
int found[10]={}; // A~J,?
int main(){
    gets(str);
    int i, len = strlen(str), solution = 1, letters = 10;
    if( 'A' <= str[0] && str[0] <= 'J' )
        solution = 9, found[str[0] - 'A'] = 1, letters--;
    else if( str[0] == '?' )
        solution = 9;   
    for(i = 1; i < len; i++)
        if( 'A' <= str[i] && str[i] <= 'J' ){
            if( found[str[i] - 'A'] == 0)
                solution *= letters, found[str[i] - 'A'] = 1, letters--;
        }else if( str[i] == '?' )
            solution *= 10;
    printf("%d\n", solution);
    // system("pause");
    return 0;
}