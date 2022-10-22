#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<ll> divi;

int ask(int a, int b, int c) {
    return divi[a] * divi[b] * divi[c];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    divi.resize(100001);
    for(int i = 1; i <= 100000; i++) {
        for(int j = i; j <= 100000; j += i) {
            divi[j]++;
        }
    }
    int t;
    cin >> t;
    while(t--) {
        vector<int> v(3);
        vector<vector<int>> al;
        for(int i = 0; i < 3; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        do {
            al.push_back(v);
        } while(next_permutation(v.begin(), v.end()));
        int g = al.size();
        ll ans = 0;
        for(int i = 0; i < (1 << g); i++) {
            int k = 0;
            int a, b, c;
            a = b = c = -1;
            for(int j = 0; j < g; j++) {
                if(i & (1 << j)) {
                    k++;
                    if(a == -1) {
                        a = al[j][0];
                        b = al[j][1];
                        c = al[j][2];
                    }
                    a = __gcd(a, al[j][0]);
                    b = __gcd(b, al[j][1]);
                    c = __gcd(c, al[j][2]);
                }
            }
            if(k) {
                if(k%2) ans += ask(a, b, c);
                else ans -= ask(a, b, c);
                if(k%2) ans += 3 * ask(__gcd(a, b), 1, c);
                else ans -= 3 * ask(__gcd(a, b), 1, c);
                int x = __gcd(a, __gcd(b, c));
                if(k%2) ans += 2 * ask(x, 1, 1);
                else ans -= 2 * ask(x, 1, 1);
            }
        }
        cout << ans/6 << '\n';
        vector<vector<int>>().swap(al);
        vector<int>().swap(v);
    }
}