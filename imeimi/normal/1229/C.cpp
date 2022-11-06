#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdlib>
#include <string>
#include <cstring>
#include <functional>
#define fs first
#define se second

#ifdef imeimi
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<ld, ld> pdd;

const int S = 500;
int n, m;
int A[100001];
int B[100001];
int T[100001];
int deg[100001];
int indeg[100001];
vector<int> ch[100001];
vector<int> edge[100001];
vector<int> bedge[100001];

llong get(int i) {
    return (llong)indeg[i] * (deg[i] - indeg[i]);
}

bool vis[100001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> A[i] >> B[i];
        if (A[i] > B[i]) swap(A[i], B[i]);
        ++deg[A[i]];
        ++deg[B[i]];
        ++indeg[A[i]];
        edge[A[i]].push_back(B[i]);
        edge[B[i]].push_back(A[i]);
    }
    llong sum = 0;
    for (int i = 1; i <= n; ++i) {
        T[i] = i;
        sum += get(i);
        for (int j : edge[i]) {
            if (deg[j] > S) {
                ch[j].push_back(i);
                bedge[i].push_back(j);
            }
        }
    }
    int q;
    cin >> q;
    printf("%lld\n", sum);
    for (int it = n + 1; it <= n + q; ++it) {
        int x;
        cin >> x;
        if (deg[x] > S) {
            for (int i : ch[x]) {
                if (vis[i]) continue;
                vis[i] = 1;
                sum -= get(x);
                sum -= get(i);
                if (T[x] < T[i]) --indeg[x];
                else --indeg[i];
                if (it < T[i]) ++indeg[x];
                else ++indeg[i];
                sum += get(x);
                sum += get(i);
            }
            for (int i : bedge[x]) {
                if (vis[i]) continue;
                sum -= get(x);
                sum -= get(i);
                if (T[x] < T[i]) --indeg[x];
                else --indeg[i];
                if (it < T[i]) ++indeg[x];
                else ++indeg[i];
                sum += get(x);
                sum += get(i);
            }
            for (int i : ch[x]) vis[i] = 0;
            ch[x].clear();
        }
        else {
            for (int i : edge[x]) {
                if (deg[i] > S) {
                    ch[i].push_back(x);
                }
                sum -= get(x);
                sum -= get(i);
                if (T[x] < T[i]) --indeg[x];
                else --indeg[i];
                if (it < T[i]) ++indeg[x];
                else ++indeg[i];
                sum += get(x);
                sum += get(i);
            }
        }
        T[x] = it;
        printf("%lld\n", sum);
    }
    return 0;
}