#include <bits/stdc++.h>

using namespace std;

const int N = 100000;

int n, ans;
int cd[N][4];

void kill() {
    puts("NO");
    exit(0);
}

void solve(vector<set<pair<int, int>>*> a) {
    if ((*a[0]).size() == 1) return;
    int mx[4];
    for (int i = 0; i < 4; ++i) mx[i] = 0x80000000;
    set<pair<int, int>>::iterator it[4];
    for (int i = 0; i < 4; ++i) it[i] = (*a[i]).begin();
    bool flag = false;
    vector<int> c;
    for (int i = 1, sz = (*a[0]).size(); i < sz; ++i) {
        for (int j = 0; j < 4; ++j) {
            mx[j] = max(mx[j], -cd[(*it[j]).second][j ^ 2]);
        }
        for (int j = 0; j < 4; ++j) {
            ++it[j];
            if ((*it[j]).first >= mx[j]) {
                set<pair<int, int>>::iterator jt = (*a[j]).begin();
                for (; jt != it[j]; ++jt) c.push_back((*jt).second);
                flag = true;
                break;
            }
        }
        if (flag) break;
    }
    if (!flag) kill();
    vector<set<pair<int, int>>*> b;
    for (int i = 0; i < 4; ++i) b.push_back(new set<pair<int, int>>);
    for (auto i : c) {
        for (int j = 0; j < 4; ++j) {
            (*a[j]).erase({cd[i][j], i});
            (*b[j]).insert({cd[i][j], i});
            ++ans;
        }
    }
    solve(a);
    solve(b);
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) scanf("%d", &cd[i][j]);
    }
    vector<set<pair<int, int>>*> a;
    for (int i = 0; i < 4; ++i) a.push_back(new set<pair<int, int>>);
    for (int i = 0; i < n; ++i) {
        cd[i][2] *= -1;
        cd[i][3] *= -1;
        for (int j = 0; j < 4; ++j) (*a[j]).insert({cd[i][j], i});
    }
    solve(a);
    puts("YES");
    return 0;
}