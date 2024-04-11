#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
struct UnionFind {
    vector<int> par;
    vector<int> rank;
    vector<ll> Size;
    UnionFind(int n = 1) {
        init(n);
    }

    void init(int n = 1) {
        par.resize(n + 1); rank.resize(n + 1); Size.resize(n + 1);
        for (int i = 0; i <= n; ++i) par[i] = i, rank[i] = 0, Size[i] = 1;
    }

    int root(int x) {
        if (par[x] == x) {
            return x;
        }
        else {
            int r = root(par[x]);
            return par[x] = r;
        }
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        Size[x] += Size[y];
        return true;
    }

    ll size(int x){
        return Size[root(x)];
    }
};


int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    UnionFind uni(500050);
    int n, m;
    cin >> n >> m;
    while(m--) {
        int num;
        cin >> num;
        if(num == 0) continue;
        int p;
        cin >> p;
        for(int i = 2; i <= num; i++) {
            int in;
            cin >> in;
            uni.merge(in, p);
        }
    }
    for(int i = 1; i <= n; i++) cout << uni.size(i) << " ";
    cout << endl;
    return 0;
}