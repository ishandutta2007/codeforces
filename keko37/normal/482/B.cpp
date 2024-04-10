#include<bits/stdc++.h>

using namespace std;

const int MAXN = 100005;
const int E = (1 << 30) - 1;

int n, m, ofs;
int ll[MAXN], rr[MAXN], q[MAXN];
int p[30][MAXN], val[MAXN], t[MAXN * 4];

void build () {
    ofs = 1;
    while (ofs < n) ofs *= 2;
    for (int i=0; i<2*ofs; i++) {
        t[i] = E;
    }
    for (int i=0; i<n; i++) {
        t[i + ofs] = val[i];
    }
    for (int i=ofs-1; i>0; i--) {
        t[i] = t[2*i] & t[2*i+1];
    }
}

int upit (int x, int from, int to, int low, int high) {
    if (from <= low && high <= to) return t[x];
    if (to < low || high < from) return E;
    return upit(2*x, from, to, low, (low + high)/2) & upit(2*x+1, from, to, (low + high)/2+1, high);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        cin >> ll[i] >> rr[i] >> q[i];
        ll[i]--; rr[i]--;
        for (int j=0; j<30; j++) {
            if (q[i] & (1 << j)) {
                p[j][ll[i]]++;
                p[j][rr[i] + 1]--;
            }
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<30; j++) {
            if (i > 0) p[j][i] += p[j][i-1];
            if (p[j][i]) val[i] += (1 << j);
        }
    }
    build();
    for (int i=0; i<m; i++) {
        if (upit(1, ll[i], rr[i], 0, ofs-1) != q[i]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES" << endl;
    for (int i=0; i<n; i++) {
        cout << val[i] << " ";
    }
    return 0;
}