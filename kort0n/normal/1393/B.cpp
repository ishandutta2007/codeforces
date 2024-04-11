#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const long long INF = 1e18;
//const ll mod = 1000000007;
ll two, four, six, eight;
ll num[105000];
void add(ll x) {
    num[x]++;
    if(num[x] == 2) two++;
    if(num[x] == 4) {
        two--;
        four++;
    }
    if(num[x] == 6) {
        four--;
        six++;
    }
    if(num[x] == 8) {
        six--;
        eight++;
    }
}

void del(ll x) {
    num[x]--;
    if(num[x] == 1) {
        two--;
    }
    if(num[x] == 3) {
        two++;
        four--;
    }
    if(num[x] == 5) {
        four++;
        six--;
    }
    if(num[x] == 7) {
        six++;
        eight--;
    }
}

void f() {
    //cout << two << " " << four << " " << six << " " << eight << endl;
    string ans = "NO";
    if(eight >= 1) ans = "YES";
    if(six >= 1 and (six >= 2 or four >= 1 or two >= 1)) ans = "YES";
    if(four >= 1 and (four >= 2 or two >= 2)) ans = "YES";
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        add(a);
    }
    ll Q;
    cin >> Q;
    while(Q--) {
        char c;
        ll x;
        cin >> c >> x;
        if(c == '+') add(x);
        else del(x);
        f();
    }
    return 0;
}