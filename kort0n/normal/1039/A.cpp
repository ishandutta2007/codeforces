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
ll rev[201000];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, T;
    cin >> N >> T;
    vector<ll> a(N), x(N), b(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        b[i] = a[i] + T;
    }
    for(int i = 0; i < N; i++) {
        cin >> x[i];
        x[i]--;
        if(x[i] < i) {
            cout << "No" << endl;
            return 0;
        }
        rev[i]++;
        rev[x[i]]--;
        if(i > 0 and x[i] < x[i-1]) {
            cout << "No" << endl;
            return 0;
        }
    }
    for(int i = 1; i <= N; i++) rev[i] += rev[i-1];
    for(int i = 0; i < N; i++) cerr << rev[i] << " ";
    cerr << endl;
    for(int i = 0; i < N; i++) {
        if(rev[i] > 0) {
            chmax(b[i], a[i+1] + T);
        }
    }
    for(int i = 1; i < N; i++) {
        chmax(b[i], b[i-1] + 1);
    }
    for(int i = 0; i < N; i++) {
        bool ok = true;
        if(x[i] + 1 < N and a[x[i]+1] + T <= b[x[i]]) ok = false;
        if(!ok) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    for(int i = 0; i < N; i++) {
        if(i != 0) cout << " ";
        cout << b[i];
    }
    cout << endl;
    return 0;
}