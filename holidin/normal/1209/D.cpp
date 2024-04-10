#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
const int N = 2e6 + 1;

vector <int> v[N];
bool use[N], usec[N];
set <int> s, mn;
int x[N], y[N];

void tr(int x) {
    use[x] = 1;
    for (int i = 0; i < v[x].size(); ++i) {
        mn.erase(v[x][i]);
        s.insert(v[x][i]);
    }
}

int main() {
    int i, j, k, n;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> k >> n;
    for (i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i];
        v[x[i]].push_back(i);
        v[y[i]].push_back(i);
        mn.insert(i);
    }
    int ans = 0;
    while (s.size() + mn.size() > 0) {
        int get;
        if (s.size() != 0) {
            get = *s.begin();
            s.erase(s.begin());
        } else {
            get = *mn.begin();
            mn.erase(mn.begin());
        }
        if (usec[get] || (use[x[get]] && use[y[get]])) {
                usec[get] = 1;
            continue;
        }
        if (!use[x[get]])
            tr(x[get]);
        if (!use[y[get]])
            tr(y[get]);
        usec[get] = 1;
        ++ans;
    }
    cout << n - ans;
}