#include <cstdio>
#include <algorithm>
using namespace std;
long long pr[100];
int cnt[100];
long long val[1000000];
int main() {
    long long n;
    int k;
    scanf("%lld %d", &n, &k);
    int m = 0;
    for(int i = 2; (long long) i * i <= n; i++)
        if(n % i == 0) {
            pr[m] = i;
            do {
                n /= i;
                cnt[m]++;
            } while(n % i == 0);
            m++;
        }
    if(n > 1) {
        pr[m] = n;
        cnt[m] = 1;
        m++;
    }
    val[0] = 1;
    int size = 1;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < size * cnt[i]; j++)
            val[j + size] = val[j] * pr[i];
        size *= cnt[i] + 1;
    }
    k--;
    if(k >= size) {
        puts("-1");
        return 0;
    }
    nth_element(val, val + k, val + size);
    printf("%lld\n", val[k]);
}