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
bool asked[2005];
vector<int> ret[2005];
vector<i_i> ans;

void ask(int now) {
    if(asked[now]) return;
    cout << "? " << now + 1 << endl;
    ret[now].resize(N);
    for(int j = 0; j < N; j++) cin >> ret[now][j];
}

void ANSWER() {
    cout << "!" << endl;
    assert(ans.size() == N - 1);
    for(auto e : ans) {
        cout << e.first + 1 << " " << e.second + 1 << endl;
    }
}

int main() {
    cin >> N;
    ask(0);
    ll num[2] = {0, 0};
    for(int i = 0; i < N; i++) {
        num[ret[0][i]%2]++;
    }
    int parity = 0;
    if(num[1] < num[0]) parity = 1;
    for(int i = 1; i < N; i++) {
        if(ret[0][i] % 2 == parity) ask(i);
    }
    for(int i = 0; i < N; i++) {
        if(parity != ret[0][i] % 2) continue;
        for(int j = 0; j < N; j++) {
            if(ret[i][j] == 1) ans.push_back({i, j});
        }
    }
    ANSWER();
    return 0;
}