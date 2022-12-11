#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int nmax = 200500;

vector<int> to;
vector<vector<int> > rev;
vector<int> p;

int dfs(int v)
{
    int ans = 1;
    for (int to : rev[v]) {
        if (p[to] == -1) {
            p[to] = v;
            ans += dfs(to);
        }
    }
    return ans;
}

int mod = 1e9 + 7;

void add(int& a, int b)
{
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

void mul(int& a, int b)
{
    ll c = ll(a) * ll(b);
    a = c % mod;
}

void sub(int& a, int b)
{
    a -= b;
    if (a < 0) {
        a += mod;
    }
}

int main()
{

    //ifstream cin("input.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    to.resize(n);
    rev.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> to[i];
        --to[i];
        rev[to[i]].pb(i);
    }

    p = vector<int>(n, -1);
    vector<pii> v;
    for (int i = 0; i < n; ++i) {
        if (p[i] != -1) {
            continue;
        }
        int curr = i;
        p[curr] = i;
        while (p[to[curr]] == -1) {
            p[to[curr]] = curr;
            curr = to[curr];
        }
        int cycle_size = 1;
        int start = curr;
        int finish = to[curr];
        while (curr != finish) {
            curr = p[curr];
            ++cycle_size;
        }
        while (p[curr] != -1) {
            int pr = p[curr];
            p[curr] = -1;
            curr = pr;
        }
        p[finish] = start;
        int comp = 0;
        curr = start;
        while (true) {
            comp += dfs(curr);
            if (curr == finish) {
                break;
            }
            curr = p[curr];
        }
        v.pb({comp, cycle_size});
    }

    vector<int> degs(nmax);
    degs[0] = 1;
    for (int i = 1; i < nmax; ++i) {
        degs[i] = degs[i - 1];
        add(degs[i], degs[i - 1]);
    }

    int ans = 1;
    for (pii& p : v) {
        int a = p.first, b = p.second;
        int val = degs[a];
        sub(val, degs[a - b + 1]);
        mul(ans, val);
    }
    cout << ans << "\n";

}