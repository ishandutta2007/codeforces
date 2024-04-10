#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 200005;

llint m, n, ofs, step;
pair <llint, llint> a[MAXN], b[MAXN];
vector <llint> va, vb;
llint fen[MAXN], sol[MAXN];

void ubaci (int x, llint val) {
    for (x++; x < MAXN; x += x&-x) fen[x] += val;
}

llint upit (int x) {
    llint res = 0;
    for (x++; x > 0; x -= x&-x) res += fen[x];
    return res;
}

void update (int x, int y, llint val) {
    if (x > y) return;
    x = (x + ofs) % n; y = (y + ofs) % n;
    if (step == 1) {x = (n - x) % n; y = (n - y) % n; swap(x, y);}
    if (x > y) ubaci(0, val);
    //cout << "bla " << x << " " << y << " " << val << endl;
    ubaci(x, val);
    ubaci(y + 1, -val);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i].first;
        a[i].first--; a[i].second = i;
    }
    for (int i=0; i<n; i++) {
        cin >> b[i].first;
        b[i].first--; b[i].second = i;
    }
    sort(a, a + n);
    sort(b, b + n);
    for (int i=0; i<n; i++) va.push_back(a[i].first);
    for (int i=0; i<n; i++) vb.push_back(b[i].first);
    for (step = 0; step < 2; step++) {
        for (int i=0; i<n; i++) {
            ofs = (n - i) % n;
            //cout << "sad na " << i << "  ";
            if (m & 1) {
                int p1 = lower_bound(vb.begin(), vb.end(), va[i]) - vb.begin();
                int p2 = upper_bound(vb.begin(), vb.end(), va[i]) - vb.begin();
                int p3 = upper_bound(vb.begin(), vb.end(), (va[i] + m/2) % m) - vb.begin();
                //cout << p1 << " " << p2 << " " << p3 << endl;
                if (va[i] < (m+1)/2) {
                    update(0, p1 - 1, va[i]);
                    update(p2, p3 - 1, -va[i]);
                    update(p3, n - 1, va[i] + m * (step == 0));
                } else {
                    update(0, p3 - 1, -va[i] + m * (step == 0));
                    update(p3, p1 - 1, va[i]);
                    update(p2, n - 1, -va[i]);
                }
            } else {
                int p1 = lower_bound(vb.begin(), vb.end(), va[i]) - vb.begin();
                int p2 = upper_bound(vb.begin(), vb.end(), va[i]) - vb.begin();
                int p3 = lower_bound(vb.begin(), vb.end(), (va[i] + m/2) % m) - vb.begin();
                int p4 = upper_bound(vb.begin(), vb.end(), (va[i] + m/2) % m) - vb.begin();
                //cout << p1 << " " << p2 << " " << p3 << " " << p4 << endl;
                if (va[i] < (m+1)/2) {
                    update(0, p1 - 1, va[i]);
                    update(p2, p3 - 1, -va[i]);
                    update(p4, n - 1, va[i] + m * (step == 0));
                    if (step == 0) update(p3, p4 - 1, m/2);
                } else {
                    update(0, p3 - 1, -va[i] + m * (step == 0));
                    update(p4, p1 - 1, va[i]);
                    update(p2, n - 1, -va[i]);
                    if (step == 0) update(p3, p4 - 1, m/2);
                }
            }
        }
        swap(va, vb);
    }
    llint mn = 1e18;
    for (int i=0; i<n; i++) {
        llint val = upit(i);
        if (val < mn) {
            mn = val;
            ofs = i;
        }
    }
    for (int i=0; i<n; i++) {
        sol[a[i].second] = b[(i + ofs) % n].second;
    }
    cout << mn << endl;
    for (int i=0; i<n; i++) {
        cout << sol[i] + 1 << " ";
    }
    return 0;
}