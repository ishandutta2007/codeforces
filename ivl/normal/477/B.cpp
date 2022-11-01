#include <cstdio>

using namespace std;

int n, k;

int m;

int main(){
    scanf("%d%d", &n, &k); // k zanemariv
    m = ((n * 3) * 2 - 1) * k;
    printf("%d\n", m);
    for (int i = 0; i < n; ++i){
        printf("%d %d %d %d\n", k * (i * 6 + 1), k * (i * 6 + 3), k * (i * 6 + 4), k * (i * 6 + 5));
    }
    return 0;
}