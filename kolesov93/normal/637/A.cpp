#include<bits/stdc++.h>
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
using namespace std;


int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int n;
    cin >> n;
    int mxi = 0;
    int mx = -1;
    unordered_map<int, int> v;
    while (n--) {
        int x;
        cin >> x;
        ++v[x];
        if (v[x] > mx) {
            mx = v[x];
            mxi = x;
        }
    }
    cout << mxi << '\n';

    return 0;
}