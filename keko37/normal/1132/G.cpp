#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1000005;
const int INF = 1000000007;

int n, k, ofs = 1;
int a[MAXN], par[MAXN], lim[MAXN];
int t[4*MAXN], prop[4*MAXN];
vector < pair <int, int> > st;

void ispis () {
    for (int i=1; i<=n; i++) {
        cout << i << " " << lim[i] << endl;
    }
}

void build () {
    st.push_back(make_pair(INF, n+1));
    for (int i=n; i>=1; i--) {
        while (st.back().first <= a[i]) st.pop_back();
        par[i] = st.back().second;
        lim[par[i]] = i;
        st.push_back(make_pair(a[i], i));
    }
    for (int i=1; i<=n; i++) {
        if (lim[i] == 0) {
            lim[i] = i;
        } else {
            lim[i] = lim[lim[i]];
        }
    }
}

void propagate (int x) {
    if (prop[x] == 0) return;
    t[x] += prop[x];
    if (x < ofs) {
        prop[2*x] += prop[x];
        prop[2*x+1] += prop[x];
    }
    prop[x] = 0;
}

void update (int x, int from, int to, int lo, int hi, int val) {
    propagate(x);
    if (from <= lo && hi <= to) {
        prop[x] += val;
        propagate(x);
        return;
    }
    if (to < lo || hi < from) return;
    update(2*x, from, to, lo, (lo+hi)/2, val);
    update(2*x+1, from, to, (lo+hi)/2+1, hi, val);
    t[x] = max(t[2*x], t[2*x+1]);
}

int upit (int x, int from, int to, int lo, int hi) {
    propagate(x);
    if (from <= lo && hi <= to) return t[x];
    if (to < lo || hi < from) return 0;
    return max(upit(2*x, from, to, lo, (lo+hi)/2), upit(2*x+1, from, to, (lo+hi)/2+1, hi));
}

void solve () {
    while (ofs < n+1) ofs *= 2;
    for (int i=1; i<k; i++) {
        update(1, lim[i], i, 0, ofs-1, 1);
    }
    for (int i=1; i+k-1<=n; i++) {
        update(1, lim[i+k-1], i+k-1, 0, ofs-1, 1);
        cout << upit(1, i, i+k-1, 0, ofs-1) << " ";
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    build();
    solve();
    return 0;
}