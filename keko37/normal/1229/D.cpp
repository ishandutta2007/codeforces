#include<bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

long long sol;
int n, k, cnt;
int a[MAXN];
int p[125][6], ind[MAXN];
int g[125][125], bio[125], pos[125];
set < pair <int, int> > st;
vector <int> v;
vector < pair <int, int> > pii;
queue <int> q;

void precompute () {
    int r[6] = {0, 1, 2, 3, 4, 5};
    do {
        int br = 0;
        for (int i=1; i<=k; i++) {
            br = br * 10 + r[i];
            p[cnt][i] = r[i];
        }
        ind[br] = cnt;
        cnt++;
    } while (next_permutation(r + 1, r + 1 + k));
    for (int i=0; i<cnt; i++) {
        for (int j=0; j<cnt; j++) {
            int br = 0;
            for (int h = 1; h <= k; h++) {
                br = br * 10 + p[i][p[j][h]];
            }
            g[i][j] = ind[br];
        }
    }
}

int bfs () {
    memset(bio, 0, sizeof bio);
    int res = 0;
    for (auto x : v) {
        bio[x] = 1;
        q.push(x);
        res++;
    }
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto y : v) {
            int sus = g[x][y];
            if (bio[sus] == 0) {
                bio[sus] = 1;
                q.push(sus);
                res++;
            }
        }
    }
    return res;
}

void calc () {
    for (int i=0; i<cnt; i++) {
        pos[i] = -1;
    }
    for (int i=0; i<n; i++) {
        if (st.find({pos[a[i]], a[i]}) != st.end()) st.erase({pos[a[i]], a[i]});
        pos[a[i]] = i;
        st.insert({pos[a[i]], a[i]});
        memset(bio, 0, sizeof bio);
        v.clear(); pii.clear();
        for (auto it = st.rbegin(); it != st.rend(); it++) {
            int novi = it -> second;
            if (bio[novi] == 0) {
                v.push_back(novi);
                pii.push_back({bfs(), it -> first});
            }
        }
        sol += 1LL * pii.back().first * (pii.back().second + 1);
        for (int j = (int) pii.size() - 2; j >= 0; j--) {
            sol += 1LL * pii[j].first * (pii[j].second - pii[j + 1].second);
        }
    }
}

int main () {
    cin >> n >> k;
    precompute();
    for (int i=0; i<n; i++) {
        int br = 0;
        for (int j=0; j<k; j++) {
            int x;
            cin >> x;
            br = br * 10 + x;
        }
        a[i] = ind[br];
    }
    calc();
    cout << sol;
    return 0;
}