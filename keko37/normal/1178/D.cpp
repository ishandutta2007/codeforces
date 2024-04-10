#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 1005;

int n, cnt;
vector <int> v[MAXN];
vector < pair <int, int> > p;

bool prost (int x) {
    for (int i=2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

void dodaj (int x, int y) {
    v[x].push_back(y);
    v[y].push_back(x);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    dodaj(1, n);
    for (int i=1; i<n; i++) {
        dodaj(i, i+1);
    }
    cnt = n;
    if (n % 4 == 2) {
        p.push_back({1, n/2 + 1});
        for (int i=2; i <= n/2; i += 4) {
            p.push_back({i, i + 2});
            p.push_back({i + 1, i + 3});
        }
        for (int i=n/2+2; i <= n; i += 4) {
            p.push_back({i, i + 2});
            p.push_back({i + 1, i + 3});
        }
    } else {
        for (int i=1; i+3<=n; i+=4) {
            p.push_back({i, i + 2});
            p.push_back({i + 1, i + 3});
        }
        if (n % 4 == 3) p.push_back({n, n-2});
    }
    int curr = 0;
    while (!prost(cnt)) {
        cnt++;
        dodaj(p[curr].first, p[curr].second);
        curr++;
    }
    cout << cnt << endl;
    for (int i=1; i<=n; i++) {
        for (auto sus : v[i]) {
            if (i < sus) cout << i << " " << sus << '\n';
        }
    }
    return 0;
}