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

vector<int> v;
int N;
void print(vector<int> v) {
    for(int i = 0; i < v.size(); i++) {
        if(i != 0) cout << " ";
        cout << v[i];
    }
    cout << endl;
}
bool One() {
    for(int i = 0; i < N; i++) {
        if(v[i] != v[0]) return false;
    }
    cout << 1 << endl;
    for(int i = 0; i < N; i++) {
        if(i != 0) cout << " ";
        cout << 1;
    }
    cout << endl;
    return true;
}


bool Two() {
    vector<int> ret;
    for(int i = 0; i < N; i++) {
        ret.push_back((i&1) + 1);
    }
    if(N % 2 == 0) {
        cout << 2 << endl;
        print(ret);
        return true;
    }
    if(v[0] == v.back()) {
        cout << 2 << endl;
        print(ret);
        return true;
    }
    for(int i = 0; i < N - 1; i++) {
        if(v[i] == v[i+1]) {
            for(int j = i + 1; j < N; j++) {
                ret[j] = 3 - ret[j];
            }
            cout << 2 << endl;
            print(ret);
            return true;
        }
    }
    return false;
}

void Three() {
    cout << 3 << endl;
    vector<int> ret;
    for(int i = 0; i < N; i++) {
        ret.push_back((1&i) + 1);
    }
    ret.back() = 3;
    print(ret);
}

void solve() {
    cin >> N;
    v.resize(N);
    for(int i = 0; i < N; i++) cin >> v[i];
    if(One()) return;
    if(Two()) return;
    Three();
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}