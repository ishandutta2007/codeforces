#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <llint, llint> pi;

const int MAXN = 400005;

int n, q, ofs = 1;
llint s[MAXN], tip[MAXN], a[MAXN];
llint br[MAXN * 4], sum[MAXN * 4], upp[MAXN * 4], dwn[MAXN * 4];
vector <llint> saz;

void spoji (int a, int b, int c) {
    br[c] = br[a] + br[b];
    sum[c] = sum[a] + sum[b];
    upp[c] = upp[a] + upp[b] + sum[b] * br[a];
    dwn[c] = dwn[a] + dwn[b] + sum[a] * br[b];
}

void tour_init () {
    while (ofs < saz.size()) ofs *= 2;
    for (int i = 1; i <= n; i++) {
        int pos = lower_bound(saz.begin(), saz.end(), s[i]) - saz.begin();
        br[pos + ofs] = 1;
        sum[pos + ofs] = upp[pos + ofs] = dwn[pos + ofs] = s[i];
    }
    for (int i = ofs - 1; i > 0; i--) {
        spoji(2 * i, 2 * i + 1, i);
    }
}

void update (int pos, llint val) {
    pos += ofs;
    if (br[pos]) {
        br[pos] = sum[pos] = upp[pos] = dwn[pos] = 0;
    } else {
        br[pos] = 1;
        sum[pos] = upp[pos] = dwn[pos] = val;
    }
    pos /= 2;
    while (pos > 0) {
        spoji(pos * 2, pos * 2 + 1, pos);
        pos /= 2;
    }
}

llint pref_sum (int x, int k) {
    if (k == br[x]) return sum[x];
    if (k <= br[2 * x]) return pref_sum(2 * x, k);
    return sum[2 * x] + pref_sum(2 * x + 1, k - br[2 * x]);
}

llint suf_sum (int x, int k) {
    if (k == br[x]) return sum[x];
    if (k <= br[2 * x + 1]) return suf_sum(2 * x + 1, k);
    return sum[2 * x + 1] + suf_sum(2 * x, k - br[2 * x + 1]);
}

llint pref_dwn (int x, int k) {
    if (k == br[x]) return dwn[x];
    if (k <= br[2 * x]) return pref_dwn(2 * x, k);
    return dwn[2 * x] + sum[2 * x] * (k - br[2 * x]) + pref_dwn(2 * x + 1, k - br[2 * x]);
}

llint suf_upp (int x, int k) {
    if (k == br[x]) return upp[x];
    if (k <= br[2 * x + 1]) return suf_upp(2 * x + 1, k);
    return upp[2 * x + 1] + sum[2 * x + 1] * (k - br[2 * x + 1]) + suf_upp(2 * x, k - br[2 * x + 1]);
}

llint calc () {
    if (br[1] == 0) return 0;
    int lo = 1, hi = (br[1] + 1) / 2;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        llint pref = pref_sum(1, mid);
        llint suf = suf_sum(1, mid - 1);
        if (pref - suf > 0) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    int k = lo;
    llint sol = 0;
    if (k - 1 > 0) {
        sol += 2 * (suf_upp(1, k - 1) - pref_dwn(1, k - 1));
    }
    if (k * 2 != br[1] + 1) sol += suf_sum(1, br[1] - k) - pref_sum(1, k);
    return sol;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        saz.push_back(s[i]);
    }
    for (int i = 1; i <= q; i++) {
        cin >> tip[i] >> a[i];
        saz.push_back(a[i]);
    }
    sort(saz.begin(), saz.end());
    saz.erase(unique(saz.begin(), saz.end()), saz.end());
    tour_init();
    cout << calc() << endl;
    for (int i = 1; i <= q; i++) {
        int pos = lower_bound(saz.begin(), saz.end(), a[i]) - saz.begin();
        update(pos, a[i]);
        cout << calc() << endl;
    }
    return 0;
}