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
//const ll mod = 1000000007;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<int> primes;
    for(int i = 2; i <= 1e5; i++) {
        bool ok = true;
        for(int j = 2; j * j <= i; j++) {
            if(i % j == 0) ok = false;
        }
        if(ok) primes.push_back(i);
    }
    int n;
    cin >> n;
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j < primes.size(); j++) {
            if(i % primes[j] == 0) {
                cout << j + 1 << " ";
                break;
            }
        }
    }
    cout << endl;
    return 0;
}