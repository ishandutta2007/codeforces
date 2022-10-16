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
ll N;
vector<ll> A, B;
string S;
ll ans = 0;

bool increasing(vector<ll> &v) {
    for(int i = 1; i < v.size(); i++) {
        if(v[i-1] > v[i]) return false;
    }
    return true;
}

bool nonpositive(vector<ll> &v) {
    for(auto val : v) {
        if(val <= 0) return true;
    }
    return false;
}

void decrease() {
    if(N >= 3) {
        for(int i = N - 1; i >= 1; i--) {
            B[i] -= B[i-1];
        }
        S.push_back('P');
        ans++;
        return;
    } else {
        ll timer;
        if(A[0] == B[0] and (B[1] - A[1]) % B[0] == 0) {
            timer = (B[1] - A[1]) / B[0];
        } else if (A[1] == B[0] and (B[1] - A[0]) % B[0] == 0) {
            timer = (B[1] - A[0]) / B[0];
        } else {
            ll delta = B[0];
            timer = (B[1] - B[0] + delta - 1) / delta;
        }
        ans += timer;
        for(ll i = 0; i < timer; i++) {
            if(S.size() > 6e5) break;
            S.push_back('P');
        }
        B[1] -= timer * B[0];
        if(timer == 0) {
            cout << "IMPOSSIBLE" << endl;
            exit(0);
        }
    }
    return;
}

void print(vector<ll> &a) {
    for(auto val : a) {
        cerr << val << " ";
    }
    cerr << endl;
}

vector<ll> rev(vector<ll> a) {
    reverse(a.begin(), a.end());
    return a;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    A.resize(N);
    B.resize(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];
    bool changed = false;
    while(true) {
        //print(A);
        //print(B);
        if(A == B) break;
        else if(rev(B) == A) {
            S.push_back('R');
            break;
        }
        if(!increasing(B)) {
            if(changed) {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
            changed = true;
            S.push_back('R');
            reverse(B.begin(), B.end());
            continue;
        }
        changed = false;
        decrease();
        if(nonpositive(B)) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    if(ans > 200000) {
        cout << "BIG" << endl;
        cout << ans << endl;
    } else {
        cout << "SMALL" << endl;
        cout << S.size() << endl;
        reverse(S.begin(), S.end());
        cout << S << endl;
    }
    return 0;
}