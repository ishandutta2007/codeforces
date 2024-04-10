#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 100005;

int n, cnt;
int a[MAXN], b[MAXN], d[MAXN], sol[MAXN];
vector <int> v[MAXN];

void ispis () {
    for (int i = 0; i < n-1; i++) {
        cout << sol[i] << '\n';
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> a[i] >> b[i];
        d[a[i]]++;
        d[b[i]]++;
        v[a[i]].push_back(i);
        v[b[i]].push_back(i);
    }
    memset(sol, -1, sizeof sol);
    for (int i = 1; i <= n; i++) {
        if (d[i] >= 3) {
            for (auto e : v[i]) {
                sol[e] = cnt++;
            }
            for (int i = 0; i < n-1; i++) {
                if (sol[i] == -1) sol[i] = cnt++;
            }
            ispis();
            return 0;
        }
    }
    for (int i = 0; i < n-1; i++) sol[i] = i;
    ispis();
    return 0;
}