#include <bits/stdc++.h>

#define sz(a) static_cast<int>(a.size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int rmax = 22;

vector<vector<int> > maxim, minim;

int getmax(int i, int l)
{
    if (l == 1) {
        return maxim[i][0];
    }
    int d = 0;
    for (; (1 << d) <= l; ++d) ;
    --d;
    return max(maxim[i][d], maxim[i + l - (1 << d)][d]);
}

int getmin(int i, int l)
{
    if (l == 1) {
        return minim[i][0];
    }
    int d = 0;
    for (; (1 << d) <= l; ++d) ;
    --d;
    return min(minim[i][d], minim[i + l - (1 << d)][d]);
}

int main()
{

    //freopen("input.txt", "r", stdin);

    int n, k;
    scanf("%d%d", &n, &k);

    vector<int> v(n), c(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &c[i]);
    }

    maxim.resize(n);
    minim.resize(n);
    for (int i = 0; i < n; ++i) {
        maxim[i].resize(rmax);
        minim[i].resize(rmax);
    }

    for (int i = n - 1; i >= 0; --i) {
        maxim[i][0] = v[i];
        minim[i][0] = c[i];
        for (int r = 1; r < rmax; ++r) {
            int t = i + (1 << (r - 1));
            if (t >= n) {
                maxim[i][r] = maxim[i][r - 1];
                minim[i][r] = minim[i][r - 1];
            } else {
                maxim[i][r] = max(maxim[i][r - 1], maxim[t][r - 1]);
                minim[i][r] = min(minim[i][r - 1], minim[t][r - 1]);
            }
        }
    }

    vector<int> a(n);
    for (int i = n - 1; i >= 0; --i) {
        int l = 1, r = n - i;
        while (l < r) {
            int m = (l + r + 1) >> 1;
            //int L = min(100 * getmax(i, m - 1), getmin(i, m - 1));
            //int R = min(100 * getmax(i, m), getmin(i, m));
            if (100 * getmax(i, m) <= getmin(i, m)) {
                l = m;
            } else {
                r = m - 1;
            }
        }
        a[i] = min(100 * getmax(i, l), getmin(i, l));
        if (l != n - i) {
            a[i] = max(a[i], min(100 * getmax(i, l + 1), getmin(i, l + 1)));
        }
    }

    sort(all(a));

    ld ans = 0;
    ld C = (ld)(k) / (ld)(n);
    int t = n - 1;
    int s = k - 1;

    for (int i = 0; i <= n - k; ++i) {
        if (i) {
            C *= (t - s);
            C /= t;
            --t;
        }
        ans += C * (ld)(a[i]);
    }

    cout << fixed;
    cout.precision(10);
    cout << ans << "\n";

}