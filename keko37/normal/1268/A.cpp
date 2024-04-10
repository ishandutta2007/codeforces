#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 200005;

int n, k;
string s, t;

bool moze () {
    for (int i = 0; i < n; i++) {
        if (t[i % k] < s[i]) return 0;
        if (t[i % k] > s[i]) return 1;
    }
    return 1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> s;
    t = s.substr(0, k);
    if (!moze()) {
        for (int i = k-1; i >= 0; i--) {
            t[i]++;
            if (t[i] <= '9') break;
            t[i] = '0';
        }
    }
    cout << n << endl;
    for (int i = 0; i < n; i++) cout << t[i % k];
    return 0;
}