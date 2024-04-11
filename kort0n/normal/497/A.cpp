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
int N, M;
bool ok[105];
string S[105];
string field[105];

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for(int i = 1; i <= N; i++) cin >> S[i];
    int ans = 0;
    for(int i = 0; i < M; i++) {
        bool now = true;
        for(int j = 1; j <= N; j++) {
            field[j].push_back(S[j][i]);
        }
        for(int i = 1; i < N; i++) {
            if(field[i] > field[i+1]) now = false;
        }
        if(!now) {
            for(int j = 1; j <= N; j++) field[j].pop_back();
        }
    }
    cout << M - field[1].size() << endl;
    return 0;
}