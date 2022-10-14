#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 100005;
const llint INF = 1000000000000000000LL;

llint n, p;
llint t[MAXN], sol[MAXN];
set < pair <llint, int> > st, bk;
set <int> wait, q;
deque < pair <llint, int> > dq;

void rjesi () {
    while (!st.empty() || !bk.empty()) {
        llint v = INF;
        if (!st.empty()) v = min(v, st.begin() -> first);
        if (!bk.empty()) v = min(v, bk.begin() -> first);
        while (!bk.empty() && (bk.begin() -> first) == v) {
            int ind = bk.begin() -> second;
            bk.erase(bk.begin());
            q.erase(ind);
            dq.pop_front();
        }
        while (!st.empty() && (st.begin() -> first) == v) {
            int ind = st.begin() -> second;
            st.erase(st.begin());
            wait.insert(ind);
        }
        while (!wait.empty() && (q.empty() || *wait.begin() < *q.begin())) {
            int ind = *wait.begin();
            wait.erase(ind);
            q.insert(ind);
            if (dq.empty()) {
                sol[ind] = v;
                dq.push_back({sol[ind], ind});
            } else {
                sol[ind] = dq.back().first + p;
                dq.push_back({sol[ind], ind});
            }
            bk.insert({sol[ind] + p, ind});
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> p;
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
        st.insert({t[i], i});
    }
    rjesi();
    for (int i = 1; i <= n; i++) {
        cout << sol[i] + p << " ";
    }
    return 0;
}