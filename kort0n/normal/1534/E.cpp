#include <bits/stdc++.h>
//#include <atcoder/all>
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
bool can[505][505];
i_i from[505][505];
int N, K;
bool A[505];

int main() {
    cin >> N >> K;
    can[0][0] = true;
    int d = -1;
    for(int i = 0; i <= 500; i++) {
        if(can[i][N]) {
            d = i;
            break;
        }
        for(int j = 0; j <= N; j++) {
            if(!can[i][j]) continue;
            for(int k = 0; k <= min(K, j); k++) {
                if(N - j < K - k) continue;
                int l = j - k + (K - k);
                if(l > N) continue;
                can[i+1][l] = true;
                from[i+1][l] = {j, k};
            }
        }
    }
    if(d == -1) {
        cout << -1 << endl;
        return 0;
    }
    vector<int> v;
    int nowd = d;
    int b = N;
    while(nowd >= 1) {
        cerr << nowd << " " << b << endl;
        v.push_back(from[nowd][b].second);
        b = from[nowd][b].first;
        nowd--;
    }
    reverse(v.begin(), v.end());
    ll ans = 0;
    for(auto tmp : v) {
        vector<int> query;
        int use = tmp;
        int unuse = K - tmp;
        cerr << use << " " << unuse << endl;
        for(int i = 0; i < N; i++) {
            if(A[i]) {
                if(use) {
                    use--;
                    query.push_back(i);
                    A[i] = false;
                }
            } else {
                if(unuse) {
                    unuse--;
                    query.push_back(i);
                    A[i] = true;
                }
            }
        }
        cout << "?";
        for(auto val : query) {
            cout << " " << val + 1;
        }
        cout << endl;
        ll ret;
        cin >> ret;
        ans ^= ret;
    }
    cout << "! " << ans << endl;
    return 0;
}