#include <cstdio>
using namespace std;
bool is_prime(int x) {
    for(int i = 2; i * i <= x; i++)
        if(x % i == 0)
            return false;
    return true;
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 4; i <= n; i++) {
        if(!is_prime(i) && !is_prime(n - i)) {
            printf("%d %d\n", i, n - i);
            return 0;
        }
    }
}