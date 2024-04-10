#include <bits/stdc++.h>
#define ll long long
#define int long long

using namespace std;

const ll MOD = 1111169;
vector<ll> num, nums;
map<int, vector<int> > numbers;

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n, x, p = 0, mp = 0, a = 0; cin >> n; x = n;
        int s = (int)(sqrt(n));
        for(int i = 2; i <= s+1; i++) {
            p = 0;
            while(!(n%i)) {
                p++;
                n /= i;
            }
            if(p > mp) {
                mp = p;
                a = i;
            }
        }
        if(mp <= 1) {
            cout << 1 << '\n' << x << '\n';
        }
        else {
            cout << mp << '\n';
            for(int i = 0; i < mp-1; i++) {
                cout << a << ' ';
                x /= a;
            }
            cout << x << '\n';
        }
    }
}