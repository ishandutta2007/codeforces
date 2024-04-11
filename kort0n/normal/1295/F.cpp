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

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);
const ll mod = 998244353;
ll beki(ll a, ll b){
    if(b == 0){
        return 1;
    }
    ll ans = beki(a, b / 2);
    ans = ans * ans % mod;
    if(b % 2 == 1){
        ans = ans * a % mod;
    }
    return ans;
}
ll inv(ll x) {
    return beki(x, mod - 2);
}

ll combination(ll a, ll b) {
    if((a == b) || (b == 0)){
        return 1;
    }
    if(a < b) return 0;
    b = min(b, a - b);
    ll ret = 1;
    for(ll i = 1; i <= b; i++) {
        ret *= (a + 1 - i);
        ret %= mod;
        ret *= inv(i);
        ret %= mod;
    }
    return ret;
}

ll N;
ll l[51];
ll r[51];
ll Total = 1;
ll ans = 0;
vector<ll> cmp;
ll Prev[51], Next[51];
void print(int timer) {
    return;
    cerr << "-----" << cmp[timer] << "-----" << endl;
    for(int i = 0; i < N; i++) {
        cerr << Prev[i] << " ";
    }
    cerr << endl;
}
int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> l[i] >> r[i];
        Total *= (r[i] - l[i] + 1);
        Total %= mod;
    }
    for(int i = 0; i < N / 2; i++) {
        swap(l[i], l[N-1-i]);
        swap(r[i], r[N-1-i]);
    }
    for(int i = 1; i < N; i++) {
        chmax(l[i], l[i-1]);
    }
    for(int i = N - 2; i >= 0; i--) {
        chmin(r[i], r[i+1]);
    }
    l[N] = l[N-1];
    r[N] = r[N-1];
    N++;
    for(int i = 0; i < N; i++) {
        //cerr << i << " " << l[i] << " " << r[i] << endl;
    }
    for(int i = 0; i < N; i++) {
        if(l[i] > r[i]) {
            cout << 0 << endl;
            return 0;
        }
        cmp.push_back(l[i]);
        cmp.push_back(r[i]);
    }
    sort(cmp.begin(), cmp.end());
    cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());
    for(int i = 0; i < N; i++) {
        if(i == 0 or l[i - 1] == cmp[0]) Prev[i] = 1;
    }
    //Prev[0] = 1;
    print(0);
    //ans += Prev[N-1];
    for(int timer = 1; timer < cmp.size(); timer++) {
        for(int i = 0; i < N; i++) Next[i] = 0;
        /*
        ll Mindex = 0;
        for(int i = 0; i < N; i++) {
            if(l[i] < cmp[timer]) Mindex = i;
        }
        for(int i = Mindex + 1; i < N; i++) {
            if(l[i] >= cmp[timer]) {
                Next[i] += Prev[Mindex];
            }
        }
        for(int from = 0; from <= Mindex; from++) {
            if(r[from] <= cmp[timer-1]) continue;
            for(int to = from; to <= Mindex ; to++) {
                ll delta = cmp[timer] - cmp[timer-1] - 1;
                Next[to] += combination(delta + (to - from), delta) * Prev[from];
                Next[to] %= mod;
            }
        }
        */
        for(int i = 0; i < N; i++) {
            if(r[i] < cmp[timer]) continue;
            for(int j = i; j < N; j++) {
                if(j > i) {
                    if(l[j-1] > cmp[timer-1] or r[j-1] < cmp[timer]) continue;
                }
                //cerr << i << " " << j << endl;
                Next[j] += combination(j - i + cmp[timer] - cmp[timer-1] - 1 , j - i) * Prev[i];
                Next[j] %= mod;
            }
        }
        for(int i = 0; i < N - 1; i++) {
            if(l[i] == cmp[timer]) {
                Next[i + 1] += Next[i];
            }
        }
        swap(Prev, Next);
        //ans += Prev[N-1];
        print(timer);
        //cerr << cmp[timer] << " " << Mindex << endl;
    }
    cout << Prev[N-1] * inv(Total) % mod << endl;
    //cout << Prev[N-1] << endl;
    /*
    ll tmp = combination(420 - 42 + 2, 2);
    ll sub = 420 - 42 + 1;
    tmp += sub * (1337 - 420);
    tmp %= mod;
    */
    //ll tmp = 0;
    //for(ll i = 1; i <= 420 - 41; i++) tmp += i;
    //tmp += (420 - 41) * (1337 - 420);
    //cout << tmp * inv(Total) % mod << endl;
    return 0;
}