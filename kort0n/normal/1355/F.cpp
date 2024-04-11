#include <bits/stdc++.h>
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
vector<ll> p;
ll LOCAL = 0;
ll LocalX = 1;
vector<ll> query;
vector<ll> Div;
ll ret;
void ask(ll Q) {
    cout << "? " << Q << endl;
    if(LOCAL == 0) {
        cin >> ret;
    } else {
        ret = __gcd(Q, LocalX);
        cerr << Q << " " << LocalX << " " << ret << endl;
    }
}

void ANS(ll ans) {
    cout << "! " << ans << endl;
    if(LOCAL) {
        ll trueans = 0;
        for(ll j = 1; j * j <= LocalX; j++) {
            if(LocalX % j != 0) continue;
            trueans++;
            if(j * j != LocalX) trueans++;
        }
        bool ok = false;
        if(abs(trueans - ans) <= 7) ok = true;
        if(ans <= trueans * 2 and 2 * ans >= trueans) ok = true;
        cerr << "Myans: " << ans << endl;
        cerr << "trueans: " << trueans << endl;
        assert(ok);
    }
}

ll maximize(ll x) {
    ll ret = 1;
    while(true) {
        ll nxt = ret * x;
        if(nxt * nxt > 1e9) break;
        ret = nxt;
    }
    return ret;
}

void solve() {
    Div.clear();
    if(LOCAL) {
        LocalX = rand();
        cerr << "X is " << LocalX << endl;
        ll copy = LocalX;
        for(ll i = 2; i * i <= copy; i++) {
            if(copy % i != 0) continue;
            ll num = 0;
            while(copy % i == 0) {
                copy /= i;
                num++;
            }
            cerr << i << " " << num << endl;
        }
        if(copy != 1) {
            cerr << copy << " " << 1 << endl;
        }
    }
    for(int i = 0; i < 19; i++) {
        ask(query[i]);
        for(auto val : p) {
            //cerr << ret << " " << val << " " << ret % val << endl;
            if(ret % val == 0) {
                //cerr << "ok: " << val << endl;
                Div.push_back(val);
            }
        }
    }
    //cerr << Div.size() << endl;
    if(Div.empty()) {
        ANS(8);
        return;
    }
    ll q = query.back() * maximize(Div[0]);
    //cerr << Div[0] << " " << maximize(Div[0]) << endl;
    ask(q);
    for(auto val : p) {
        if(val == Div[0]) continue;
        if(ret % val == 0) Div.push_back(val);
    }
    ll ans = 1;
    ll tmp = 0;
    while(ret % Div[0] == 0) {
        ret /= Div[0];
        tmp++;
    }
    //cerr << "--------" << Div[0] << " " << tmp << endl;
    ans *= tmp + 1;
    vector<ll> a = {1, 1};
    for(int i = 1; i < Div.size(); i++) {
        ll idx = (i - 1) / 4;
        a[idx] *= maximize(Div[i]);
    }
    for(int i = 0; i < 2; i++) {
        ask(a[i]);
        for(auto val : Div) {
            ll tmp = 0;
            while(ret % val == 0) {
                ret /= val;
                tmp++;
            }
            //if(tmp) cerr << "--------" << val << " " << tmp << endl;
            ans *= tmp + 1;
        }
    }
    ANS(ans * 2);
}

int main() {
    for(ll i = 2; i <= 800; i++) {
        bool ok = true;
        for(ll j = 2; j * j <= i; j++) {
            if(i % j == 0) ok = false;
        }
        if(ok) p.push_back(i);
    }
    for(auto val : p) {
        if(query.empty() or INF / query.back() <= val) {
            query.push_back(val);
        } else {
            query.back() *= val;
        }
    }
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}