#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define ick cout<<"ickbmi32.9\n"
using namespace std;
vector<int> conn[1000005];
bool vi[1000005];
void init(int k) {
    for(int i = 0; i <= k; i++) {
        vi[i] = false;
        conn[i].clear();
    }
}
bool isprime(int k) {
    for(int i = 2; i <= sqrt(k); i++) if(k % i == 0) return false; 
    return true;
}
int bm(int a, int b, int mod) {
    if(b == 0) return 1; 
    int t = bm(a, b / 2, mod); 
    t = t * t % mod; 
    return (b % 2 == 1 ? t * a % mod : t);
}
int inv(int a, int mod) {return bm(a, mod - 2, mod);}
int arr[150005];
int n;
vector<int> bad;

bool check(int l, int r) {
    r = min(r, n - 1);
    l = max(l, 1LL);
    for(int i = l; i <= r; i++) {
        if(i % 2 == 0) {
            if(arr[i] <= arr[i + 1]) {
                return false;
            }
        }
        else {
            if(arr[i] >= arr[i + 1]) return false;
        }
    }
    for(auto i: bad) {
        if(i % 2 == 0) {
            if(arr[i] <= arr[i + 1]) {
                return false;
            }
        }
        else {
            if(arr[i] >= arr[i + 1]) return false;
        }
    }
    return true;
}
map<pair<int, int>, bool> tried;
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    if(n % 2 == 1) arr[n + 1] = 9999999;
    else arr[n + 1] = -1;
    for(int i = 1; i < n; i++) {
        if(i % 2 == 0) {
            if(arr[i] <= arr[i + 1]) {
                bad.pb(i);
            }
        }
        else {
            if(arr[i] >= arr[i + 1]) bad.pb(i);
        }
    }
    //cerr << bad.size() << '\n';
    if(bad.size() > 4) {
        cout << "0\n";
        return;
    }
    else {
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            for(auto x: bad) {
                int a = i, b = x;
                if(a > b) swap(a, b);
                if(a != b && !tried[mp(a, b)]) {
                    swap(arr[a], arr[b]);
                    if(check(a - 1, a) && check(b - 1, b)) ans++;
                    swap(arr[a], arr[b]);
                    tried[mp(a, b)] =true;
                }
                //err << a << ' ' << b << ' ' << ans << '\n';
                b= x + 1;
                a = i;
                if(a > b) swap(a, b);
                if(a != b && !tried[mp(a, b)]) {
                    swap(arr[a], arr[b]);
                    if(check(a - 1, a) && check(b - 1, b)) ans++;
                    swap(arr[a], arr[b]);
                    tried[mp(a, b)] = true;
                }
                //cerr << a << ' ' << b << ' ' << ans << '\n';
            }
        }
        cout << ans << '\n';
    }
    return;
    if(bad.size() == 4) {
        if(bad[1] != bad[0] + 1 || bad[3] != bad[2] + 1) {
            cout << "0\n";
            return;
        }
        swap(arr[bad[1]], arr[bad[3]]);
        if(check(1, n)) cout << "1\n";
        else cout << "0\n";
        return;
    }
    if(bad.size() == 3) {
        int ans = 0;
        if(bad[0] == bad[1] - 1) {
            int a = bad[0], b = bad[1], c = bad[2], d = bad[2] + 1;
            swap(arr[a], arr[c]);
            if(check(1, n)) ans++;
            swap(arr[a], arr[c]);
            if(d <= n) {swap(arr[a], arr[d]);
            if(check(1, n)) ans++;
            swap(arr[a], arr[d]);}
            swap(arr[b], arr[c]);
            if(check(1, n)) ans++;
            swap(arr[b], arr[c]);
            if(d <= n) {swap(arr[b], arr[d]);
            if(check(1, n)) ans++;
            swap(arr[b], arr[d]);}
        }
        else if(bad[1] == bad[2] - 1) {
            int a = bad[0], b = bad[0] + 1, c = bad[1], d = bad[2];
            swap(arr[a], arr[c]);
            if(check(1, n)) ans++;
            swap(arr[a], arr[c]);
            if(d <= n) {swap(arr[a], arr[d]);
            if(check(1, n)) ans++;
            swap(arr[a], arr[d]);}
            swap(arr[b], arr[c]);
            if(check(1, n)) ans++;
            swap(arr[b], arr[c]);
            if(d <= n) {swap(arr[b], arr[d]);
            if(check(1, n)) ans++;
            swap(arr[b], arr[d]);}
        }
        else {
            cout << "0\n";
            return;
        }
        cout << ans << '\n';
        return;
    }
    if(bad.size() == 2) {
        if(bad[0] == bad[1] - 1) {
            int ans = 0;
            for(int i = 1; i <= n; i++) {
                int a = bad[0], b = i;
                if(a != b) {
                    swap(arr[a], arr[b]);
                    if(check(a - 1, a) && check(b - 1, b)) ans++;
                    swap(arr[a], arr[b]);
                }
                a = bad[1];
                if(a != b && b != bad[0]) {
                    swap(arr[a], arr[b]);
                    if(check(a - 1, a) && check(b - 1, b)) ans++;
                    swap(arr[a], arr[b]);
                }
            }
            cout << ans << '\n';
            return;
        }
        else {
            int ans = 0;
            int a = bad[0], b = bad[0] + 1, c = bad[1], d = bad[1] + 1;
            swap(arr[a], arr[c]);
            if(check(1, n)) ans++;
            swap(arr[a], arr[c]);
            if(d <= n) {swap(arr[a], arr[d]);
            if(check(1, n)) ans++;
            swap(arr[a], arr[d]);}
            swap(arr[b], arr[c]);
            if(check(1, n)) ans++;
            swap(arr[b], arr[c]);
            if(d <= n) {swap(arr[b], arr[d]);
            if(check(1, n)) ans++;
            swap(arr[b], arr[d]);}
            cout << ans << '\n';
            return;
        }
    }
    else if(bad.size() == 1) {
        int ans = 0;
            for(int i = 1; i <= n; i++) {
                int a = bad[0], b = i;
                if(a != b) {
                    swap(arr[a], arr[b]);
                    if(check(a - 1, a) && check(b - 1, b)) ans++;
                    swap(arr[a], arr[b]);
                }
                //cerr << i << ' ' << ans << '\n';
                a = bad[0] + 1;
                if(a != b && b != bad[0]) {
                    swap(arr[a], arr[b]);
                    if(check(a - 1, a) && check(b - 1, b)) ans++;
                    swap(arr[a], arr[b]);
                }
                //cerr << i << ' ' << ans << '\n';
            }
            cout << ans << '\n';
            return;
    }
    assert(bad.size() != 0);
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t = 1;  
    //cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    while(t--) solve();
    return 0;
}