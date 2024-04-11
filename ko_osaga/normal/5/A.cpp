#include <cstdio>

int main(){
    char str[105];
    int p = 0;
    int ret = 0;
    while (fgets(str,105,stdin)) {
        if(str[0] == '+'){
            p++;
        }
        else if(str[0] == '-'){
            p--;
        }
        else{
            int q = 0, f = 0;
            for (int i=0; str[i] != '\n'; i++) {
                if(f) q++;
                if(str[i] == ':') f = 1;
            }
            ret += p * q;
        }
    }
    printf("%d",ret);
}