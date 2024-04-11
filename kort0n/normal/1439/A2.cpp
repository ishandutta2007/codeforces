#include <bits/stdc++.h>
//#include <atcoder/all>
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

const long long INF = 1e18;
//const ll mod = 1000000007;

ll T;
ll H, W;
bool S[105][105];
vector<vector<int>> ans;
void A(vector<int> v) {
    assert(v.size() == 6);
    S[v[0]][v[1]] = !S[v[0]][v[1]];
    S[v[2]][v[3]] = !S[v[2]][v[3]];
    S[v[4]][v[5]] = !S[v[4]][v[5]];
    ans.push_back(v);
}

void f(int h, int w) {
    if(!S[h][w] and !S[h][w+1]) return;
    vector<int> v;
    if(S[h][w] and S[h][w+1]) {
        v = {h, w, h, w+1, h+1, w};
    } else if(S[h][w]) {
        v = {h,w,h+1,w,h+1,w+1};
    } else {
        v = {h,w+1,h+1,w,h+1,w+1};
    }
    A(v);
}

void g(int h, int w) {
    if(!S[h][w] and !S[h+1][w]) return;
    vector<int> v;
    if(S[h][w] and S[h+1][w]) {
        v = {h,w,h+1,w,h+1,w+1};
    } else if(S[h][w]) {
        v = {h,w,h,w+1,h+1,w+1};
    } else {
        v = {h+1,w,h,w+1,h+1,w+1};
    }
    A(v);
}
bool CLEAR() {
    for(int h = 0; h < H; h++) {
        for(int w = 0; w < W; w++) {
            if(S[h][w]) return false;
        }
    }
    return true;
}

void B(int h, int w) {
    vector<vector<int>> V;
    vector<int> Q;
    for(int dh = 0; dh < 2; dh++) {
        for(int dw = 0; dw < 2; dw++) {
            Q.push_back(h+dh);
            Q.push_back(w+dw);
        }
    }
    for(int i = 0; i < 4; i++) {
        V.push_back(Q);
        V.back().erase(V.back().begin() + 2 * i);
        V.back().erase(V.back().begin() + 2 * i);
    }
    for(int bits = 0; bits < (1 << V.size()); bits++) {
        for(int i = 0; i < V.size(); i++) {
            if(bits & (1 << i)) A(V[i]);
        }
        if(CLEAR()) return;
        for(int i = 0; i < V.size(); i++) {
            if(bits & (1 << i)) A(V[i]);
        }
        for(int i = 0; i < __builtin_popcount(bits) * 2; i++) {
            ans.pop_back();
        }
    }
}

void print() {
    assert(CLEAR());
    assert(ans.size() <= H * W);
    /*
    for(int h = 0; h < H; h++) {
        for(int w = 0; w < W; w++) {
            cerr << S[h][w];
        }
        cerr << endl;
    }
    */
    cout << ans.size() << endl;
    cerr << "A" << endl;
    for(auto v : ans) {
        for(int i = 0; i < 6; i++) {
            if(i % 2 == 0) {
                assert(0 <= v[i] and v[i] < H);
            } else {
                assert(0 <= v[i] and v[i] < W);
            }
            if(i != 0) cout << " ";
            cout << v[i] + 1;
        }
        cout << endl;
    }
}

void solve() {
    ans.clear();
    cin >> H >> W;
    for(int h = 0; h < H; h++) {
        string B;
        cin >> B;
        for(int w = 0; w < W; w++) {
            S[h][w] = (B[w] == '1');
        }
    }
    for(int h = 0; h + 1 < H; h++) {
        for(int w = 0; w + 1 < W; w += 2) {
            f(h, w);
        }
        if(W % 2 == 1) {
            f(h, W - 2);
        }
    }
    for(int w = 0; w + 2 < W; w++) {
        g(H - 2, w);
    }
    B(H - 2, W - 2);
    print();
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> T;
    while(T--) solve();
    return 0;
}