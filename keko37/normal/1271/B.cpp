#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 205;

int n;
string s;
bool p[MAXN], t[MAXN];
vector <int> v;

bool moze (int c) {
    v.clear();
    for (int i = 0; i < n; i++) {
        t[i] = p[i];
    }
    for (int i = 0; i < n - 1; i++) {
        if (t[i] != c) {
            t[i] = !t[i];
            t[i + 1] = !t[i + 1];
            v.push_back(i + 1);
        }
    }
    if (t[n - 1] == c) return 1; return 0;
}

void ispis () {
    cout << v.size() << endl;
    for (auto x : v) cout << x << " "; cout << endl;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        p[i] = (s[i] == 'B');
    }
    if (moze(0) || moze(1)) ispis(); else cout << -1;
    return 0;
}