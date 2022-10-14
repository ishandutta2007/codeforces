#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

int t, n;
vector <llint> v;

void precompute () {
    for (llint a = 3; 1; a += 2) {
        llint c = (a * a - 1) / 2 + 1;
        if (c > 1e9) break;
        v.push_back(c);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    precompute();
    cin >> t;
    while (t--) {
        cin >> n;
        int ind = upper_bound(v.begin(), v.end(), n) - v.begin();
        cout << ind << '\n';
    }
    return 0;
}