
#include <cstdio>

int main(){
    char str[105];
    scanf("%s",str);
    int flag = 1;
    for (int i=1; str[i]; i++) {
        if(str[i] <= 'Z' && str[i] >= 'A'){
           
        }
        else flag = 0;
    }
    if(flag == 0){
        puts(str);
        return 0;
    }
    for (int i=0; str[i]; i++) {
        if(str[i] <= 'Z' && str[i] >= 'A'){
            putchar(str[i] - 'A' + 'a');
        }
        else putchar(str[i] - 'a' + 'A');
    }
}