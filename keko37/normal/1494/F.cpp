#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 3005;

int n, m;
int bio[MAXN], par[MAXN], p[MAXN], cnt[MAXN][2], rem[MAXN][2];
bool del[MAXN][MAXN], last[MAXN];
vector <int> v[MAXN], r, st;

void dfs (int x, int rod, int root) {
    bio[x] = 1;
    par[x] = rod;
    if (rod != 0 && par[rod] == 0) {
        root = x;
        r.push_back(root);
    }
    p[x] = root;
    cnt[root][v[x].size() % 2]++;
    for (auto sus : v[x]) {
        if (sus == rod || bio[sus]) continue;
        dfs(sus, x, root);
    }
}

bool check (int x) {
    for (int i = 1; i <= n; i++) {
        bio[i] = cnt[i][0] = cnt[i][1] = rem[i][0] = rem[i][1] = 0;
    }
    r.clear();
    dfs(x, 0, 0);
    for (auto sus : v[x]) {
        rem[p[sus]][v[sus].size() % 2]++;
    }
    int br = 0;
    for (auto root : r) {
        if (cnt[root][1] - rem[root][1] >= 2) return 0;
        if (cnt[root][1] - rem[root][1] == 1) {
            if (rem[root][0] == 0) return 0;
            br++;
        }
        if (rem[root][0] == 0 && cnt[root][0] + cnt[root][1] != 1) br++;
    }
    if (br >= 2) return 0;
    for (auto sus : v[x]) {
        if (v[sus].size() % 2 == 1) {
            del[x][sus] = del[sus][x] = 1;
            last[sus] = 1;
        }
    }
    int head = -1;
    for (auto root : r) {
        if (rem[root][0] == 0 && cnt[root][0] + cnt[root][1] != 1) {
            head = root;
            break;
        }
    }
    if (head != -1) {
        for (auto sus : v[x]) {
            if (p[sus] == head && v[sus].size() % 2 == 1) {
                del[x][sus] = del[sus][x] = 0;
                last[sus] = 0;
                break;
            }
        }
    }
    return 1;
}

void euler (int x) {
    while (!v[x].empty()) {
        int sus = v[x].back();
        v[x].pop_back();
        if (del[x][sus]) continue;
        del[x][sus] = del[sus][x] = 1;
        euler(sus);
        st.push_back(sus);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (check(i)) {
            euler(i);
            st.push_back(i);
            st.push_back(-1);
            for (int j = 1; j <= n; j++) {
                if (last[j]) {
                    st.push_back(j);
                    st.push_back(i);
                }
            }
            cout << st.size() << '\n';
            for (auto x : st) cout << x << " ";
            return 0;
        }
    }
    cout << 0;
    return 0;
}