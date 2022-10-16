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

const int INF = 1e9;
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
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        Size[x] += Size[y];
        return true;
    }

    ll size(int x){
        return Size[root(x)];
    }
};

ll N, Q;
ll node[150000][27];
ll subtree[150000][27];
int p[150000];
int tmpp[150000];
vector<int> children[150000];
int val[150000];
int tmpval[150000];

void f(int now) {
    //cerr << "f: " << now << endl;
    if(children[now].size() == 0) {
        for(int i = 0; i < 27; i++) {
            subtree[now][i] = node[now][i];
        }
    }
    if(children[now].size() == 1) {
        for(int i = 0; i < 27; i++) {
            subtree[now][i] = node[now][i] + subtree[children[now][0]][i];
        }
    }
    if(children[now].size() == 2) {
        //cerr << now << " " << children[now][0] << " " << children[now][1] << endl;
        int num[2] = {0, 0};
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 27; j++) {
                num[i] += subtree[children[now][i]][j];
            }
        }
        if(num[0] != num[1]) {
            for(int i = 0; i < 27; i++) subtree[now][i] = -INF;
        } else {
            int tmpnum = num[0];
            //cerr << tmpnum << endl;
            for(int i = 0; i < 26; i++) {
                subtree[now][i] = max(subtree[children[now][0]][i], subtree[children[now][1]][i]);
                tmpnum -= subtree[now][i];
            }
            //cerr << tmpnum << endl;
            if(tmpnum < 0) {
                for(int i = 0; i < 27; i++) subtree[now][i] = -INF;
            } else {
                subtree[now][26] = tmpnum;
                for(int i = 0; i < 27; i++) {
                    subtree[now][i] += node[now][i];
                }
            }
        }
    }
    /*
    cerr << "-----" << now << "------" << endl;
    for(int i = 0; i < 27; i++) {
        cerr << subtree[now][i] << " ";
    }
    cerr << endl;
    */
}

void dfs(int now) {
    cerr << "---dfs: " << now << endl; 
    cerr << "children: ";
    for(auto tmp : children[now]) {
        cerr << tmp << " ";
    }
    cerr << endl;
    for(auto tmp : children[now]) dfs(tmp);
}
UnionFind uni;

void print() {
    for(int i = 0; i < N; i++) {
        if(uni.root(i) != i) continue;
        cerr << "-------------" << i << "-------------" << endl;
        for(int j = 0; j < 27; j++) {
            cerr << subtree[i][j] << " ";
        }
        cerr << endl;
    }
}

int main() {
    cin >> N >> Q;
    p[0] = -1;
    for(int i = 1; i < N; i++) {
        cin >> p[i];
        p[i]--;
        char tmp;
        cin >> tmp;
        if(tmp == '?') tmpval[i] = 26;
        else tmpval[i] = (int)(tmp - 'a');
        val[i] = 26;
        children[p[i]].push_back(i);
    }
    uni.init(N);
    for(int i = 0; i < N; i++) {
        if(children[i].size() == 1) {
            uni.merge(i, children[i][0]);
        }
    }
    for(int i = 1; i < N; i++) {
        node[uni.root(i)][val[i]]++;
    }
    for(int i = 0; i < N; i++) {
        tmpp[i] = p[i];
        p[i] = -1;
    }
    for(int i = 0; i < N; i++) {
        if(children[i].size() == 2) {
            //cerr << i << " " << children[i][0] << " " << children[i][1] << " " << uni.root(i) << endl;
            p[children[i][0]] = uni.root(i);
            p[children[i][1]] = uni.root(i);
        }
    }
    for(int i = 0; i < N; i++) children[i].clear();
    for(int i = 0; i < N; i++) {
        if(p[i] != -1) {
            children[p[i]].push_back(i);
        }
    }
    //dfs(0);
    for(int i = N - 1; i >= 0; i--) {
        if(uni.root(i) == i) f(i);
    }
    if(subtree[0][0] < 0) {
        for(int q = 0; q < Q; q++) {
            cout << "Fou" << endl;
        }
        return 0;
    }
    for(int i = 1; i < N; i++) {
        val[i] = tmpval[i];
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 27; j++) {
            subtree[i][j] = 0;
            node[i][j] = 0;
        }
    }
    for(int i = 1; i < N; i++) {
        node[uni.root(i)][val[i]]++;
    }
    for(int i = N - 1; i >= 0; i--) {
        if(uni.root(i) == i) f(i);
    }
    //print();
    for(int q = 0; q < Q; q++) {
        int v;
        char tmp;
        cin >> v >> tmp;
        v--;
        int c;
        if(tmp == '?') c = 26;
        else c = (int)(tmp - 'a');
        int now = uni.root(v);
        node[now][val[v]]--;
        val[v] = c;
        node[now][val[v]]++;
        int nownode = now;
        while(true) {
            //cerr << nownode << endl;
            f(nownode);
            if(p[nownode] == -1) break;
            nownode = p[nownode];
        }
        //print();
        //cerr << v << " " << now << " " << c << endl;
        /*
        for(int i = 0; i < 27; i++) {
            cerr << subtree[0][i] << " ";
        }
        cerr << endl;
        */
        if(subtree[0][0] < 0) {
            cout << "Fou" << endl;
        } else {
            cout << "Shi ";
            ll ans = 0;
            for(ll i = 0; i < 26; i++) {
                ans += (i + 1) * (subtree[0][i] + subtree[0][26]);
            }
            cout << ans << endl;
        }
    }
    return 0;
}