#include <cstdio>
using namespace std;
int main() {
    int n, k, t0 = 0, t1 = 0;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        (a % 2 == 0 ? t0 : t1)++;
    }
    int rounds = n - k;
    if(rounds == 0)
        puts(t1 % 2 == 0 ? "Daenerys" : "Stannis");
    else if(rounds % 2 == 1) {
        // last hand is Stannis
        if(t1 <= rounds / 2)
            puts("Daenerys");
        else if(t0 <= rounds / 2 && k % 2 == 0)
            puts("Daenerys");
        else
            puts("Stannis");
    } else {
        // last hand is Daenerys
        if(t0 <= rounds / 2 && k % 2 == 1)
            puts("Stannis");
        else
            puts("Daenerys");
    }
}