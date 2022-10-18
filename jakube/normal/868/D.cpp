#include <bits/stdc++.h>
using namespace std;

using bs = bitset<(1<<15)>;

void insert(bs &b, int length, int value) {
    if (length > 14) return;
    b[(1<<length) - 2 + value] = true;
}

vector<bs> goals;

int findMax(bs &b) {
    for (int i = 15 - 1; i > 0; i--) {
        if ((b & goals[i]) == goals[i])
            return i;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    goals.resize(15);
    for (int i = 1; i < 15; i++) {
        goals[i].reset();
        for (int j = 0; j < (1 <<i); j++) {
            insert(goals[i], i, j);
        }
    }


    int n;
    cin >> n;
    vector<bs> v(201);
    // vector<string> ss(201);
    vector<string> starts(201), ends(201);
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        // ss[i] = s;
        starts[i] = s;
        ends[i] = s;
        v[i].reset();
        int sz = s.size();
        for (int a = 0; a < sz; a++) {
            int value = 0;
            for (int b = a; b < sz; b++) {
                value = 2*value + (s[b] - '0');
                insert(v[i], b + 1 - a, value);
            }
        }
    }

    int Q;
    cin >> Q;
    for (int q = 1; q <= Q; q++) {
        int x, y;
        cin >> x >> y;
        v[n + q] = v[x] | v[y];
        if (starts[x].size() < 14) {
            string sss = starts[x] + starts[y];
            starts[n+q] = sss;
        } else {
            starts[n+q] = starts[x];
        }

        if (ends[y].size() < 14) {
            string sss = ends[x] + ends[y];
            ends[n+q] = sss;
        } else {
            ends[n+q] = ends[y];
        }

        //overlapping
        auto &s1 = ends[x];
        auto &s2 = starts[y];
        int sz1 = s1.size();
        int sz2 = s2.size();
        for (int a = max(0, sz1 - 15); a < sz1; a++) {
            int value = 0;
            int length = 0;
            for (int b = a; b < sz1 + min(15, sz2); b++) {
                length++;
                value = 2*value + (b < sz1 ? s1[b] - '0' : s2[b - sz1] - '0');
                insert(v[n + q], length, value);
            }
        }

        cout << findMax(v[n + q]) << endl;

    }
}