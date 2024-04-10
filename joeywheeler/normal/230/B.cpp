#include <cstdio>
#include <cmath>

#define N 1000010

using namespace std;

bool notprime[N];

int main() {
    notprime[0] = notprime[1] = true;
    for (int i = 2; i < N; i++) {
        if (!notprime[i]) {
            for (int j = 2 * i; j < N; j += i) {
                notprime[j] = true;
            }
        }
    }

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        long long t;
        scanf("%I64d", &t);
        long long x = floor(sqrt(t)+0.5);
        if (x*x == t && !notprime[x]) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}