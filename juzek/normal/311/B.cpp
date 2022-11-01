#include <cstdio>
#include <vector>
#include <deque>
#include <algorithm>
#include <climits>

const int mod = 1000000007;

struct Prosta {
    long long prz;
    int a;
    long long b;
};

int d[100007];
long long dp[100007];
int points[100007];
std::deque<Prosta> proste;

void dorzuc(int a) {
    while (proste.size() != 0) {
        long long p = (proste.back().b - dp[a]);
        if (p < 0 || proste.back().a == points[a])
            return;
        p /= proste.back().a - points[a];
        if (p > proste.back().prz)
            proste.pop_back();
        else {
            proste.push_back({p, points[a], dp[a]});
            return;
        }
    }
    proste.push_back({1337133713LL, points[a], dp[a]});
}

int main() {
    int N, M, P;
    scanf("%d%d%d", &N, &M, &P);
    for (int i = 2; i <= N; i++) {
        scanf("%d", &d[i]);
        d[i] += d[i - 1];
    }
    int a, b;
    long long s = 0;
    for (int i = 1; i <= M; i++) {
        scanf("%d%d", &a, &b);
        dp[i] = -1;
        s += b - d[a];
        points[i] = b - d[a];
    }
    std::sort(points + 1, points + M + 1);
//    for (int i = 1; i <= M; i++) {
//        printf("%d ", points[i]);
//    }
//    printf("\n");
    dp[M] = (long long) points[M] * M - s;
    if (P == 1) {
        printf("%lld", dp[M]);
        return 0;
    }
    for (int k = 1; k < P; k++) {
        for (int i = M; i >= 1; i--) {
            long long mini = LLONG_MAX;
            if (dp[i] != -1)
                dorzuc(i);
            while (proste.size() > 1 && proste[1].prz >= i)
                proste.pop_front();
            mini = std::min(mini, proste.front().b - (long long) i * (proste.front().a - points[i]));
            dp[i] = mini;
        }
//        for (int i = 1; i <= M; i++)
//            printf("%lld ", dp[i]);
//        printf("\n");
        proste = std::deque<Prosta>();
    }
    long long mini = LLONG_MAX;
    for (int i = 1; i <= M; i++)
        mini = std::min(mini, dp[i]);
    printf("%lld", mini);
    return 0;
}