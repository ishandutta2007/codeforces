#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vi p;


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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int m, n;
    cin >> m >> n;
    vi a(m), b(n);
    for(int i = 0; i < m; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<array<int, 3>> e;
    ll sum = 0;
    for(int i = 0; i < m; i++) {
        int s;
        cin >> s;
        for(int j = 0; j < s; j++) {
            int el;
            cin >> el;
            --el;
            e.push_back({a[i] + b[el], el, n + i});
            sum += a[i] + b[el];
        }
    }
    p.resize(n + m);
    for(int i = 0; i < n + m; i++) {
        p[i] = i;
    }
    sort(e.begin(), e.end());
    for(int i = (int)e.size() - 1; i >= 0; i--) {
        int v = e[i][1];
        int u = e[i][2];
        if(eq(v, u)) continue;
        join(v, u);
        sum -= e[i][0];
    }
    cout << sum;
}