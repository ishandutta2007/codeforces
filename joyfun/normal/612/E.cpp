#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1000005;
int n, vis[N], a[N], b[N];

int on, en;
vector<int> odd[N];
vector<int> even[N];

bool cmp(vector<int> a, vector<int> b) {
    return (int)a.size() < (int)b.size();
}

bool judge() {
    if (en % 2) return false;
    sort(even, even + en, cmp);
    for (int i = 0; i < en; i += 2) {
        if ((int)even[i].size() != (int)even[i + 1].size()) return false;
        int sz = even[i].size();
        for (int j = 0; j < sz; j++) {
            b[even[i][j]] = even[i + 1][j];
            b[even[i + 1][j]] = even[i][(j + 1) % sz];
        }
    }
    for (int i = 0; i < on; i++) {
        int sz = odd[i].size();
        for (int j = 0; j < (sz + 1) / 2; j++) {
            b[odd[i][j]] = odd[i][(j + (sz + 1) / 2) % sz];
            if (j + (sz + 1) / 2 < sz) b[odd[i][j + (sz + 1) / 2]] = odd[i][j + 1];
        }
    }
    return true;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            vector<int> tmp;
            tmp.push_back(i);
            int t = a[i];
            int cnt = 1;
            while (!vis[t]) {
                vis[t] = 1;
                tmp.push_back(t);
                t = a[t];
            }
            if ((int)tmp.size() % 2) odd[on++] = tmp;
            else even[en++] = tmp;
        }
    }
    if (!judge()) printf("-1\n");
    else {
        for (int i = 1; i <= n; i++)
            printf("%d%c", b[i], i == n ? '\n' : ' ');
    }
    return 0;
}