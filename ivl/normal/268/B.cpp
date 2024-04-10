#include <cstdio>

using namespace std;

int n;

int main(){
    scanf("%d", &n);
    int rez = 0;
    for (int i = 1; i <= n; ++i){
        rez += i * (n  - i);
    }
    rez += n;
    printf("%d\n", rez);
    return 0;
}