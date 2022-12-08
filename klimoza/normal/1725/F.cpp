#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <cmath>
#include <map>
#include <random>
#include <chrono>
#include <fstream>
#include <array>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <sstream> 
#include <cstring>

using namespace std;

#define pb push_back
#define f first
#define s second
#define ull unsigned long long

typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef pair<int, int> pii;

const int MAXN = 1e5 + 10;
//const int MAXM = 21;
ll INF = 1e9 + 10;
ll MOD = 998244353;
ld EPS = 1e-12;

void fastIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//    freopen("/Users/maksimmartynov/Downloads/second_hands_input.txt", "r", stdin);
//    freopen("/Users/maksimmartynov/Downloads/second_hands_validation_output.txt", "w", stdout);
}


int n, q;
int L[MAXN], R[MAXN];
int ans[30];

int calc(int len) {
    int res = 0;
    vector <pii> v;
    for (int i = 0; i < n; i++) {
        if (R[i] - L[i] + 1 >= len) {
            res++;
        } else {
            int l = L[i] % len;
            int r = R[i] % len;
            v.pb({l, 1});
            v.pb({r + 1, -1}); 
            if (l > r) {
                v.pb({0, 1});
            }
        }
    }
    sort(v.begin(), v.end());
    int mx = 0, cur = 0;
    int i = 0;
    while (i < v.size()) {
        int pos = v[i].f;
        while (v[i].f == pos) {
            cur += v[i++].s;
        }
        mx = max(mx, cur);
    }
    return res + mx;
}

int main() {
    fastIO();
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> L[i] >> R[i];
    }
    for (int i = 0; i < 30; i++) {
        ans[i] = calc((1 << i));
    }
    cin >> q;
    while (q--) {
        int w;
        cin >> w;
        int min_bit = 0;
        while (((w >> min_bit) & 1) == 0) {
            min_bit++;
        }
        cout << ans[min_bit] << '\n';
    }




    return 0;
}