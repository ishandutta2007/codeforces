#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int BN = 800888;
vector<int> sit[BN][2];
int b[BN][26], bn = 0;
char buf[BN];

vector< pair<int, int> > ans;
ll ansv;

inline void imerge(vector<int>& v1, vector<int>& v2) {
    if (v2.size() > v1.size()) {
        v2.swap(v1);
    }
    if (v2.size() > 0) {
        v1.insert(v1.end(), v2.begin(), v2.end());
    }
}

void dfs(int x, int depth, vector<int>& t1, vector<int>& t2) {
    imerge(t1, sit[x][0]);
    imerge(t2, sit[x][1]);

    while (t1.size() > 0 && t2.size() > 0) {
        int x = t1.back();
        int y = t2.back();
        t1.pop_back();
        t2.pop_back();
        ans.push_back({x, y});
        ansv += depth;
    }

    for (int i = 0; i < 26; ++i)
        if (b[x][i]) {
            vector<int> tc1;
            vector<int> tc2;
            dfs(b[x][i], depth + 1, tc1, tc2);
            while (t1.size() > 0 && tc2.size() > 0) {
                int x = t1.back();
                int y = tc2.back();
                t1.pop_back();
                tc2.pop_back();
                ans.push_back({x, y});
                ansv += depth;
            }
            while (t2.size() > 0 && tc1.size() > 0) {
                int x = tc1.back();
                int y = t2.back();
                tc1.pop_back();
                t2.pop_back();
                ans.push_back({x, y});
                ansv += depth;
            }
            imerge(t1, tc1);
            imerge(t2, tc2);
        }
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int n;
    scanf("%d\n", &n);
    for (int i = 0; i < n; ++i) {
        gets(buf);
        int cur = 0;
        for(int j = 0; buf[j]; ++j) {
            if (!b[cur][buf[j] - 'a']) 
                b[cur][buf[j] - 'a'] = ++bn;
            cur = b[cur][buf[j] - 'a'];
        }
        sit[cur][0].push_back(i);
    }
    for (int i = 0; i < n; ++i) {
        gets(buf);
        int cur = 0;
        for(int j = 0; buf[j]; ++j) {
            if (!b[cur][buf[j] - 'a']) 
                b[cur][buf[j] - 'a'] = ++bn;
            cur = b[cur][buf[j] - 'a'];
        }
        sit[cur][1].push_back(i);
    }
    assert(bn < BN);

    vector<int> v1, v2;
    dfs(0, 0, v1, v2);
    assert(v1.size() == 0);
    assert(v2.size() == 0);
    assert(ans.size() == n);

    printf("%I64d\n", ansv);
    for (int i = 0; i < ans.size(); ++i)
        printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
    
    return 0;
}