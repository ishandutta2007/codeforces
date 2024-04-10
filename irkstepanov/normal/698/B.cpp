#include <bits/stdc++.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pll;

vector<int> p;
vector<int> color;
vector<int> bad;
vector<int> self;

void dfs(int v)
{
    color[v] = 1;
    if (color[p[v]] == 0) {
        dfs(p[v]);
    } else if (color[p[v]] == 1) {
        if (p[v] == v) {
            self.pb(v);
        }
        bad.pb(v);
    }
    color[v] = 2;
}

int main()
{

    //ifstream cin("input.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    p.resize(n);
    color.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
    }

    for (int i = 0; i < n; ++i) {
        if (color[i] == 0) {
            dfs(i);
        }
    }

    if (!self.empty()) {
        int root = self[0];
        cout << sz(bad) - 1 << "\n";
        for (int x : bad) {
            p[x] = root;
        }
        for (int i = 0; i < n; ++i) {
            cout << p[i] + 1 << " ";
        }
        cout << "\n";
    } else {
        cout << sz(bad) << "\n";
        int root = bad[0];
        for (int x : bad) {
            p[x] = root;
        }
        for (int i = 0; i < n; ++i) {
            cout << p[i] + 1 << " ";
        }
        cout << "\n";
    }

}