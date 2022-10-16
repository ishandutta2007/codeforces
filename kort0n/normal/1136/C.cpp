#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
ll n, m;
ll A[505][505];
ll B[505][505];

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) cin >> A[i][j];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) cin >> B[i][j];
    }
    for(int sum = 2; sum <= n + m; sum++) {
        vector<int> a;
        vector<int> b;
        for(int i = 1; i <= n; i++) {
            int j = sum - i;
            if(j < 1 || j > m) continue;
            a.push_back(A[i][j]);
            b.push_back(B[i][j]);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for(int i = 0; i < a.size(); i++) {
            if(a[i] != b[i]) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}