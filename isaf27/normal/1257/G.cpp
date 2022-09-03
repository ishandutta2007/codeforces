#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define prev _prev
#define y0 _y0
#define kill _kill

//permanent constants
const ld pi = acos(-1.0);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int alf = 26;
const int dig = 10;
const int two = 2;
const int th = 3;
const ll prost = 239;
const ll btc = 30;
const ld eps = 1e-8;
const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(1e9 + 239);
//const int MOD = 998244353; // (int)(1e9 + 7);
//const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937_64 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 18;
const int T = (1 << 20);
const int B = 500;
const int X = 3e6 + 239;

const int MOD = 998244353; // 2^23 * 7 * 17 - 1

int power(int a, int k)
{
    if (k == 0)
        return 1;
    int t = power(a, k >> 1);
    t = 1LL * t * t % MOD;
    if (k & 1)
        t = 1LL * t * a % MOD;
    return t;
}

const int wp = power(3, 7 * 17); // w^(2^23) == 1

namespace fft {
    int k;
    vector<int> rev;
    vector<int> st;

    void fft(vector<int> &a) {
        for (int i = 0; i < k; i++)
            if (rev[i] < i)
                swap(a[rev[i]], a[i]);
        int w, wn, ai, aj;
        for (int s = 1, it = 0; s < k; s <<= 1, it++) {
            wn = st[it];
            for (int l = 0; l < k; l += s + s) {
                w = 1;
                for (int i = l, j = l + s; i < l + s; i++, j++) {
                    ai = a[i];
                    aj = 1LL * w * a[j] % MOD;
                    a[i] = ai + aj;
                    if (a[i] >= MOD)
                        a[i] -= MOD;
                    a[j] = ai - aj;
                    if (a[j] < 0)
                        a[j] += MOD;
                    w = 1LL * w * wn % MOD;
                }
            }
        }
    }

    vector<int> mult(vector<int> a, vector<int> b) {
        k = 1;
        while (k < (int)a.size() + (int)b.size() - 1)
            k <<= 1;
        st.clear();
        st.push_back(power(wp, ((1 << 22) / k)));
        for (int t = 1; t < k; t <<= 1)
            st.push_back(1LL * st.back() * st.back() % MOD);
        reverse(st.begin(), st.end());
        rev.clear();
        rev.resize(k);
        rev[0] = 0;
        for (int i = 1; i < k; i++) {
            if (i & 1)
                rev[i] = rev[i - 1] + (k >> 1);
            else
                rev[i] = rev[i >> 1] >> 1;
        }
        a.resize(k);
        fft(a);
        b.resize(k);
        fft(b);
        vector<int> pr(k);
        for (int i = 0; i < k; i++)
            pr[i] = 1LL * a[i] * b[i] % MOD;
        fft(pr);
        reverse(pr.begin() + 1, pr.end());
        int inv_k = power(k, MOD - 2);
        for (int i = 0; i < k; i++)
            pr[i] = 1LL * pr[i] * inv_k % MOD;
        while (pr.back() == 0)
            pr.pop_back(); // can be removed
        return pr;
    }
}

int n, a[M], cnt[X], k;

vector<int> func(int l, int r)
{
    if (r - l == 1)
        return vector<int>(a[l] + 1, 1);
    int mid = (l + r) >> 1;
    return fft::mult(func(l, mid), func(mid, r));
}

int32_t main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        cnt[p]++;
    }
    k = 0;
    for (int t = 0; t < X; t++)
        if (cnt[t] > 0)
            a[k++] = cnt[t];
    vector<int> res = func(0, k);
    res.resize((n / 2) + 1);
    cout << res[n / 2];
    return 0;
}