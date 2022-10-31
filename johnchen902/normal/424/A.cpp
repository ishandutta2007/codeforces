#include <cstdio>
#include <cstdlib>

using namespace std;

char c[200];

int main() {
    int n;
    scanf("%d\n", &n);
    int x = 0, X = 0;
    for(int i = 0; i < n; i++){
        if((c[i] = getchar()) == 'x')
            x++;
        else
            X++;
    }
    printf("%d\n", abs(x - X) / 2);
    for(int i = 0; i < n; i++){
        if(x > X && c[i] == 'x')
            c[i] = 'X', x--, X++;
        if(x < X && c[i] == 'X')
            c[i] = 'x', X--, x++;
        putchar(c[i]);
    }
    putchar('\n');
}