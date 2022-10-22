#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <string>
#include <utility>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;

void mod_sum(ll& sum, ll summand) {
    sum += summand;
    sum = sum % MOD;
}

struct Node {
    Node *l = 0, *r = 0;
    ll lo, hi, madd = 0, val = -1;
    Node(ll lo, ll hi):lo(lo),hi(hi){} // Large llerval of in f
    Node(vector<ll>& v, ll lo, ll hi) : lo(lo), hi(hi) {
        if (lo + 1 < hi) {
            ll mid = lo + (hi - lo)/2;
            l = new Node(v, lo, mid); r = new Node(v, mid, hi);
            val = max(l->val, r->val);
        }
        else val = v[lo];
    }
    ll query(ll L, ll R) {
        if (R <= lo || hi <= L) return -1;
        if (L <= lo && hi <= R) return val;
        push();
        return max(l->query(L, R), r->query(L, R));
    }
    void add(ll L, ll R, ll x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            mod_sum(madd, x);
            mod_sum(val, x);
        }
        else {
            push(), l->add(L, R, x), r->add(L, R, x);
            val = max(l->val, r->val);
        }
    }
    void push() {
        if (!l) {
            ll mid = lo + (hi - lo)/2;
            l = new Node(lo, mid); r = new Node(mid, hi);
        }
        if (madd) {
            l->add(lo, hi, madd), r->add(lo, hi, madd), madd = 0;
        }
    }
};


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    ll n;
    cin >> n;
    vector<ll> x(n + 1);
    vector<ll> y(n);
    vector<ll> s(n);
    for (ll i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> s[i];
    }

    x[n] = x[n - 1] + 1;

    ll sum = x[0];
    for (ll i = 0; i < n; i++) {
        if (s[i] == 0) mod_sum(sum, x[i + 1] - x[i]); 
    }

    // int k = n - 1;
    // while (k && (s[k] == 0)) k--;
    // for (int i = 0; i <= k; i++) s[i] = 1;

    Node *seg_tree = new Node(s, 0, n);

    vector<ll> weights(n, 0);
    vector<ll> prev_ind(n, 0);

    for (ll i = 0; i < n; i++) {
        if (y[i] < x[0]) {
            prev_ind[i] = 0;
        } else {
            ll l = 0, r = n - 1;
            while (r - l > 1) {
                ll mid = (l + r) / 2;
                if (y[i] < x[mid]) r = mid;
                else l = mid;
            }
            prev_ind[i] = r;
        }

        weights[i] = x[i + 1] - x[i] + x[prev_ind[i]] - y[i];
    }

    for (ll i = n - 1; i >= 1; i--) {
        ll val = seg_tree->query(i, i + 1);
        seg_tree->add(prev_ind[i], i, val);
    }

    for (ll i = 0; i < n; i++) {
        int x = seg_tree->query(i, i + 1);
        sum = (sum + weights[i] * x) % MOD;
    }

    cout << sum << "\n";


}