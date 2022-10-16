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
    vector<int> a(2), b(1);
    a[1] = 1;
    b[0] = 1;
    int N;
    cin >> N;
    for(int i = 1; i < N; i++) {
        vector<int> c(i + 2);
        for(int j = 0; j < a.size(); j++) {
            c[j+1] = a[j];
        }
        /*
        for(int j = 0; j < b.size(); j++) {
            if(i & 1) c[j] -= b[j];
            else c[j] += b[j];
        }
        */
        for(int k = -1; k <= 1; k+=2) {
            for(int j = 0; j < b.size(); j++) {
                c[j] += k * b[j];
            }
            bool ok = true;
            for(int j = 0; j < c.size(); j++) {
                if(abs(c[j]) > 1) ok = false;
            }
            if(ok) break;
            for(int j = 0; j < b.size(); j++) {
                c[j] -= k * b[j];
            }
            assert(k != 1);
        }
        swap(a, b);
        swap(a, c);
    }
    cout << a.size() - 1 << endl;
    for(int i = 0; i < a.size(); i++) {
        if(i != 0) cout << " ";
        cout << a[i];
    }
    cout << endl;
    cout << b.size() - 1 << endl;
    for(int i = 0; i < b.size(); i++) {
        if(i != 0) cout << " ";
        cout << b[i];
    }
    cout << endl;
    return 0;
}