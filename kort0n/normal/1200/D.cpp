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
int N, K;
string field[2005];
int column[2005][2005];
int row[2005][2005];

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    for(int i = 0; i < N; i++) cin >> field[i];
    for(int i = 0; i < N; i++) {
        int l = N + 1;
        int r = -1;
        for(int j = 0; j < N; j++) {
            if(field[i][j] == 'B') {
                chmin(l, j);
                chmax(r, j);
            }
        }
        if(r == -1) {
            row[0][0]++;
            continue;
        }
        //cerr << l << " " << r << endl;
        if(r - K + 1 >= l + 1) continue;
        row[max(0, i - K + 1)][max(0, r - K + 1)]++;
        row[max(0, i - K + 1)][l+1]--;
        row[i+1][max(0, r - K + 1)]--;
        row[i+1][l+1]++;
    }
    for(int i = 0; i < N; i++) {
        for(int j = 1; j < N; j++) {
            row[i][j] += row[i][j-1];
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 1; j < N; j++) {
            row[j][i] += row[j-1][i];
        }
    }
    for(int i = 0; i < N; i++) {
        int l = N + 1;
        int r = -1;
        for(int j = 0; j < N; j++) {
            if(field[j][i] == 'B') {
                chmin(l, j);
                chmax(r, j);
            }
        }
        if(r == -1) {
            column[0][0]++;
            continue;
        }
        //cerr << l << " " << r << endl;
        if(r - K + 1 >= l + 1) continue;
        /*
        row[max(0, i - K + 1)][max(0, r - K + 1)]++;
        row[max(0, i - K + 1)][l+1]--;
        row[i+1][max(0, r - K + 1)]--;
        row[i+1][l+1]++;
        */
        column[max(0, r - K + 1)][max(0, i - K + 1)]++;
        column[max(0, r-K+1)][i+1]--;
        column[l+1][max(0, i - K + 1)]--;
        column[l+1][i+1]++;
        //column[max(0, i - K + 1)][max(0, r - K + 1)]++;
        //column[i+1][min(N, l + 1)]--;
    }
    for(int i = 0; i < N; i++) {
        for(int j = 1; j < N; j++) {
            column[i][j] += column[i][j-1];
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 1; j < N; j++) {
            column[j][i] += column[j-1][i];
        }
    }
    int ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            chmax(ans, row[i][j] + column[i][j]);
        }
    }
    /*
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cerr << column[i][j] << " ";
        }
        cerr << endl;
    }
    cerr << endl;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cerr << row[i][j] << " ";
        }
        cerr << endl;
    }
    */
    cout << ans << endl;
    return 0;
}