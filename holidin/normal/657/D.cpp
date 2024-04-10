#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 3e5 + 1;
vector <pair<int, int> > hv[N];
vector <int> pv;
int ct[N], t[N], p[N];
long double mxcost[N], mncost[N];
vector <pair<long double, int> > v;
map <int, int> num;

int main() {
    int i, j;
    long long n, k, b, c, cc;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> p[i];
        pv.push_back(p[i]);
    }
    sort(pv.begin(), pv.end());
    pv.erase(unique(pv.begin(), pv.end()), pv.end());
    for (i = 0; i < pv.size(); ++i)
        num[pv[i]] = i + 1;
    for (i = 0; i < n; ++i)
        ct[i] = num[p[i]];
    long double T = 0;
    for (i = 0; i < n; ++i) {
        cin >> t[i];
        T += t[i];
        v.push_back({-p[i] * 1.0 / t[i], i});
    }
    sort(v.begin(), v.end());
    long double l = 0, r = 1;
    for (i = 0; i < 100; ++i) {
        long double mid = (l + r) / 2;
        long double time = 0;
        for (j = 0; j <= n; ++j) {
            mxcost[j] = 0;
            mncost[j] = 1e18;
        }
        j = 0;
        while (j < v.size()) {
            int u = j;
            long double tme = 0;
            while (u < v.size() && abs(v[j].fi - v[u].fi) < 1e-10) {
                tme += t[v[u].se];
                ++u;
            }
            long long ss = 0;
            while (j < u) {
                mncost[ct[v[j].se]] = min(mncost[ct[v[j].se]], p[v[j].se] * (1 - mid * (time + tme) / T));
                ss += mncost[ct[v[j].se]];
                mxcost[ct[v[j].se]] = max(mxcost[ct[v[j].se]], p[v[j].se] * (1 - mid * (time + t[v[j].se]) / T));
                ++j;
            }
            time += tme;
        }
        bool flag = false;
        for (j = 1; j < pv.size(); ++j)
        if (mxcost[j] > mncost[j + 1] + 1e-10)
            flag = true;
        if (flag)
            r = mid;
        else
            l = mid;
    }
    cout << fixed << setprecision(10) << l;
}