#include<bits/stdc++.h>
#define maxn 1000000
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;


ll f[maxn];
int n, m;

void add(int r, ll val) {
    for(; r < n; r = r | (r + 1)) {
        f[r] += val;
    }
}

ll get(int r) {
    ll ans = 0;
    for(; r >= 0; r = (r & (r + 1)) - 1) {
        ans += f[r];
    }
    return ans;
}

void add(int l, int r, ll val) {
    add(l, val);
    add(r + 1, -val);
}
set<array<int, 3>> s;

int get_col(int x) {
    auto it = s.lower_bound((array<int, 3>){x + 1, -1, -1});
    --it;
    return (*it)[2];
}

array<int, 3> get_otr(int x) {
    auto it = s.lower_bound((array<int, 3>){x + 1, -1, -1});
    --it;
    return *it;
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
    cin >> n >> m;
    vector<ll> adding(n, 0);
    s.insert({0, n - 1, 0});
    for(int i = 0; i < m; i++) {
        string s1;
        cin >> s1;
        if(s1[0] == 'C') {
            int l, r, c;
            cin >> l >> r >> c;
            --l;
            --r;
            --c;
            auto p = get_otr(l);
            s.erase(p);
            if(p[0] < l) {
                s.insert({p[0], l - 1, p[2]});
            }
            s.insert({l, p[1], p[2]});
            p = get_otr(r);
            s.erase(p);
            if(p[1] > r) {
                s.insert({r + 1, p[1], p[2]});
            }
            s.insert({p[0], r, p[2]});
            int now = l;
            while(now <= r) {
                auto p = get_otr(now);
                s.erase(p);
                add(p[0], p[1], adding[p[2]] - adding[c]);
                now = p[1] + 1;
            }
            int l1 = l;
            int r1 = r;
            if(l - 1 >= 0) {
                auto p = get_otr(l - 1);
                if(p[2] == c) {
                    s.erase(p);
                    l1 = p[0];
                }
            }
            if(r + 1 < n) {
                auto p = get_otr(r + 1);
                if(p[2] == c) {
                    s.erase(p);
                    r1 = p[1];
                }
            }
            s.insert({l1, r1, c});

        } else if(s1[0] == 'A') {
            int c, x;
            cin >> c >> x;
            --c;
            adding[c] += x;
        } else {
            int x;
            cin >> x;
            --x;
            cout << adding[get_col(x)] + get(x) << '\n';
        }
    }
}