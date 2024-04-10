#include <bits/stdc++.h>
using namespace std;

vector<int> order;

int f(const vector<int>& v, int l, int r, int idx, int cur_height) {
    if (idx == order.size() || l == r) {
        return 0;
    }

    int next = order[idx];
    // case 1
    // --------
    // --------
    int result = next - cur_height;
    int last = l;
    for (int i = l; i < r; i++) {
        if (result >= r - l) break;
        if (v[i] == next) {
            result += f(v, last, i, idx+1, next);
            last = i + 1;
        }
    }
    if (result < r - l) {
        result += f(v, last, r, idx+1, next);
    }

    return min(result, r-l);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    set<int> s(v.begin(), v.end());
    order = {s.begin(), s.end()};

    cout << f(v, 0, n, 0, 0) << endl;


    return 0;
}