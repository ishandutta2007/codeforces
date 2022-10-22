/* 
// is short or still long ???
hollwo_pelw's template(short)
// Note : -Dhollwo_pelw_local
*/

#include<bits/stdc++.h>
using namespace std;

void FAST_IO(string filein = "", string fileout = "", string fileerr = ""){
    if (fopen(filein.c_str(), "r")){
        freopen(filein.c_str(), "r", stdin);
        freopen(fileout.c_str(), "w", stdout);
        #ifdef hollwo_pelw_local
            freopen(fileerr.c_str(), "w", stderr);
        #endif
    }
    cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
}

void Hollwo_Pelw();

signed main(){
    #ifdef hollwo_pelw_local
        FAST_IO("input.inp", "output.out", "error.err");
        auto start = chrono::steady_clock::now();
    #else
        FAST_IO(".inp", ".out");
    #endif
    int testcases = 1;
    // cin >> testcases;
    for (int test = 1; test <= testcases; test++){
        // cout << "Case #" << test << ": ";
        Hollwo_Pelw();
    }
    #ifdef hollwo_pelw_local
        auto end = chrono::steady_clock::now();
        cout << endl;
        cout << "Excution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
    #endif
    return 0;
}

const int N = 2e5 + 5;

struct trie_node {
    int ch[2];
    trie_node () {
        ch[0] = ch[1] = -1;
    }
} trie[N << 4];

int node_cnt, n;

void __init__() {
    for (int i = 0; i <= node_cnt; i++) 
        trie[i] = trie_node();
    node_cnt = 0;
}

void add(int num) {
    int p = 0;
    for (int i = 29; i >= 0; i--) {
        int x = num >> i & 1;
        if (!~trie[p].ch[x])
            trie[p].ch[x] = ++ node_cnt;
        p = trie[p].ch[x];
    }
}

int query(int num) {
    int p = 0, res = 0;
    for (int i = 29; i >= 0; i--) {
        int x = num >> i & 1;
        if (!~trie[p].ch[x])
            x ^= 1, res ^= 1 << i;
        p = trie[p].ch[x];
    }
    return res;
}

queue<pair<int, vector<int>>> q;
long long ans;

void solve(int bt, vector<int> &work){
    if ((int) work.size() <= 1) return ;
    vector<int> sub[2];

    for (auto &v : work)
        sub[v >> bt & 1].push_back(v);

    if (!sub[0].empty() && !sub[1].empty()) {
        __init__();
        int res = 1ll << 30;

        for (auto &v : sub[0]) add(v);
        for (auto &v : sub[1]) 
            res = min(res, query(v));

        ans += res;
    }

    if (bt) {
        q.emplace(bt - 1, sub[0]);
        q.emplace(bt - 1, sub[1]);
    }
}

void Hollwo_Pelw() {
    set<int> allp;
    cin >> n;
    for (int i = 1, x; i <= n; i++)
        cin >> x, allp.insert(x);
    vector<int> work;
    for (auto v : allp)
        work.push_back(v);
    q.emplace(29, work);
    while (!q.empty()) {
        solve(q.front().first, q.front().second), q.pop();
    }
    cout << ans;
}