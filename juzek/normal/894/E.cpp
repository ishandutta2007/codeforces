#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

std::vector<std::pair<int, int>> v[1000007];
std::vector<int> rv[1000007];
int post[1000007];
bool odw[1000007];
std::vector<int> spoj[1000007];
int moj[1000007];
long long sila[1000007];
long long dp[1000007];
long long grzybki[1000000];
long long grzybkiPref[1000000];
int maksGrzyb = 0;

int zeit = 0;

void dfs(int a) {
    odw[a] = true;
    for (auto it : v[a])
        if (!odw[it.first])
            dfs(it.first);
    post[++zeit] = a;
}

void dfs2(int a, int ter) {
    odw[a] = true;
    moj[a] = ter;
    spoj[ter].push_back(a);
    for (auto it : rv[a])
        if (!odw[it])
            dfs2(it, ter);
}

inline long long policz(int a) {
    int kon = int(std::lower_bound(grzybki + 1, grzybki + maksGrzyb, a) - grzybki);
    return (long long) a * kon - grzybkiPref[kon - 1];
}

void dfsPolicz(int sp) {
    odw[sp] = true;
    dp[sp] = sila[sp];
    for (auto a : spoj[sp]) {
        for (auto it : v[a]) {
            if (moj[it.first] != sp) {
                if (!odw[moj[it.first]])
                    dfsPolicz(moj[it.first]);
                dp[sp] = std::max(dp[sp], sila[sp] + it.second + dp[moj[it.first]]);
            }
        }
    }
}

int main() {
    for (int i = 1; i <= 1000000; i++) {
        grzybki[i] = grzybki[i - 1] + i;
        if (grzybki[i] > 100000000) {
            maksGrzyb = i;
            break;
        }
    }
    for (int i = 1; i < maksGrzyb; i++)
        grzybkiPref[i] = grzybkiPref[i - 1] + grzybki[i];
    int N, M;
    scanf("%d%d", &N, &M);
    for (int a, b, c, i = 0; i < M; i++) {
        scanf("%d%d%d", &a, &b, &c);
        v[a].emplace_back(b, c);
        rv[b].push_back(a);
    }
    int s;
    scanf("%d", &s);
    for (int i = 1; i <= N; i++)
        if (!odw[i])
            dfs(i);
    memset(odw, 0, sizeof(odw));
    int ile = 1;
    for (int i = N; i >= 1; i--)
        if (!odw[post[i]])
            dfs2(post[i], ile++);
    memset(odw, 0, sizeof(odw));
    for (int i = 1; i < ile; i++) {
        long long s = 0;
        for (auto a : spoj[i])
            for (auto it : v[a])
                if (moj[it.first] == i)
                    s += policz(it.second);
        sila[i] = s;
    }
    for (int i = 1; i < ile; i++)
        if (!odw[i])
            dfsPolicz(i);
    printf("%lld", dp[moj[s]]);
    return 0;
}