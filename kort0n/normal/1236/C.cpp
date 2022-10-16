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
vector<int> ans[305];

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    for(int i = 0; i < N / 2; i++) {
        for(int j = 0; j < N; j++) {
            ans[j].push_back(i * N + j);
            ans[j].push_back(N * N - 1 - i * N - j);
        }
    }
    if(N & 1) {
        for(int i = 0; i < N; i++) {
            ans[i].push_back(N * (N / 2) + i);
        }
    }
    for(int i = 0; i < N; i++) {
        for(auto val : ans[i]) cout << val + 1 << " ";
        cout << endl;
    }
    return 0;
}