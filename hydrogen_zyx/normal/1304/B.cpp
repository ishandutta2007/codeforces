#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
char c[120][80];
int n, m;
bool tong(int p1, int p2);
bool hui(int p);
int main() {
    ios::sync_with_stdio(false);
    vector<pair<int, int> > v;
    vector<int> vv;
    bool used[120];
    int len = 0;
    memset(used, 0, sizeof(used));
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (int i = 1; i < n; i++) {
        if (used[i]) continue;
        for (int j = i + 1; j <= n; j++) {
            if (used[j] || i == j) continue;
            if (tong(i, j)) {
                len += 2 * m;
                used[i] = used[j] = 1;
                v.push_back(pair<int, int>(i, j));
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (used[i]) continue;
        if (hui(i)) vv.push_back(i);
    }
    bool you = 0;
    if (!vv.empty()) {
        len += m;
        you = 1;
    }
    if (len == 0) {
        cout << 0;
        return 0;
    }
    cout << len << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << c[v[i].first];
    }
    if (you) cout << c[vv[0]];
    for (int i = v.size() - 1; i >= 0; i--) {
        cout << c[v[i].second];
    }
}
bool tong(int p1, int p2) {
    char ch[80];
    strcpy(ch, c[p1]);
    reverse(ch, ch + strlen(ch));
    if (strcmp(ch, c[p2]) == 0)
        return 1;
    else
        return 0;
}
bool hui(int p) {
    char ch[80];
    strcpy(ch, c[p]);
    reverse(ch, ch + strlen(ch));
    if (strcmp(ch, c[p]) == 0)
        return 1;
    else
        return 0;
}