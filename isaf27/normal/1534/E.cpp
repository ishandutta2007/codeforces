/*
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
*/

#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
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
const ld eps = 1e-10;
const ll INF = (ll)(4e18 + 239);
const int BIG = (int)(1e9 + 239);
const int MOD = 1e9 + 7;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
#ifdef ONPC
mt19937_64 rnd(239);
#else
mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

//constants
const int M = (int)(4e5 + 239);
const int N = (int)(2e3 + 10);
const int L = 21;
const int T = (1 << 18) + 239;
const int B = 510;
const int X = 2010;

int n, k;

int ask(const vector<int>& ids) {
    cout << "? ";
    for (int i : ids) {
        cout << i + 1 << " ";
    }
    cout << endl;
    int x;
    cin >> x;
    return x;
}

void answer(int x) {
    cout << "! " << x << endl;
    exit(0);
}

int gett(const vector<int>& ids) {
    assert(ids.size() % 2 == 0);
    if (ids.size() == 0) {
        return 0;
    }
    if (ids.size() == k) {
        return ask(ids);
    }
    vector<bool> used(n, false);
    for (int i : ids) {
        used[i] = true;
    }
    vector<int> other;
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            other.emplace_back(i);
        }
    }
    other.resize(k - ((int)ids.size() / 2));
    vector<int> id1(other);
    for (int i = 0; i < (int)ids.size() / 2; i++) {
        id1.emplace_back(ids[i]);
    }
    vector<int> id2(other);
    for (int i = 0; i < (int)ids.size() / 2; i++) {
        id2.emplace_back(ids[i + ((int)ids.size() / 2)]);
    }
    return ask(id1) ^ ask(id2);
}

int32_t main() {
#ifdef ONPC
    //freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> k;
    if (k % 2 == 0 && n % 2 == 1) {
        cout << "-1" << endl;
        return 0;
    }
    if (n % k == 0) {
        int ans = 0;
        for (int i = 0; i < (n / k); i++) {
            vector<int> ids;
            for (int j = 0; j < k; j++) {
                ids.emplace_back(i * k + j);
            }
            ans ^= ask(ids);
        }
        answer(ans);
    }
    if (n >= 2 * k && (k + (n % k)) % 2 == 0) {
        int ans = 0;
        for (int i = 0; i < (n / k) - 1; i++) {
            vector<int> ids;
            for (int j = 0; j < k; j++) {
                ids.emplace_back(i * k + j);
            }
            ans ^= ask(ids);
        }
        vector<int> ids;
        for (int i = ((n / k) - 1) * k; i < n; i++) {
            ids.emplace_back(i);
        }
        ans ^= gett(ids);
        answer(ans);
    }
    if ((n % k) % 2 == 0) {
        int ans = 0;
        for (int i = 0; i < (n / k); i++) {
            vector<int> ids;
            for (int j = 0; j < k; j++) {
                ids.emplace_back(i * k + j);
            }
            ans ^= ask(ids);
        }
        vector<int> ids;
        for (int i = ((n / k)) * k; i < n; i++) {
            ids.emplace_back(i);
        }
        ans ^= gett(ids);
        answer(ans);
    }
    assert(n <= 2 * k && n % 2 == 0 && k % 2 == 1);
    int len = n - k;
    int ans = 0;
    for (int i = 0; i < (n / (2 * len)); i++) {
        vector<int> ids;
        for (int j = i * len * 2; j < (i + 1) * len * 2; j++) {
            ids.emplace_back(j);
        }
        ans ^= gett(ids);
    }
    vector<int> ids;
    for (int i = (n / (2 * len)) * 2 * len; i < n; i++) {
        ids.emplace_back(i);
    }
    ans ^= gett(ids);
    answer(ans);
    return 0;
}