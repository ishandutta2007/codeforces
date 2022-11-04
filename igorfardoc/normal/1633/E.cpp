#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vi p;
int n, m;
vector<array<int, 3>> e;
vector<int> res1;
vector<pair<ll, int>> res2;

int get_par(int a) {
    if(p[a] == a) return a;
    int par = get_par(p[a]);
    p[a] = par;
    return par;
}

bool eq(int a, int b) {
    return get_par(a) == get_par(b);
}

void join(int a, int b) {
    a = get_par(a);
    b = get_par(b);
    if(a == b) return;
    p[a] = b;
}

void clear_p() {
    p.assign(n, 0);
    for(int i = 0; i < n; i++) {
        p[i] = i;
    }
}

void calc(int x) {
    vector<array<int, 4>> enew;
    for(int i = 0; i < m; i++) {
        enew.push_back({abs(x - e[i][2]), e[i][0], e[i][1], x > e[i][2]});
    }
    sort(enew.begin(), enew.end());
    clear_p();
    ll ans = 0;
    int am = 0;
    for(int i = 0; i < m; i++) {
        int v = enew[i][1];
        int u = enew[i][2];
        int w = enew[i][0];
        int val = enew[i][3];
        if(eq(v, u)) continue;
        join(v, u);
        ans += w;
        am += val;
    }
    res1.push_back(x);
    res2.push_back({ans, am});
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
    e.resize(m);
    for(int i = 0; i < m; i++) {
        cin >> e[i][0] >> e[i][1] >> e[i][2];
        --e[i][0];
        --e[i][1];
    }
    set<int> need;
    need.insert(200000000);
    for(int i = 0; i < m; i++) {
        for(int j = i; j < m; j++) {
            int sum = e[i][2] + e[j][2];
            if(sum % 2 == 0) {
                need.insert(sum / 2);
                need.insert(max(0, sum / 2 - 1));
            } else {
                need.insert(sum / 2);
            }
        }
    }
    for(const auto& el : need) {
        calc(el);
    }
    int p, k, a, b, c;
    cin >> p >> k >> a >> b >> c;
    int bef = -1;
    ll result = 0;
    for(int i = 0; i < k; i++) {
        int here;
        if(i < p) {
            cin >> here;
        } else {
            here = ((ll)bef * a + b) % c;
        }
        bef = here;
        int id1 = lower_bound(res1.begin(), res1.end(), here) - res1.begin();
        ll ans = res2[id1].first;
        int small = res2[id1].second;
        int big = n - 1 - small;
        int delta = res1[id1] - here;
        ans += (ll)big * delta;
        ans -= (ll)small * delta;
        result ^= ans;
    }
    cout << result;

}