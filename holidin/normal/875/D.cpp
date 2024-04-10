#include <bits/stdc++.h>
using namespace std;
const int N = 1000000;

int m[N], m1[N], v, a[N], top;

int dor(int v, int vl, int vr, int l, int r) {
    if ((l <= vl) && (vr <= r))
        return m[v];
    else if ((vl >= r) || (l >= vr))
            return 0;
        else
            return dor(2*v + 1, vl, (vl + vr)/2, l, r) | dor(2*v + 2, (vl + vr)/2, vr, l, r);
}

int dorm(int v, int vl, int vr, int l, int x) {
    ++top;
    if (vr - vl == 1)
        if ((x | m[v]) == x)
            return -1;
        else
            return vl;
    else
        if (l <= vl)
            if ((m[2*v + 1] | x) != x)
                return dorm(2*v + 1, vl, (vl + vr)/2, l, x);
            else
                return dorm(2*v + 2, (vl + vr)/2, vr, l, x);
        else if (l >= (vl + vr)/2)
                return dorm(2*v + 2, (vl + vr)/2, vr, l, x);
            else {
                int p = dorm(2*v + 1, vl, (vl + vr)/2, l, x);
                if (p == -1)
                    return dorm(2*v + 2, (vl + vr)/2, vr, l, x);
                else
                    return p;
            }
}

int dmaxm(int v, int vl, int vr, int l, int x) {
    if (vr - vl == 1)
        if (m1[v] < x)
            return -1;
        else
            return vl;
    else
        if (l <= vl)
            if (m1[2*v + 1] >= x)
                return dmaxm(2*v + 1, vl, (vl + vr)/2, l, x);
            else
                return dmaxm(2*v + 2, (vl + vr)/2, vr, l, x);
        else if (l >= (vl + vr)/2)
                return dmaxm(2*v + 2, (vl + vr)/2, vr, l, x);
            else {
                int p = dmaxm(2*v + 1, vl, (vl + vr)/2, l, x);
                if (p == -1)
                    if (m1[2*v + 2] >= x)
                        return dmaxm(2*v + 2, (vl + vr)/2, vr, l, x);
                    else
                        return -1;
                else
                    return p;
            }
}

int dmax(int v, int vl, int vr, int l, int r) {
    if ((l <= vl) && (vr <= r))
        return m1[v];
    else if ((vl >= r) || (l >= vr))
            return 0;
        else
            return max(dmax(2*v + 1, vl, (vl + vr)/2, l, r), dmax(2*v + 2, (vl + vr)/2, vr, l, r));
}

void als(int i, int j) {
    i = i + v - 2;
    m[i] = j;
    m1[i] = j;
    while (i > 0) {
        i = (i - 1) / 2;
        m[i] = m[2*i + 1] | m[2*i + 2];
        m1[i] = max(m1[2*i + 1], m1[2 * i +  2]);
    }
}

int main() {
    //ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    int i, j, n;
    cin >> n;
     v = 1;
    while (v < n) v *= 2;
    for (i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        als(i, a[i]);
    }
    long long ans = 0;
    for (i = 1; i <= n; ++i) {
        int t = a[i], maxs = a[i];
        j = i;
        bool fate = false;
        while (j <= n) {
            int l = -1;
            for (int i1 = j + 1; i1 <= min(n, j + 10); ++i1)
            if ((a[i1] | t) > t) {
                l = i1;
                break;
            }
            if (l == -1)
                l = dorm(0, 1, v + 1, j + 1, t);
            if (l == -1) {
                int p = 0;
                if (fate)
                    p = dmaxm(0, 1, v + 1, j + 1, t);
                if ((fate) && (p == -1))
                    ans += n + 1 - j;
                else if (fate) {
                    ans += p - j;
                }
                break;
            }
            int l1 = l;
            if (fate && l > j + 1)
                 l = dmaxm(0, 1, v + 1, j + 1, t);
            if (l < 0)
                l = n + 1;
            if (fate)
                l = min(l, l1);
            else
                l = l1;
            if (fate)
                ans += l - j;
            j = l;
            t = t | a[j];
            maxs = max(maxs, a[j]);
            fate = t != maxs;
        }
    }
    cout << ans;
}