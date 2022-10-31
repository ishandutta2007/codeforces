#include <cstdio>

using namespace std;

int main(){
    unsigned n, k;
    scanf("%u %u", &n, &k);
    if(k > (n - 1) / 2){
        puts("-1");
        return 0;
    }
    printf("%u\n", n * k);
    for(unsigned diff = 1; diff <= k; diff++){
        for(unsigned i = 0; i < n; i++){
            printf("%u %u\n", i + 1, (i + diff) % n + 1);
        }
    }
}