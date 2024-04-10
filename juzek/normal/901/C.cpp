#include <cstdio>
#include <vector>
#include <algorithm>

std::vector<int> v[1000007];
bool odw[1000007];
bool jest[1000007];
std::vector<int> ter;
std::vector<int> cykle[1000007];
int dp[1000007];
long long pref[1000007];

void dfs(int a, int oj) {
    odw[a] = true;
    ter.push_back(a);
    jest[a] = true;
    for (auto it : v[a]) {
        if (!odw[it]) {
            dfs(it, a);
        } else if (jest[it] && it != oj) {
            int mini = it, maxi = it;
            auto w = ter.rbegin();
            while (*w != it) {
                mini = std::min(mini, *w);
                maxi = std::max(maxi, *w);
                w++;
            }
            cykle[maxi].push_back(mini);
        }
    }
    ter.pop_back();
    jest[a] = false;
}

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    int a, b;
    for (int i = 0; i < M; i++) {
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 1; i <= N; i++)
        if (!odw[i])
            dfs(i, -1);
    for (int i = 1; i <= N; i++)
        std::sort(cykle[i].begin(), cykle[i].end());
    int kon = 1;
    for (int i = 1; i <= N; i++) {
        while (kon <= N - 1 && (cykle[kon + 1].empty() || *cykle[kon + 1].begin() < i)) {
            if (!cykle[kon + 1].empty())
                cykle[kon + 1].pop_back();
            else
                kon++;
        }
        dp[i] = kon;
        pref[i] = pref[i - 1] + dp[i] - i + 1;
    }
    int Q;
    scanf("%d", &Q);
    while (Q--) {
        scanf("%d%d", &a, &b);
        int sr = int(std::lower_bound(dp + a, dp + b + 1, b) - dp);
        long long ile = b - sr + 1;
        long long wyn = ile * (ile + 1) / 2 + pref[sr - 1] - pref[a - 1];
        printf("%I64d\n", wyn);
    }
    return 0;
}