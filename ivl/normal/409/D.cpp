#include <cstdio>

using namespace std;

int v[] = {1,0,0,1,0,1,0,1,1,1,0,0,1,0,1,0};

int main(){
    int a;
    scanf("%d", &a);
    printf("%d\n", v[a - 1]);
    return 0;
}