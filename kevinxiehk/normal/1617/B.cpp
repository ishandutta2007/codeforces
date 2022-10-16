#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define ick cout<<"ickbmi32.9\n"
using namespace std;
unordered_map<int, int> vi;
int bm(int a, int b, int mod) {
    if(b == 0) return 1; 
    int t = bm(a, b / 2, mod); 
    t = t * t % mod; 
    return (b % 2 == 1 ? t * a % mod : t);
}
int inv(int a, int mod) {return bm(a, mod - 2, mod);}
vector<int> MILLER = {2, 3, 5, 7};
bool millerTest(int d, int n, int a) {
    int x = bm(a, d, n);
    if (x == 1  || x == n - 1) return true;
    while (d != n - 1) {
        x = x * x % n;
        d *= 2;
        if (x == 1) return false;
        if (x == n - 1) return true;
    }
    return false;
}
bool isprime(int n) {
    if(vi[n] == 1) return true;
    if(vi[n] == -1) return false;
    if (n <= 1 || n == 4)  return false;
    if (n <= 3) return true;
    int d = n - 1;
    while (d % 2 == 0) d /= 2;
    for(auto a: MILLER) {
        if(a >= n) {vi[n] = 1; return true;}
        if (!millerTest(d, n, a)) {vi[n] = -1; return false;}
    }
    vi[n] = 1;
    return true;
}
void solve() {
    int n;
    cin >> n;
    if(n % 2 == 0) {
        cout << n - 3 << " 2 1\n";
        return;
    }
    n--;
    for(int i = 3; true; i += 2) {
        int x = i, y = n - i;
        if(isprime(x) && isprime(y)) {
            cout << x << ' ' << y << " 1\n";
            return;
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}