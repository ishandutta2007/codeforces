#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)
using namespace std;
typedef long long LL;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
inline bool valid(int x, int w) { return 0 <= x && x < w; }
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "{"; for(T e : v) os << e << ","; os << "}"; return os;
}
struct UF{
    vector<int> data;
    UF(int N) : data(N) {
        REP(i, N) data[i] = i;
    }
    int root(int x) {
        if(data[x] == x) return x;
        return data[x] = root(data[x]);
    }
    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        data[x] = y;
    }
};

int main(){
    int N;
    while(cin >> N) {
        vector<int> a(N);
        REP(i, N) cin >> a[i];
        UF uf(N);
        REP(i, N) {
            string s;
            cin >> s;
            REP(j, N) if(s[j] =='1') {
                uf.unite(i, j);
            }
        }

        map<int, vector<int>> idx;
        map<int, vector<int>> ary;
        set<int> rts;
        REP(i, N) rts.insert(uf.root(i));
        REP(i, N) idx[ uf.root(i) ].push_back(i);
        REP(i, N) ary[ uf.root(i) ].push_back(a[i]);
        for(auto r : rts) sort(ary[r].begin(), ary[r].end());
        vector<int> b(N);
        for(auto r : rts) {
            for(int i = 0; i < idx[r].size(); i++) {
                b[ idx[r][i] ] = ary[r][i];
            }
        }

        REP(i, N) {
            cout << b[i];
            if(i == N - 1) {
                cout << endl;
            } else {
                cout << " ";
            }
        }
    }
    return 0;
}