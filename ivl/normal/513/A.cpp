#include <cstdio>

using namespace std;

int main(){
    int n1, n2, k1, k2;
    scanf("%d%d%d%d", &n1, &n2, &k1, &k2);
    if (n1 <= n2) printf("Second\n"); else printf("First\n");
    return 0;
}