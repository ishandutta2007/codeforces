#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }

vector<priority_queue<pair<int, int>>> dq;

int pid;
struct Trie
{
    char a_init;
    int D;
    int INVALID = -1;
    std::vector<std::vector<int>> child;
    using T_NODE = int;
    vector<T_NODE> v_info;
    Trie(char a_init = 'a', int D = 26) : a_init(a_init), D(D), child(1, std::vector<int>(D, INVALID)), v_info(1) {}
    void add_word(string str, T_NODE info) {
        int now = 0;
        for (auto &c : str) {
            if (child[now][c - a_init] == INVALID) {
                child[now][c - a_init] = child.size();
                child.emplace_back(std::vector<int>(D, INVALID));
                v_info.resize(child.size());
            }
            now = child[now][c - a_init];
        }
        v_info[now] += info;
    }
};
Trie trie;

int dfs(int now, int depth)
{
    int i = -1, si = -1;
    queue<int> ds;
    REP(d, 26) if (trie.child[now][d] != -1) {
        int j = dfs(trie.child[now][d], depth + 1);
        if (chmax<int>(si, dq[j].size())) {
            i = j;
        }
        ds.emplace(j);
    }
    if (i == -1) {
        i = dq.size();
        dq.resize(i + 1);
        ds.emplace(i);
    }
    if (trie.v_info[now]) {
        dq[i].emplace(depth, pid++);
    }
    while (ds.size()) {
        int dsn = ds.front();
        ds.pop();
        if (dsn != i)
        {
            while (dq[dsn].size())
            {
                dq[i].push(dq[dsn].top());
                dq[dsn].pop();
            }
        }
    }
    if (!trie.v_info[now] and dq[i].size()) {
        dq[i].pop();
        dq[i].emplace(depth, pid++);
    }
    return i;
}


int main()
{
    pid = 0;
    int N;
    cin >> N;
    trie.add_word("", 1);
    while (N--) {
        string S;
        cin >> S;
        trie.add_word(S, 1);
    }

    int p = dfs(0, 0);

    long long ret = 0;
    while (dq[p].size()) {
        ret += dq[p].top().first;
        dq[p].pop();
    }
    cout << ret << "\n";
}