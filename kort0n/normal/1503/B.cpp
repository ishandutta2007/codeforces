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
ll N;
vector<l_l> A[2];
ll B[200][200];

void print(l_l a, ll color) {
    cout << color << " " << a.first + 1 << " " << a.second + 1 << endl;
    B[a.first][a.second] = color;
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            A[(i+j)%2].push_back({i, j});
        }
    }
    for(int t = 0; t < N * N; t++) {
        int a;
        cin >> a;
        if(A[0].size() and A[1].size()) {
            if(a != 1) {
                print(A[0].back(), 1);
                A[0].pop_back();
            } else {
                print(A[1].back(), 2);
                A[1].pop_back();
            }
        } else if(!A[0].empty()) {
            if(a != 1) {
                print(A[0].back(), 1);
                A[0].pop_back();
            } else {
                print(A[0].back(), 3);
                A[0].pop_back();
            }
        } else if(!A[1].empty()) {
            if(a != 2) {
                print(A[1].back(), 2);
                A[1].pop_back();
            } else {
                print(A[1].back(), 3);
                A[1].pop_back();
            }
        } else {
            assert(0);
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cerr << B[i][j] << " ";
        }
        cerr << endl;
    }
    return 0;
}