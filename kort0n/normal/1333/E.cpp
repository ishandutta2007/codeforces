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
int ans[505][505];
int N;

void Even() {
    int now = 0;
    for(int w = N - 1; w >= 0; w--) {
        now++;
        ans[N-1][w] = now;
    }
    for(int h = N - 2; h >= 0; h--) {
        now++;
        ans[h][0] = now;
    }
    for(int w = 1; w < N - 1; w++) {
        now++;
        ans[0][w] = now;
    }
    for(int h = 1; h < N - 1; h++) {
        now++;
        ans[h][N-1] = now;
    }
    for(int h = N - 2; h >= 1; h -= 2) {
        for(int w = N - 3; w >= 1; w--) {
            now++;
            ans[h][w] = now;
        }
        for(int w = 1; w <= N - 3; w++) {
            now++;
            ans[h-1][w] = now;
        }
    }
    now++;
    ans[0][N-1] = now;
    now++;
    ans[1][N-2] = now;
    for(int h = 2; h < N - 1; h++) {
        now++;
        ans[h][N-2] = now;
    }
}

void Odd() {
    int now = 0;
    for(int w = 0; w < N; w++) {
        now++;
        ans[N-1][w] = now;
    }
    for(int w = N - 1; w >= 0; w--) {
        now++;
        ans[N-2][w] = now;
    }
    for(int h = N - 3; h >= 0; h--) {
        now++;
        ans[h][0] = now;
    }
    for(int w = 1; w < N - 1; w++) {
        now++;
        ans[0][w] = now;
    }
    for(int h = 1; h < N - 2; h++) {
        now++;
        ans[h][N-1] = now;
    }
    for(int h = N - 3; h >= 1; h -= 2) {
        for(int w = N - 3; w >= 1; w--) {
            now++;
            ans[h][w] = now;
        }
        for(int w = 1; w <= N - 3; w++) {
            now++;
            ans[h-1][w] = now;
        }
    }
    now++;
    ans[0][N-1] = now;
    now++;
    ans[1][N-2] = now;
    for(int h = 2; h < N - 2; h++) {
        now++;
        ans[h][N-2] = now;
    }
}

void print() {
    for(int h = 0; h < N; h++) {
        for(int w = 0; w < N; w++) {
            if(w != 0) cout << " ";
            cout << ans[h][w];
        }
        cout << endl;
    }
}
int Three[3][3];

const long long INF = 1e18;
//const ll mod = 1000000007;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    if(N <= 2) {
        cout << -1 << endl;
        return 0;
    }
    if(N == 3) {
        ans[2][0] = 1;
        ans[2][1] = 2;
        ans[1][1] = 3;
        ans[1][2] = 4;
        ans[2][2] = 5;
        ans[0][1] = 6;
        ans[0][0] = 7;
        ans[0][2] = 8;
        ans[1][0] = 9;
        print();
        return 0;
    }
    if(N & 1) Odd();
    else Even();
    print();
    return 0;
}