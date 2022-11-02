#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define mp make_pair
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

int main()
{
    int n;
    cin >> n;
    vector<int64> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        a[i] = x;
    }
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        b[i] = x;
    }
    vi res(n, 0);
    for (int it = 0; it < 2; ++it) {
        vector<int64> v;
        if (it == 0) {
            for (int i = 0; i < n; ++i) {
                v.pb(a[i]);
                v.pb(-b[i]);
            }
        } else {
            for (int i = n - 1; i >= 0; --i) {
                v.pb(a[i]);
                v.pb(-b[(i + n - 1) % n]);
            }
        }
        multiset<int64> S;
        int64 add = 0;
        int64 cur = 0;
        for (int i = 0; i < sz(v); ++i) {
            cur += v[i];
            S.insert(cur);
        }
        cur = 0;
        for (int i = 0; i < sz(v); ++i) {
            if (*S.begin() + add >= 0 && i % 2 == 0) {
                if (it == 0) res[i / 2] = 1;
                else res[n - 1 - i / 2] = 1;
            }
            cur = v[i];
            S.erase(S.find(cur - add));
            add -= v[i];
            S.insert(- add);
        }
    }

    vi vr;
    for (int i = 0; i < sz(res); ++i)
        if (res[i]) vr.pb(i);
    cout << sz(vr) << "\n";
    for (int i = 0; i < sz(vr); ++i)
        printf("%d ", vr[i] + 1);
    printf("\n");
    return 0;
}