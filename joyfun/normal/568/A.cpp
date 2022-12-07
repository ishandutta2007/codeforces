#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 2000005;

int pri[N], mir[N];
int bit[10], bn;

int gao(int x) {
    bn = 0;
    while (x) {
        bit[bn++] = x % 10;
        x /= 10;
    }
    for (int i = 0; i < bn / 2; i++)
        if (bit[i] != bit[bn - i - 1]) return false;
    return true;
}

int main() {
    pri[1] = 1;
    for (int i = 2; i < N; i++) {
        if ((long long)i * i >= (long long)N) break;
        for (int j = i * i; j < N; j += i)
            pri[j] = 1;
    }
    for (int i = 1; i < N; i++)
        pri[i] = pri[i - 1] + (!pri[i]);
    for (int i = 1; i < N; i++)
        mir[i] = gao(i) + mir[i - 1];
    int p, q;
    scanf("%d%d", &p, &q);
    int flag = 0;
    for (int i = N - 1; i >= 1; i--) {
        if ((long long)mir[i] * p >= (long long)pri[i] * q) {
            printf("%d\n", i);
            flag = 1;
            break;
        }
    }
    if (!flag) printf("Palindromic tree is better than splay tree\n");
    return 0;
}