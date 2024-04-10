#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

map<pii, int> ret;
int Q(int L, int R) {
    if (ret.count(pii(L, R))) return ret[pii(L, R)];
    cout << "? " << L << ' ' << R << endl;
    cin >> ret[pii(L, R)];
    return ret[pii(L, R)];
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    int m = (1 + n) / 2;
    ret[pii(m + 1, n)] = Q(1, n) - Q(1, m);
    vector<int> A;
    for (int i = 1; i <= n; ++i) {
        if (i <= m) A.push_back(Q(i, n) - Q(i + 1, n));
        else A.push_back(Q(1, i) - Q(1, i - 1));
    }
    cout << '!';
    for (int i : A) cout << ' ' << i;
    cout << endl;
    return 0;
}