#include <cstdio>

using namespace std;

int n, k;

int main(){
    scanf("%d%d", &n, &k);
    int p1 = 1, p2 = n;
    for (int i = 1; i <= k; ++i){
        if (i & 1) printf("%d ", p1++);
        else printf("%d ", p2--);
    }
    if ((k & 1) == 0) for (int i = p2; i >= p1; --i) printf("%d ", i);
    else for (int i = p1; i <= p2; ++i) printf("%d ", i);
    printf("\n");
    return 0;
}