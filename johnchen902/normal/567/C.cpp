#include <cstdio>
#include <map>
using namespace std;
int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    map<int, int> m1;
    map<int, long long> m2;
    long long a = 0;
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if(x % k == 0) {
            a += m2[x / k];
            m2[x] += m1[x / k];
        }
        m1[x]++;
    }
    printf("%I64d\n", a);
}