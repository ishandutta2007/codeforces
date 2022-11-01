#include <cstdio>

using namespace std;

int a, b;

int f(int x){
    if (x < b) return x;
    return f(x - b + 1) + b;
}

int main(){
    scanf("%d%d", &a, &b);
    printf("%d\n", f(a));
    return 0;
}