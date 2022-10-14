#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

int n;

int pitaj (int ind) {
    if (ind == 0 || ind == n + 1) return 1e9;
    cout << "? " << ind << endl;
    int res;
    cin >> res;
    return res;
}

int solve (int lo, int hi) {
    if (lo == hi) return lo;
    if (hi == lo + 1) {
        if (pitaj(lo) < pitaj(hi)) return lo;
        return hi;
    }
    int mid = (lo + hi) / 2;
    if (pitaj(mid) < pitaj(mid + 1)) return solve(lo, mid);
    return solve(mid + 1, hi);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int sol = solve(1, n);
    cout << "! " << sol << endl;
    return 0;
}