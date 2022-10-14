#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 300005;

int t, n, br, sol;
int par[MAXN], par2[MAXN], lo[MAXN], hi[MAXN];
vector <int> ch[MAXN], ch2[MAXN];
set <pi> st;

void dfs (int x) {
    lo[x] = hi[x] = br++;
    for (auto sus : ch2[x]) {
        dfs(sus);
        hi[x] = hi[sus];
    }
}

void calc (int x) {
    pi del = {-1, -1};
    st.insert({lo[x], hi[x]});
    auto it = st.find({lo[x], hi[x]});

    if (it != st.begin()) {
        auto prv = it; prv--;
        if (hi[x] <= (prv -> second)) {
            del = *prv;
            st.erase(prv);
        }
    }

    auto nxt = it; nxt++;
    if (nxt != st.end()) {
        if ((nxt -> second) <= hi[x]) {
            del = *it;
            st.erase(it);
        }
    }

    sol = max(sol, (int) st.size());

    for (auto sus : ch[x]) {
        calc(sus);
    }

    if (del.first != -1) st.insert(del);
    st.erase({lo[x], hi[x]});
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            ch[i].clear();
            ch2[i].clear();
        }
        for (int i = 2; i <= n; i++) {
            cin >> par[i];
            ch[par[i]].push_back(i);
        }
        for (int i = 2; i <= n; i++) {
            cin >> par2[i];
            ch2[par2[i]].push_back(i);
        }
        br = 0, sol = 0;
        dfs(1);
        calc(1);
        cout << sol << '\n';
    }
    return 0;
}