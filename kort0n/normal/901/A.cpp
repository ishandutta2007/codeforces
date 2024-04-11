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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int H;
    cin >> H;
    vector<int> A(H + 1);
    ll N = 0;
    for(int h = 0; h < H + 1; h++) {
        cin >> A[h];
        N += A[h];
    }
    int height = -1;
    for(int h = 0; h < H; h++) {
        if(A[h] > 1 and A[h+1] > 1) height = h;
    }
    if(height == -1) {
        cout << "perfect" << endl;
        return 0;
    }
    cout << "ambiguous" << endl;
    cerr << height << endl;
    vector<int> a(N), b(N);
    int Last = 0;
    int root = 0;
    for(int h = 1; h < H + 1; h++) {
        if(height + 1 != h) {
            for(int i = 0; i < A[h]; i++) {
                a[Last+1+i] = root + 1;
                b[Last+1+i] = root + 1;
            }
        } else {
            for(int i = 0; i < A[h]; i++) {
                a[Last+1+i] = root + 1;
                b[Last+1+i] = root + 1 + (i % 2);
            }
        }
        Last += A[h];
        root += A[h-1];
    }
    for(int i = 0; i < N; i++) {
        if(i != 0) cout << " ";
        cout << a[i];
    }
    cout << endl;
    for(int i = 0; i < N; i++) {
        if(i != 0) cout << " ";
        cout << b[i];
    }
    cout << endl;
    return 0;
}