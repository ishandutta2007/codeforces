#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 1e7 + 5;

int t, n;
int p[MAXN];
vector <int> v, d1, d2;

void sito () {
    for (int i = 2; i * i < MAXN; i++) {
        if (p[i] != 0) continue;
        for (int j = i * i; j < MAXN; j += i) {
            p[j] = i;
        }
    }
    for (int i = 2; i <= 1e7; i++) {
        if (p[i] == 0) p[i] = i;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    sito();
    cin >> t;
    while (t--) {
        cin >> n;
        v.clear();
        while (n > 1) {
            int r = p[n];
            while (n % r == 0) n /= r;
            v.push_back(r);
        }
        if (v.size() < 2) {
            d1.push_back(-1);
            d2.push_back(-1);
        } else {
            d1.push_back(v[0]);
            int res = 1;
            for (int i = 1; i < v.size(); i++) res *= v[i];
            d2.push_back(res);
        }
    }
    for (auto x : d1) cout << x << " "; cout << '\n';
    for (auto x : d2) cout << x << " "; cout << '\n';
    return 0;
}