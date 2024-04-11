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

int A[55][55];

int di[4] = {-1, -1, 0, 0};
int dj[4] = {0, -1, -1, 0};
int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> A[i][j];
        }
    }
    vector<i_i> v;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            bool ok = false;
            if(A[i][j] == 0) {
                continue;
            }
            for(int k = 0; k < 4; k++) {
                bool now = true;
                if(ok) break;
                int newi = i + di[k];
                int newj = j + dj[k];
                if(newi <= 0 || newi + 1 > n || newj <= 0 || newj + 1 > m) now = false;
                else {
                    if(A[newi][newj] == 0) now = false;
                    if(A[newi+1][newj] == 0) now = false;
                    if(A[newi][newj+1] == 0) now = false;
                    if(A[newi+1][newj+1] == 0) now = false;
                }
                if(now) {
                    ok = true;
                    v.push_back({min(newi, i), min(newj, j)});
                }
            }
            if(!ok) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << v.size() << endl;
    for(int i = 0; i < v.size(); i++) {
        cout << v[i].first << " " << v[i].second << endl;
    }
    return 0;
}