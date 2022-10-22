#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int op_count = 0; // Sanity check

vector<pair<ll, ll>> ops;

ll add(ll a, ll b) {
    ops.push_back({a+1, b+1});
    return a + b;
}

ll rox(ll a, ll b) {
    ops.push_back({-a-1, -b-1});
    return (a ^ b);
}

ll mult(ll n, ll k) { // Generates the number n * k in O(log k) things
    ll g = 1;
    ll ans = n * k;
    while(g < k) {
        add(n*g, n*g);
        g *= 2;
    }
    ll sum = 0;
    for(int i = 0; k; i++) {
        if((1LL << i) & k) {
            k -= (1LL << i);
            add(sum, n * (1LL << i));
            sum += n * (1LL << i);
        }
    }
    return ans;
}

void print_all() {
    cout << ops.size() << '\n';
    for(auto p : ops) {
        cout << abs(p.first) - 1;
        if(p.first > 0) cout << " + ";
        else cout << " ^ ";
        cout << abs(p.second) - 1;
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    ll k = 2;
    rox(n, n);
    // Idea: generate the number 2^61 (> 10^6^3)
    // Trust in the fact that there exists k with gcd(kn ^ n, n) = 1
    while(__gcd(((k * n) ^ n), n) != 1) k++;
    ll x = rox(mult(n, k), n);
    k = 2;
    while(((1LL << 61) - (x * k)) % n) {
        k++;
    }
    // Find k so that we can just keep adding n until we get 2^61
    ll BIG = add(mult(n, ((1LL << 61) - (x * k)) / n), mult(x, k));
    assert(BIG == (1LL << 61));
    // Oh I can actually generate BIG + 1 lol
    k = 2;
    while(((1LL << 61) + 1 - (x * k)) % n) {
        k++;
    }
    ll BIG2 = add(mult(n, ((1LL << 61) + 1 - (x * k)) / n), mult(x, k));
    assert(BIG2 == (1LL << 61) + 1);
    rox(BIG, BIG2);
    print_all();
}