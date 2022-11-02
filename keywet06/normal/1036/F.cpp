#include <bits/stdc++.h>
using namespace std;

typedef long double float96;
typedef long long int64;

const int N = 61;
const int64 lim = 1000000000000000000ll;

vector<int64> V[N];
int T;
int64 n;
int64 cnt[N];

int main() {
    for (int i = 1; i <= 1000000; i++) {
        int64 num = int64(i) * i;
        for (int j = 3; j < N; j++)
            if (num <= lim / i) {
                num *= i;
                V[j].push_back(num);
            } else
                break;
    }
    scanf("%d", &T);
    while (T--) {
        scanf("%I64d", &n);
        for (int i = N - 1; i > 0; i--) {
            int64 num;
            if (i == 1)
                num = n;
            else if (i == 2) {
                int64 a = sqrt(float96(n));
                while (a * a <= n) a++;
                while (a * a > n) a--;
                num = a;
            } else
                num = upper_bound(V[i].begin(), V[i].end(), n) - V[i].begin();
            cnt[i] = num - 1;
            for (int j = i + i; j < N; j += i) cnt[i] -= cnt[j];
        }
        printf("%I64d\n", cnt[1]);
    }
    return 0;
}