#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

llint t, n;
llint curr, sign;

bool pitaj (llint val) {
    cout << "? " << val << endl;
    int res; cin >> res;
    return res;
}

llint get_start (llint x) {
    if (x <= 2) return 1;
    return x / 2 + 1 - get_start(x / 2) + x % 2;
}

void init (llint x) {
    curr = get_start(x);
    sign = 1;
    pitaj(curr);
}

bool jump (llint len) {
    curr += len * sign;
    sign = -sign;
    return pitaj(curr);
}

llint solve (llint x, bool tip, llint ofs) {
    //cout << "solve " << x << " " << tip << " " << ofs << endl;
    if (x + tip <= 1) return 1;
    llint len = x / 2 + tip;
    bool res = jump(len + ofs);
    return solve(x / 2, (x%2) ^ tip ? !(res ^ tip) : tip, ofs + !res * len) + !res * len;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        init(n);
        llint sol = solve(n, 0, 0);
        cout << "= " << sol << endl;
    }
    return 0;
}