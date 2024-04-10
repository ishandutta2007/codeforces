#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 100;

int t, n;
map <int, int> mp;

void precompute () {
    int pot = 4, flg = 1;
    while (pot < 1e9) {
        mp[pot] = flg;
        pot *= 2;
        flg = !flg;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    precompute();
    cin >> t;
    while (t--) {
        cin >> n;
        if (n <= 3) {
            cout << "Bob\n";
        } else if (mp.find(n) != mp.end()) {
            if (mp[n]) cout << "Alice\n"; else cout << "Bob\n";
        } else {
            if (n % 2 == 0) cout << "Alice\n"; else cout << "Bob\n";
        }
    }
    return 0;
}