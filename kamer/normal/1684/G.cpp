#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <utility>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct PushRelabel {
struct Edge {
int dest, back;
ll f, c;
};
vector<vector<Edge>> g;
vector<ll> ec;
vector<Edge*> cur;
vector<vi> hs; vi H;
PushRelabel(int n) : g(n), ec(n), cur(n), hs(2*n), H(n) {}
void addEdge(int s, int t, ll cap, ll rcap=0) {
if (s == t) return;
g[s].push_back({t, sz(g[t]), 0, cap});
g[t].push_back({s, sz(g[s])-1, 0, rcap});
}
void addFlow(Edge& e, ll f) {
Edge &back = g[e.dest][e.back];
if (!ec[e.dest] && f) hs[H[e.dest]].push_back(e.dest);
e.f += f; e.c -= f; ec[e.dest] += f;
back.f -= f; back.c += f; ec[back.dest] -= f;
}
ll calc(int s, int t) {
int v = sz(g); H[s] = v; ec[t] = 1;
vi co(2*v); co[0] = v-1;
rep(i,0,v) cur[i] = g[i].data();
for (Edge& e : g[s]) addFlow(e, e.c);
for (int hi = 0;;) {
while (hs[hi].empty()) if (!hi--) return -ec[s];
int u = hs[hi].back(); hs[hi].pop_back();
while (ec[u] > 0) // discharge u
if (cur[u] == g[u].data() + sz(g[u])) {
H[u] = 1e9;
for (Edge& e : g[u]) if (e.c && H[u] > H[e.dest]+1)
H[u] = H[e.dest]+1, cur[u] = &e;
if (++co[H[u]], !--co[hi] && hi < v)
rep(i,0,v) if (hi < H[i] && H[i] < v)
--co[H[i]], H[i] = v + 1;
hi = H[u];
} else if (cur[u]->c && H[u] == H[cur[u]->dest]+1)
addFlow(*cur[u], min(ec[u], cur[u]->c));
else ++cur[u];
}
}
bool leftOfMinCut(int a) { return H[a] >= sz(g); }
};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int n, m;
    cin >> n >> m;
    vector<int> t(n);
    unordered_set<int> large_nums;
    unordered_set<int> small_nums;

    vector<int> large_counts;
    vector<int> small_counts;

    unordered_map<int, int> large_index;
    unordered_map<int, int> small_index;
    
    unordered_map<int, int> inv_l_index;
    unordered_map<int, int> inv_s_index;


    for (int i = 0; i < n; i++) {
        cin >> t[i];

        if (t[i] > m / 3) {
            if (large_nums.find(t[i]) != large_nums.end()) {
                large_counts[large_index[t[i]]]++;
            } else {
                large_nums.insert(t[i]);
                large_index[t[i]] = large_nums.size() - 1;
                inv_l_index[large_nums.size() - 1] = t[i];
                large_counts.push_back(1);
            }
        } else {

            if (small_nums.find(t[i]) != small_nums.end()) {
                small_counts[small_index[t[i]]]++;
            } else {
                small_nums.insert(t[i]);
                small_index[t[i]] = small_nums.size() - 1;
                inv_s_index[small_nums.size() - 1] = t[i];
                small_counts.push_back(1);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (t[i] > m / 2) {
            cout << "-1\n";
            return 0;
        }
    }

    PushRelabel flow(2 + large_nums.size() + small_nums.size());

    int l_size = large_nums.size();
    int s_size = small_nums.size();
    for (int i = 0; i < l_size; i++) {
        flow.addEdge(0, i + 1, large_counts[i]);
    }
    for (int i = 0; i < s_size; i++) {
        flow.addEdge(l_size + 1 + i, l_size + s_size + 1, small_counts[i]);
    }

    for (auto l_el : large_nums) {
        for (int s_num = 1; (2 * l_el + s_num <= m) && (s_num * s_num <= l_el); s_num++) {
            if (l_el % s_num == 0) {
                if (small_nums.find(s_num) != small_nums.end()) {
                    flow.addEdge(large_index[l_el] + 1, l_size + 1 + small_index[s_num], large_counts[large_index[l_el]]);
                }

                int other_num = l_el / s_num;
                if (2 * l_el + other_num <= m && other_num != s_num) {
                    if (small_nums.find(other_num) != small_nums.end()) {
                        flow.addEdge(large_index[l_el] + 1, l_size + 1 + small_index[other_num], large_counts[large_index[l_el]]);
                    }
                }
            }
        }
    }

    flow.calc(0, l_size + s_size + 1);

    for (int i = 0; i < l_size; i++) {
        if (flow.g[0][i].f != large_counts[i]) {
            // cout << "BAD " << i << " " << flow.g[0][i + 1].f << " " << large_counts[i] << "\n";
            cout << "-1\n";
            return 0;
        }
    }

    vector<tuple<int, int>> p;

    for (int i = 1; i <= l_size; i++) {
        int large_num = inv_l_index[i - 1];
        for (auto edge : flow.g[i]) {
            if (edge.f > 0) {
                int small_num = inv_s_index[edge.dest - 1 - l_size];
                for (int j = 0; j < edge.f; j++) {
                    p.emplace_back(2 * large_num + small_num, large_num + small_num);
                    small_counts[edge.dest - 1 - l_size]--;
                }
            }
        }
    }

    for (int i = 0; i < s_size; i++) {
        if (small_counts[i] > 0) {
            for (int j = 0; j < small_counts[i]; j++) {
                p.emplace_back(3 * inv_s_index[i], 2 * inv_s_index[i]);
            }
        }
    }

    cout << p.size() << "\n";

    for (auto [a, b] : p) {
        cout << a << " " << b << "\n";
    }






}