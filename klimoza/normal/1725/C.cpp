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

const int MAXN = 3 * 1e5 + 10;
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

int n, m, diam_pairs;
ll d[MAXN], sum;


ll fac[MAXN], rev[MAXN];
 
ll add(ll a, ll b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
    return a;
}
 
ll mul(ll a, ll b) {
    return a * b % MOD;
}
 
ll bp(ll a, ll k) {
    ll res = 1;
    while (k) {
        if (k & 1)
            res = mul(res, a);
        a = mul(a, a);
        k >>= 1;
    }
    return res;
}
 
void build() {
    fac[0] = 1;
    for (ll i = 1; i < MAXN; i++)
        fac[i] = mul(fac[i - 1], i);
    rev[MAXN - 1] = bp(fac[MAXN - 1], MOD - 2);
    for (ll i = MAXN - 2; i >= 0; i--)
        rev[i] = mul(rev[i + 1], i + 1);
}
 
ll cnk(ll n, ll k) {
    if (k > n) return 0;
    return mul(fac[n], mul(rev[n - k], rev[k]));        
}

ll ank(ll n, ll k) {
    if (k > n) return 0;
    return mul(fac[n],rev[n - k]);   
}


ll calc() {
    ll others = n - diam_pairs * 2;
    ll ans = 0;
    for (int i = 0; i <= min(diam_pairs, m); i++) {
        ll same_pairs = cnk(diam_pairs, i);
        ll colorings = ank(m, i);
        ll left_colors = m - i;
        if (left_colors == 0 && i * 2 < n) {
            continue;
        }
        ll left_pairs = diam_pairs - i;
        ll local_add = mul(same_pairs, colorings);
        local_add = mul(local_add, mul(bp(left_colors, left_pairs + others), bp(left_colors - 1, left_pairs)));
        ans = add(ans, local_add);
    }
    return ans;
}

int main() {
    fastIO();
    build();
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> d[i];
        sum += d[i];
    }
    int j = 0;
    ll cur_dist = 0;
    for (int i = 0; i < n; i++) {
        while (cur_dist * 2 < sum) {
            cur_dist += d[j++];
            if (j == n)
                j = 0;
        }
        if (cur_dist * 2 == sum)
            diam_pairs++;
        cur_dist -= d[i];
    }
    diam_pairs /= 2;
    cout << calc() << '\n';

   


    return 0;
}