#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

int n, k;
map <int, int> mp;

void ask (int x) {
    cout << "? ";
    for (int i = 1; i <= k + 1; i++) {
        if (i != x) cout << i << " ";
    }
    cout << endl;
    int pos, val;
    cin >> pos >> val;
    mp[val]++;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= k + 1; i++) ask(i);
    auto it = mp.begin(); it++;
    cout << "! " << (it -> second) << endl;
    return 0;
}