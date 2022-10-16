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

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
const ll mod = 1000000007;
int A[1005000];
string S;

void f() {
    A[0] = S.size();
    int i = 1;
    int j = 0;
    while(i < S.size()) {
        while(i + j < S.size() && S[j] == S[i+j]) j++;
        A[i] = j;
        if(j == 0) {
            i++;
            continue;
        }
        int k = 1;
        while(i + k < S.size() && k + A[k] < j) A[i+k] = A[k], k++;
        i += k;
        j -= k;
    }
}

ll used[1050000];
ll beki(ll a, ll b) {
    if(b == 0) return 1;
    ll ret = beki(a, b / 2);
    ret = ret * ret % mod;
    if(b & a) ret = ret * a % mod;
    return ret;
}

int x[1050000];

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M >> S;
    for(int i = 1; i <= M; i++) cin >> x[i];
    f();
    for(int i = 0; i <= S.size(); i++) {
        //cout << A[i] << endl;
    }
    for(int i = 1; i <= M; i++) {
        used[x[i]]++;
        used[x[i] + S.size()]--;
        if(i > 1) {
            ll delta = x[i] - x[i-1];
            //cerr << i << " " << delta << endl;
            if(delta < S.size() && A[delta] != S.size() - delta) {
                cout << 0 << endl;
                return 0;
            }
        }
    }
    for(int i = 1; i <= N; i++) used[i] += used[i-1];
    ll ans = 1;
    for(int i = 1; i <= N; i++) {
        if(used[i] == 0) ans = ans * 26 % mod;
    }
    cout << ans << endl;
    return 0;
}