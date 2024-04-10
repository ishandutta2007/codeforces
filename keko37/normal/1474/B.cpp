#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 30005;

int t;
bool p[MAXN];
int sol[MAXN];
vector <int> v;

void precompute () {
    for (int i = 2; i * i < MAXN; i++) {
        if (p[i]) continue;
        for (int j = i * i; j < MAXN; j += i) {
            p[j] = 1;
        }
    }
    for (int i = 2; i < MAXN; i++) {
        if (p[i] == 0) v.push_back(i);
    }
    for (int i = 0; i < MAXN; i++) sol[i] = 1e9;
    for (auto x : v) {
        for (auto y : v) {
            int d = min(min(x - 1, y - 1), abs(x - y));
            sol[d] = min(sol[d], x * y);
        }
    }
    for (int i = MAXN - 2; i >= 0; i--) sol[i] = min(sol[i], sol[i + 1]);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    precompute();
    cin >> t;
    while (t--) {
        int d; cin >> d;
        cout << sol[d] << '\n';
    }
    return 0;
}