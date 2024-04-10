#include <bits/stdc++.h>
using namespace std;

struct S
{
    int l, r, idx;
    int result;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    vector<S> q(m);
    for (int i = 0; i < m; i++) {
        cin >> q[i].l >> q[i].r;
        q[i].l--;
        q[i].idx = i;
    }
    
    sort(q.begin(), q.end(), [](S p, S q) {
        int p_idx = p.l / 333;
        int q_idx = q.l / 333;
        if (p_idx < q_idx)
            return true;
        if (p_idx > q_idx)
            return false;
        return p.r < q.r;
    });

    vector<int> cnts(1e5+1, 0);
    int result = 0;
    int l = 0;
    int r = 0;
    for (auto &Q : q) {
        while (Q.l < l) {
            l--;
            if (v[l] <= 1e5) {
                if (cnts[v[l]] == v[l])
                    result--;
                cnts[v[l]]++;
                if (cnts[v[l]] == v[l])
                    result++;
            }
        }

        while (Q.r > r) {
            if (v[r] <= 1e5) {
                if (cnts[v[r]] == v[r])
                    result--;
                cnts[v[r]]++;
                if (cnts[v[r]] == v[r])
                    result++;
            }
            r++;
        }

        while (Q.l > l) {
            if (v[l] <= 1e5) {
                if (cnts[v[l]] == v[l])
                    result--;
                cnts[v[l]]--;
                if (cnts[v[l]] == v[l])
                    result++;
            }
            l++;
        }

        while (Q.r < r) {
            r--;
            if (v[r] <= 1e5) {
                if (cnts[v[r]] == v[r])
                    result--;
                cnts[v[r]]--;
                if (cnts[v[r]] == v[r])
                    result++;
            }
        }

        Q.result = result;
    }

    sort(q.begin(), q.end(), [](S p, S q) {
        return p.idx < q.idx;
    });

    for (auto Q : q) {
        cout << Q.result << '\n';
    }
}