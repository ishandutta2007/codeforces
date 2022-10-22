#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll __lcm(ll a, ll b) {
    return a * b / __gcd(a, b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> perm(n);
        for(int i = 0; i < n; i++) {
            cin >> perm[i];
            perm[i]--;
        }
        ll ans = 1;
        for(int i = 0; i < n; i++) {
            if(perm[i] == -1) continue;
            string s2 = "";
            int x = i;
            while(x != -1) {
                s2 += s[x];
                int prevx = x;
                x = perm[x];
                perm[prevx] = -1;
            }
            s2.pop_back();
            int g = s2.size();
            for(int j = 1; j < n; j++) {
                bool ok = true;
                for(int k = 0; k < s2.size() && ok; k++) {
                    if(s2[k] != s2[(j+k)%s2.size()]) ok = false;
                }
                if(ok) {
                    g = j;
                    break;
                }
            }
            ans = __lcm(ans, g);
        }
        cout << ans << '\n';
    }
}