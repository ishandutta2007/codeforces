#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
const int mod = 1000000007;

int bin_pow(int a, int b) {
    if(b == 0) {
        return 1;
    }
    int res = bin_pow(a, b >> 1);
    res = ((ll)res * res) % mod;
    if(b & 1) {
        res = ((ll)res * a) % mod;
    }
    return res;
}
int bin_pow1(int a, int b) {
    int res = 1;
    int it = 0;
    int now = a;
    while((1 << it) <= b) {
        if((b >> it) & 1) {
            res = ((ll)res * now) % mod;
        }
        ++it;
        now = ((ll)now * now) % mod;
    }
    return res;
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--) {
        int n, p;
        cin >> n >> p;
        vi a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if(p == 1) {
            if(n % 2 == 1) {
                cout << 1 << '\n';
            } else {
                cout << 0 << '\n';
            }
            continue;
        }
        sort(a.begin(), a.end());
        ll s = 0;
        bool minus = false;
        int s1 = 0;
        int now = 0;
        int am = 0;
        for(int i = n - 1; i >= 0; i--) {
            //cout << s << ' ' << s1 << ' ' << minus << endl;
            int here = now;
            if(i == n - 1 || a[i] != a[i + 1]) {
                here = bin_pow1(p, a[i]);
                now = here;
            }
            if(minus) {
                s1 = (s1 - here + mod) % mod;
                continue;
            }
            if(s == 0) {
                s1 = here;
                s = 1;
            } else {
                s -= 1;
                s1 = (s1 - here + mod) % mod;
            }
            if(i != 0 && s != 0) {
                for(int j = 0; j < a[i] - a[i - 1]; j++) {
                    if(s > n) {
                        minus = true;
                        break;
                    }
                    s *= p;
                    if(s > n) {
                        minus = true;
                        break;
                    }
                }
            }
        }
        cout << s1 << '\n';

    }
}