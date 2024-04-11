#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 33333;
vector< pair< pair<int, int>, int> > p[N];
int w[N];

bool check(int x, int y, int z) {
    if (w[y] + 1 + (y == z) - (y == x) > 9) return false;
    if (w[z] + 1 + (y == z) - (z == x) > 9) return false;
    return true;
}


int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int n;
    scanf("%d", &n);

    queue<int> q1, q2;
    for (int i = 0; i < 4*n; ++i) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        p[x].push_back(make_pair(make_pair(y, z), i + 1));
        q1.push(x);
        w[x] += 1;
    }
    vector<int> ans;
    while (!q1.empty() || !q2.empty()) {
        bool diffq1 = false, diffq2 = false;
        while (!q1.empty()) {

        while (!q2.empty()) {
            int x = q2.front(); q2.pop();
            diffq2 = true;

            bool found = 0;
            for (int i = 0; i < p[x].size(); ++i) {
                pair<int, int> to = p[x][i].first;
                if ( (to.first != x || to.second != x) && check(x, to.first, to.second)) {
                    ans.push_back(p[x][i].second);
                    --w[x];
                    ++w[to.first];
                    ++w[to.second];
                    q2.push(to.first);
                    q2.push(to.second);
                    diffq2 = true;
                    p[x].erase(p[x].begin() + i);
                    found = 1;
                    break;
                }
            }
            if (!found)
            for (int i = 0; i < p[x].size(); ++i) {
                pair<int, int> to = p[x][i].first;
                if (check(x, to.first, to.second)) {
                    ans.push_back(p[x][i].second);
                    --w[x];
                    ++w[to.first];
                    ++w[to.second];
                    q2.push(to.first);
                    q2.push(to.second);
                    diffq2 = true;
                    p[x].erase(p[x].begin() + i);
                    found = 1;
                    break;
                }
            }
        }



            int x = q1.front(); q1.pop();
            if (p[x].size() == 0)
                continue;

            bool found = 0;
            for (int i = 0; i < p[x].size(); ++i) {
                pair<int, int> to = p[x][i].first;
                if ( (to.first != x || to.second != x) && check(x, to.first, to.second)) {
                    ans.push_back(p[x][i].second);
                    --w[x];
                    ++w[to.first];
                    ++w[to.second];
                    q2.push(to.first);
                    q2.push(to.second);
                    diffq2 = true;
                    p[x].erase(p[x].begin() + i);
                    found = 1;
                    break;
                }
            }
            if (!found)
            for (int i = 0; i < p[x].size(); ++i) {
                pair<int, int> to = p[x][i].first;
                if (check(x, to.first, to.second)) {
                    ans.push_back(p[x][i].second);
                    --w[x];
                    ++w[to.first];
                    ++w[to.second];
                    q2.push(to.first);
                    q2.push(to.second);
                    diffq2 = true;
                    p[x].erase(p[x].begin() + i);
                    found = 1;
                    break;
                }
            }

            if (!found)
                q1.push(x);
            else
                diffq1 = true;
        }

        if (!diffq1 && !diffq2) break;
    }
    if (ans.size() == n * 4) {
        puts("YES");
        for (int i = 0; i < ans.size(); ++i)
            printf("%d ", ans[i]);
        puts("");
    } else {
        puts("NO");
    }

    return 0;
}