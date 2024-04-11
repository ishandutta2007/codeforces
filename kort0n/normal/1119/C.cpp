#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
int N, M;
int A[505][505];
int B[505][505];
int n = 1;
int m = 1;
bool can = true;

void query() {
    m++;
    if(m > M) {
        can = false;
        return;
    }
    if(A[n][m] == 1) return;
    query();
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> A[i][j];
        }
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> B[i][j];
            A[i][j] ^= B[i][j];
        }
    }
    for(; n < N; n++) {
        m = 1;
        for(; m <= M; m++) {
            if(A[n][m] == 1) {
                int before = m;
                query();
                A[n][m] = 0;
                A[n][before] = 0;
                A[n+1][m] = 1 - A[n+1][m];
                A[n+1][before] = 1 - A[n+1][before];
            }
        }
    }
    for(int m = 1; m <= M; m++) {
        if(A[N][m] == 1) can = false;
    }
    if(can) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}