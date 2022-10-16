#include <bits/stdc++.h>
 
using namespace std;
 
/**
 * Author: Simon Lindholm (adapted by Lucian Bicsi)
 * Date: 2017-04-17
 * License: CC0
 * Description: Finds all biconnected components in an undirected graph, and
 *  runs a callback for the edges in each. 
 *  Callback should operate on vector<pair<int, int>>::iterators.
 *  In a biconnected component there
 *  are at least two distinct paths between any two nodes. Note that a node can
 *  be in several components. An edge which is not in a component is a bridge,
 *  i.e., not part of any cycle.
 *
 *  To get the articulation points, look for vertices that are in more than 1 BCC.
 * Time: O(E + V)
 * Status: tested during MIPT ICPC Workshop 2017
 */
 
 
struct BCC {
    vector<pair<int, int>> edges;
    vector<vector<int>> G;
    vector<int> enter, low, stk;
 
    BCC(int n) : G(n), enter(n, -1) {}
 
    int AddEdge(int a, int b) {
        int ret = edges.size();
        edges.emplace_back(a, b);
        G[a].push_back(ret); 
        G[b].push_back(ret);
        return ret;
    }
 
    vector<vector<int>> bccs;
    vector<vector<int>> edgs;
    
    template<typename Iter>
    void Callback(Iter bg, Iter en) {
        vector<int> verts;
        vector<int> es;

        for (Iter it = bg; it != en; ++it) {
            verts.push_back(edges[*it].first);
            verts.push_back(edges[*it].second);
            es.push_back(*it);
        }
        sort(verts.begin(), verts.end());
        verts.erase(unique(verts.begin(), verts.end()), verts.end());
 
        bccs.emplace_back(move(verts));
        edgs.emplace_back(move(es));
    }
    
    void Solve() {
        for (int i = 0; i < (int)G.size(); ++i)
            if (enter[i] == -1) {
                dfs(i, -1);
            } 
    }
 
    int timer = 0;
    int dfs(int node, int pei) {
        enter[node] = timer++;
        int ret = enter[node];
 
        for (auto ei : G[node]) if (ei != pei) {
            int vec = (edges[ei].first ^ edges[ei].second ^ node);
            if (enter[vec] != -1) {
                ret = min(ret, enter[vec]);
                if (enter[vec] < enter[node])
                    stk.push_back(ei);
            } else {
                int sz = stk.size(), low = dfs(vec, ei);
                ret = min(ret, low);
                stk.push_back(ei);
                if (low >= enter[node]) {
                    Callback(stk.begin() + sz, stk.end());
                    stk.resize(sz);
                }
            }
        }
        return ret;
    }    
};
 


int main() {
    int n, m; cin >> n >> m;
 
    BCC bcc(n);
    for(int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        bcc.AddEdge(a - 1, b - 1);
    }
    bcc.Solve();
    
    
    vector <int> ans;

    for(int i = 0; i < bcc.bccs.size(); i++)
    {
        if(bcc.bccs[i].size() == bcc.edgs[i].size())
            for(auto &j : bcc.edgs[i])
                ans.push_back(j);
    }
    cout << ans.size() << '\n';
    sort(ans.begin(), ans.end());
    for(auto i: ans) cout << i + 1<< ' ';
    return 0;
}