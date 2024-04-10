#include <cstdio>

using namespace std;

int n;
char in[2005];
int len;

int main(){
    scanf("%d", &n);
    scanf("%s", in);
    for (len = 0; in[len] != '\0'; ++len);
    int rez = 0;
    for (int i = n; i < len; i += n){
        if (in[i - 1] == in[i - 2] && in[i - 2] == in[i - 3]) ++rez;
    }
    printf("%d\n", rez);
    return 0;
}