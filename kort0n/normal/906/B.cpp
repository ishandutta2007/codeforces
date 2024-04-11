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

const long long INF = 1e18;
//const ll mod = 1000000007;
ll H, W;
vector<ll> ans[105000];
vector<ll> v;

bool f(int x, int y) {
    int xh = x / W;
    int xw = x % W;
    int yh = y / W;
    int yw = y % W;
    return abs(xh - yh) + abs(xw - yw) == 1;
}

bool can() {
    for(int h = 0; h < H; h++) {
        ans[h].clear();
        for(int w = 0; w < W; w++) {
            ans[h].push_back(v[h*W+w]);
        }
    }
    for(int h = 0; h < H; h++) {
        for(int w = 0; w < W; w++) {
            if(h > 0 and f(ans[h-1][w], ans[h][w])) return false;
            if(w > 0 and f(ans[h][w-1], ans[h][w])) return false;
        }
    }
    return true;
}

void solve() {
    v.resize(W);
    for(int i = 0; i < W; i++) v[i] = i/2 + ((W+1) / 2)*(i&1);
    if(W == 4) {
        v[0] = 1;
        v[1] = 3;
        v[2] = 0;
        v[3] = 2;
    }
    for(int j = 0; j < H; j++) {
        for(int i = 0; i < W; i++) {
            if(W % 2 == 0) {
                if(j % 2 == 0) ans[j].push_back(v[i] + W * j);
                else ans[j].push_back(v[W-1-i] + W * j);
            } else {
                if(j % 2 == 0) ans[j].push_back(v[i] + W * j);
                else ans[j].push_back(v[(i+2)%W] + W * j);
            }
        }
    }
}

void print() {
    cout << "YES" << endl;
    for(int h = 0; h < H; h++) {
        for(int w = 0; w < W; w++) {
            cout << ans[h][w] + 1 << " ";
        }
        cout << endl;
    }
}

void print2() {
    cout << "YES" << endl;
    for(int w = 0; w < W; w++) {
        for(int h = 0; h < H; h++) {
            int sh = ans[h][w] / W;
            int sw = ans[h][w] % W;
            cout << sw * H + sh + 1 << " ";
        }
        cout << endl;
    }
}

bool verify() {
    set<ll> st;
    for(int h = 0; h < H; h++) {
        for(int w = 0; w < W; w++) {
            assert(0 <= ans[h][w] and ans[h][w] < H * W);
            assert(st.find(ans[h][w]) == st.end());
            st.insert(ans[h][w]);
            if(h > 0 and f(ans[h-1][w], ans[h][w])) return false;
            if(w > 0 and f(ans[h][w-1], ans[h][w])) return false;
        }
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> H >> W;
    if(W >= 4) {
        solve();
        assert(verify());
        print();
        return 0;
    }
    if(H >= 4) {
        swap(H, W);
        solve();
        assert(verify());
        print2();
        return 0;
    }
    for(int i = 0; i < H * W; i++) v.push_back(i);
    do {
        if(can()) {
            verify();
            print();
            return 0;
        }
    } while(next_permutation(v.begin(), v.end()));
    cout << "NO" << endl;
    return 0;
}