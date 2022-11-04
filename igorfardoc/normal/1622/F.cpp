#include<bits/stdc++.h>
#define maxn 1000000
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int lp[maxn + 1];
vi pr;
ll h[maxn + 1];
mt19937 rnd(47);
uniform_int_distribution<int> rng(1, 1000000000);
int n;

ll get_random() {
    int fir = rng(rnd);
    int sec = rng(rnd);
    return ((ll)fir << 30) + sec;
}

void print_ans(vi bad={}) {
    vi ans;
    for(int i = 1; i <= n; i++) {
        bool ok = true;
        for(const auto& el : bad) {
            if(el == i) ok = false;
        }
        if(ok) ans.push_back(i);
    }
    cout << ans.size() << '\n';
    for(const auto& el : ans) {
        cout << el << ' ';
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    h[1] = 0;
    for(int i = 2; i <= maxn; i++) {
        if(lp[i] == 0) {
            lp[i] = i;
            h[i] = get_random();
            pr.push_back(i);
        }
        for(int j = 0; j < pr.size() && pr[j] <= lp[i] && pr[j] * i <= maxn; j++) {
            lp[pr[j] * i] = pr[j];
            h[pr[j] * i] = h[pr[j]] ^ h[i];
        }
    }
    cin >> n;
    ll fact[n + 1];
    fact[0] = 0;
    ll all = 0;
    map<ll, int> where;
    for(int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] ^ h[i];
        all ^= fact[i];
        where[fact[i]] = i;
    }
    if(all == 0) {
        print_ans();
        return 0;
    }
    auto it = where.find(all);
    if(it != where.end()) {
        print_ans({it->second});
        return 0;
    }
    for(int i = 2; i <= n; i++) {
        ll need = all ^ fact[i];
        auto it = where.find(need);
        if(it != where.end()) {
            print_ans({i, it->second});
            return 0;
        }
    }
    print_ans({2, n, (n - 1) / 2});
}