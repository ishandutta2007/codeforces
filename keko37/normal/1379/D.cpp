#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 100005;

int n, h, m, k, curr, t;
map <int, int> mp;
int hh[MAXN], mm[MAXN];

void sweep () {
    int mn = 1e9;
    curr = 0, t = -1;
    for (auto par : mp) {
        if (par.first >= m) break;
        curr += par.second;
        if (curr < mn) {
            mn = curr;
            t = par.first;
        }
    }
    cout << mn << " " << (t + k) % m << endl;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> h >> m >> k;
    m /= 2;
    mp[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> hh[i] >> mm[i];
        mm[i] %= m;
        int lo = mm[i] - (k - 1);
        int hi = mm[i] - 1;
        if (lo < 0) lo += m;
        if (hi < 0) hi += m;
        mp[lo]++;
        mp[hi + 1]--;
        if (lo > hi) mp[0]++;
    }
    if (k <= 2) {
        cout << 0 << " " << 0;
        return 0;
    }
    sweep();
    for (int i = 0; i < n; i++) {
        int lo = mm[i] - (k - 1);
        int hi = mm[i] - 1;
        if (lo < 0) lo += m;
        if (hi < 0) hi += m;
        if ((lo <= hi && lo <= t && t <= hi) || (lo > hi && (lo <= t || t <= hi))) cout << i + 1 << " ";
    }
    return 0;
}