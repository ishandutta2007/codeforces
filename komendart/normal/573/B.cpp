#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n + 2, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> old = a;
    for (int i = 1; i <= n; i++) {
        a[i] = min(old[i] - 1, min(old[i - 1], old[i + 1]));
    }

    int nonzero = 0;
    map<int, set<int> > data;
    set<int> left, right;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) {
            left.insert(i + 1);
            right.insert(i - 1);
        } else {
            nonzero++;
            if (data.find(a[i]) == data.end()) data[a[i]] = set<int>();
            data[a[i]].insert(i);
        }
    }

    int op = 1;
    for (; nonzero > 0; op++) {
        set<int> tmp;
        tmp.swap(left);
        for (auto i: tmp) {
            if (a[i] != 0) {
                a[i] = 0;
                nonzero--;
                left.insert(i + 1);
            }
        }
        tmp.clear();
        tmp.swap(right);
        for (auto i: tmp) {
            if (a[i] != 0) {
                a[i] = 0;
                nonzero--;
                right.insert(i - 1);
            }
        }
        if (data.find(op) != data.end()) {
            for (auto i: data[op]) {
                if (a[i] != 0) {
                    a[i] = 0;
                    nonzero--;
                    left.insert(i + 1);
                    right.insert(i - 1);
                }
            }
        }
    }

    cout << op << '\n';
}