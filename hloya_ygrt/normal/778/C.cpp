#include <bits/stdc++.h>
 
using namespace std;
#define files1 freopen("input.txt", "r", stdin)
#define pb push_back
#define pii pair<int, int>
#define endl '\n'
#define f first
#define s second
#define mp make_pair
 
const int maxn = 3e5 + 128, inf = 2e9;
 
void read(int& x) {
    scanf("%d", &x);
}
 
vector<pair<int, int> > g[maxn];
 
struct node {
    int to[26];
    int bor_size;
    node() {
        bor_size = 1;
        for (int i = 0; i < 26; i++) to[i] = 0;
    }
} tree[maxn * 10 + 100];
int tree_sz = 1;
 
int sz[maxn], f[maxn], ans[maxn];
 
void recalc(int v) {
    tree[v].bor_size = 1;
    for (int i = 0; i < 26; i++)
        if (tree[v].to[i])
            tree[v].bor_size += tree[tree[v].to[i]].bor_size;
}
 
vector<pii> saves;
 
void merge(int v, int to) {
    saves.pb(mp(to, -1));
    for (int i = 0; i < 26; i++)
        if (tree[v].to[i] != 0) {
            if (tree[to].to[i] == 0) {
                saves.pb(mp(to, i));
                tree[to].to[i] = tree_sz++;
            }
            merge(tree[v].to[i], tree[to].to[i]);
        }
    recalc(to);
}
 
void merge2(int v, int to) {
    for (int i = 0; i < 26; i++)
        if (tree[v].to[i] != 0) {
            if (tree[to].to[i] == 0) {
                tree[to].to[i] = tree_sz++;
            }
            merge2(tree[v].to[i], tree[to].to[i]);
        }
    recalc(to);
}
 
void tree_dfs(int v) {
    for (int i = 0; i < 26; i++) {
        if (tree[v].to[i] != 0) {
            cout << tree[v].to[i] << ' ' << char(i + 'a') << endl;
            tree_dfs(tree[v].to[i]);
        }
    }
}
 
void dfs(int v, int depth) {
//    cout << v << endl;
    sz[v] = 1;
    int max_son = -1, size_of_it = 0, let;
 
    for (int i = 0; i < (int)g[v].size(); i++) {
        int to = g[v][i].f;
        dfs(to, depth + 1);
        sz[v] += sz[to];
 
        if (sz[to] > size_of_it) {
            size_of_it = sz[to];
            max_son = to;
            let = g[v][i].s;
        }
    }
 
    if (max_son != -1) {
        f[v] = f[max_son];
        for (int i = 0; i < (int)g[v].size(); i++) {
            int to = g[v][i].f;
            if (to != max_son) {
                merge(f[to], f[v]);
            }
        }
 
        ans[depth] -= tree[f[v]].bor_size;
//      cout << v + 1<< ' ' << tree[f[v]].bor_size << endl;
        while (!saves.empty()) {
            int V = saves.back().f, pos = saves.back().s;
            saves.pop_back();
            if (pos != -1) {
                tree[V].to[pos] = 0;
                tree_sz--;
            }
            else
                recalc(V);
        }
    } else {
        ans[depth] -= 1;
    }
 
    f[v] = tree_sz++;
 
    if (max_son != -1) {
        tree[f[v]].to[let] = f[max_son];
        recalc(f[v]);
    }
 
    for (int i = 0; i < (int)g[v].size(); i++) {
        int to = g[v][i].f, let = g[v][i].s;
        if (to != max_son) {
            if (tree[f[v]].to[let] == 0)
                tree[f[v]].to[let] = tree_sz++;
            merge2(f[to], tree[f[v]].to[let]);
            recalc(f[v]);
        }
    }
//  cout << v + 1<< ' ' << tree[f[v]].bor_size << endl;
    ans[depth] += tree[f[v]].bor_size;
}
//  bool used[maxn][26];
//void gen() {
//  int n = 3e5;
//  ofstream cout("input.txt");
//  cout << n << endl;
//
//  memset(used, 0, sizeof(used));
//
//  for (int i = 1; i < n; i++) {
//      while (1) {
//          int v = rand() % i, c = rand() % 26;
//          if (used[v][c]) continue;
//          used[v][c] = 1;
//          cout << v + 1 << ' ' << i + 1 << ' ' << char(c + 'a') << endl;
//          break;
//      }
//  }
//}
 
int main() {
//  gen();
//  return 0;
    int n;
//  files1;
//    clock_t start = clock();
    ios_base::sync_with_stdio(0);
    cin >> n;
 
    for (int i = 0; i + 1 < n; i++) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        u--, v--;
//        cout << u << ' ' << v << ' ' << (int)(c - 'a') << endl;
        g[u].pb(mp(v, c - 'a'));
    }
    dfs(0, 0);
    int mx_ans = 0, p = 0;
    for (int i = 0; i < maxn; i++) {
        if (ans[i] != 0) {
            if (ans[i] > mx_ans) {
                mx_ans = ans[i];
                p = i;
            }
        }
    }
//  cout << mx_ans << endl;
    cout << n - mx_ans << endl << p + 1 << endl;
//  cout << fixed << setprecision(20) << (long double)(clock() - start) / CLOCKS_PER_SEC;
    return 0;
}