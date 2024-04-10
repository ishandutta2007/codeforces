#include <cstdio>
#include <algorithm>
using namespace std;
bool possible(int n, int k, int d) {
    int x = 1;
    for(int i = 0; i < d; i++) {
        x *= k;
        if(x >= n)
            return true;
    }
    return false;
}
int x[1000];
int main(){
    int n, k, d;
    scanf("%d %d %d", &n, &k, &d);
    if(!possible(n, k, d)) {
        puts("-1");
    } else {
        iota(x, x + n, 0);
        for(int i = 0; i < d; i++) {
            for(int j = 0; j < n; j++) {
                printf("%d%c", x[j] % k + 1, j == n - 1 ? '\n' : ' ');
                x[j] /= k;
            }
        }
    }
}