#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using i_i = pair<int, int>;
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

int N, Q;
int a[1501][1501];
using arr = array<i_i, 11>;
arr blocking[2][1501][1501];
int sz[2][1501][1501];

arr dp[1501];
int dpsz[1501];

bool added[1501*1501];

int SZ(arr a) {
    for(int i = 0; i < a.size(); i++) {
        if(a[i].second == 0) return i; 
    }
    return a.size();
}

arr merge(arr &a, arr &b) {
    int asz = SZ(a);
    int bsz = SZ(b);
    int aidx = 0;
    int bidx = 0;
    arr ret;
    int retsz = 0;
    while((aidx != asz or bidx != bsz) and retsz <= Q) {
        //cerr << "A" << " " << asz << " " << aidx << " " << bsz << " " << bidx << endl;
        if(aidx < asz and added[a[aidx].second]) {
            aidx++;
            continue;
        }
        if(bidx < bsz and added[b[bidx].second]) {
            bidx++;
            continue;
        }
        if(aidx == asz) {
            ret[retsz] = b[bidx];
            retsz++;
            bidx++;
        } else if(bidx == bsz) {
            ret[retsz] = a[aidx];
            retsz++;
            aidx++;
        } else {
            if(a[aidx].first < b[bidx].first) {
                ret[retsz] = a[aidx];
                retsz++;
                added[a[aidx].second] = true;
                aidx++;
            } else {
                ret[retsz] = b[bidx];
                retsz++;
                added[b[bidx].second] = true;
                bidx++;
            }
        }
    }
    for(auto tmp : ret) {
        if(tmp.second == 0) continue;
        added[tmp.second] = false;
    }
    /*
    for(auto tmp : a) cerr << "{ " << tmp.first << ", " << tmp.second << "} ";
    cerr << endl;
    for(auto tmp : b) cerr << "{ " << tmp.first << ", " << tmp.second << "} ";
    cerr << endl;
    cerr << "->" << endl;
    for(auto tmp : ret) cerr << "{ " << tmp.first << ", " << tmp.second << "} ";
    cerr << endl;
    cerr << endl;
    */
    return ret;
}

void add(arr &v, i_i tmp) {
    arr b;
    b[0] = tmp;
    v = merge(v, b);
}

void f(int idx) {
    for(int h = 0; h < N; h++) dp[h] = arr(), dpsz[h] = 0;
    for(int w = N - 1; w >= 0; w--) {
        for(int h = 1; h < N; h++) {
            //cerr << idx << " " << w << " " << h << endl;
            dp[h-1] = merge(dp[h], dp[h-1]);
        }
        for(int h = 0; h < N; h++) {
            add(dp[h], {w, a[h][w]});
            blocking[idx][h][w] = dp[h];
        }
    }
}

int ans[1510];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> Q;
    for(int h = 0; h < N; h++) {
        for(int w = 0; w < N; w++) {
            cin >> a[h][w];
        }
    }
    f(0);
    for(int h = 0; h < N; h++) {
        for(int w = 0; w < h; w++) {
            swap(a[h][w], a[w][h]);
        }
    }
    f(1);
    for(int h = 0; h < N; h++) {
        for(int w = 0; w < h; w++) {
            swap(a[h][w], a[w][h]);
            swap(blocking[1][h][w], blocking[1][w][h]);
        }
    }
    /*
    for(int h = 0; h < N; h++) {
        for(int w = 0; w < N; w++) {
            cerr << "---" << h << "---" << w << endl;
            for(auto tmp : blocking[0][h][w]) {
                cerr << "{" << tmp.first << ", " << tmp.second << "} ";
            }
            cerr << endl;
            for(auto tmp : blocking[1][h][w]) {
                cerr << "{" << tmp.first << ", " << tmp.second << "} ";
            }
            cerr << endl;
        }
    }
    */
    for(int h = 0; h < N; h++) {
        for(int w = 0; w < N; w++) {
            auto v1 = blocking[0][h][w];
            for(auto &tmp : v1) {
                tmp.first -= w;
            }
            auto v2 = blocking[1][h][w];
            for(auto &tmp : v2) {
                tmp.first -= h;
            }
            arr v = merge(v1, v2);
            int len = min(N - h, N - w);
            if(SZ(v) > Q) {
                chmin(len, v[Q].first);
            }
            ans[len]++;
            //cerr << len << " ";
        }
        //cerr << endl;
    }
    for(int i = N - 1; i >= 1; i--) {
        ans[i] += ans[i+1];
    }
    for(int i = 1; i <= N; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}