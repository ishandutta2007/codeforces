// Not MST actually, but CF/117E
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

vector<int> g[101005];
vector<vector<int>> st;
vector<int> p;
vector<char> heavy;
vector<char> mkd;
vector<int> cycle;
vector<int> h;
vector<int> lca_with_cycle;
vector<vector<int>> chains;
vector<int> chainNum;
vector<vector<int>> trees;
vector<vector<char>> xors;

int dfs(int v, int prev = -1){
    int cyc = -1;
    for(auto u: g[v]){
        if(u == prev){
            continue;
        }
        if(mkd[u] == 2){
            continue;
        }
        if(mkd[u] == 1){
            cyc = u;
            cycle.push_back(v);
            mkd[v] = 2;
            return cyc;
        }
        mkd[u] = 1;
        cyc = dfs(u, v);
        if(cyc != -1){
            cycle.push_back(v);
            if(cyc == v){
                cyc = -1;
            }else{
                mkd[v] = 2;
                return cyc;
            }
        }
    }
    mkd[v] = 2;
    return -1;
}

int dfs2(int v, int prev = -1){
    int total_size = 1;
    int cur_size, max_size = 0, idx = -1;
    for(auto u: g[v]){
        if(u == prev || (u == cycle[0] && v == cycle[cycle.size() - 1]) || (v == cycle[0] && u == cycle[cycle.size() - 1])){
            continue;
        }
        h[u] = 1 + h[v];
        if(h[u] < cycle.size() && u == cycle[h[u]]){
            lca_with_cycle[u] = u;
        }else{
            lca_with_cycle[u] = lca_with_cycle[v];
        }
        st[v].push_back(u);
        p[u] = v;
        cur_size = dfs2(u, v);
        if(max_size < cur_size){
            max_size = cur_size;
            idx = u;
        }
        total_size += cur_size;
    }
    if(2 * max_size >= total_size){
        heavy[idx] = 1;
    }
    return total_size;
}

int dfs3(int v){
    int ans = -1;
    for(auto u: st[v]){
        int chain = dfs3(u);
        if(chain == -1){
            chain = chains.size();
            chains.push_back({u});
        }
        chainNum[u] = chain;
        chains[chain].push_back(v);
        if(heavy[u]){
            ans = chain;
        }
    }
    return ans;
}

void build(int num, int idx, int l, int r){
    trees[num][idx] = 0;
    if(l == r){
        return;
    }
    int mid = (l + r) >> 1;
    build(num, idx << 1, l, mid);
    build(num, idx << 1 | 1, mid + 1, r);
}

void push(int num, int idx, int l, int r){
    if(xors[num][idx]){
        if(l < r){
            int mid = (l + r) >> 1;
            trees[num][idx << 1] = (mid - l + 1) - trees[num][idx << 1];
            trees[num][idx << 1 | 1] = (r - mid) - trees[num][idx << 1 | 1];
            xors[num][idx << 1] ^= 1;
            xors[num][idx << 1 | 1] ^= 1;
        }
        xors[num][idx] = 0;
    }
}

void update(int num, int idx, int l, int r, int l1, int r1){
    if(l > r || l1 > r1 || l > r1 || l1 > r){
        return;
    }
    push(num, idx, l, r);
    if(l == l1 && r == r1){
        trees[num][idx] = r - l + 1 - trees[num][idx];
        xors[num][idx] ^= 1;
        return;
    }
    int mid = (l + r) >> 1;
    update(num, idx << 1, l, mid, l1, min(mid, r1));
    update(num, idx << 1 | 1, mid + 1, r, max(mid + 1, l1), r1);
    trees[num][idx] = trees[num][idx << 1] + trees[num][idx << 1 | 1];
}

//update returns lca(v1, v2) for conveniency
int update(int v1, int v2){
    while(chainNum[v1] != chainNum[v2]){
        if(v1 != cycle[0] && (v2 == cycle[0] || h[chains[chainNum[v1]].back()] > h[chains[chainNum[v2]].back()])){
            swap(v1, v2);
        }
        int num = chainNum[v2];
        int sz = chains[num].size() - 1;
        int l = sz - h[v2] + h[chains[num].back()];
        int r = sz - 1;
        update(num, 1, 0, sz - 1, l, r);
        v2 = chains[num].back();
    }
    if(v1 != cycle[0]){
        if(h[v1] > h[v2]){
            swap(v1, v2);
        }
        int num = chainNum[v2];
        int sz = chains[num].size() - 1;
        int l = sz - h[v2] + h[chains[num].back()];
        int r = sz - h[v1] + h[chains[num].back()] - 1;
        update(num, 1, 0, sz - 1, l, r);
        return v1;
    }
    return cycle[0];
}

int get(int num, int idx, int l, int r, int l1, int r1){
    if(l > r || l1 > r1 || l > r1 || l1 > r){
        return 0;
    }
    push(num, idx, l, r);
    if(l == l1 && r == r1){
        return trees[num][idx];
    }
    int mid = (l + r) >> 1;
    return get(num, idx << 1, l, mid, l1, min(mid, r1)) +
            get(num, idx << 1 | 1, mid + 1, r, max(mid + 1, l1), r1);
}

int get(int v1, int v2){
    int ans = 0;
    while(chainNum[v1] != chainNum[v2]){
        if(v1 != cycle[0] && (v2 == cycle[0] || h[chains[chainNum[v1]].back()] > h[chains[chainNum[v2]].back()])){
            swap(v1, v2);
        }
        int num = chainNum[v2];
        int sz = chains[num].size() - 1;
        int l = sz - h[v2] + h[chains[num].back()];
        int r = sz - 1;
        ans += get(num, 1, 0, sz - 1, l, r);
        v2 = chains[num].back();
    }
    if(v1 != cycle[0]){
        if(h[v1] > h[v2]){
            swap(v1, v2);
        }
        int num = chainNum[v2];
        int sz = chains[num].size() - 1;
        int l = sz - h[v2] + h[chains[num].back()];
        int r = sz - h[v1] + h[chains[num].back()] - 1;;
        ans += get(num, 1, 0, sz - 1, l, r);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int a, b;
    for(int i = 0; i < n; ++i){
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    mkd.resize(n, 0);
    mkd[0] = 1;
    dfs(0);
    h.resize(n, 0);
    st.resize(n);
    p.resize(n, -1);
    heavy.resize(n, 0);
    chainNum.resize(n, -1);
    lca_with_cycle.resize(n, -1);
    lca_with_cycle[cycle[0]] = cycle[0];
    dfs2(cycle[0]);
    dfs3(cycle[0]);
    trees.resize(chains.size());
    xors.resize(chains.size());
    for(int i = 0; i < chains.size(); ++i){
        trees[i].resize(((int)chains[i].size()) << 2);
        xors[i].resize(((int)chains[i].size()) << 2, 0);
        build(i, 1, 0, chains[i].size() - 1);
    }
    int v, u;
    int ans = 0;
    int cur;
    int cnt;
    int oddEdge = 0;
    for(int i = 0; i < m; ++i){
        cin >> v >> u;
        --v;
        --u;
        int v1 = lca_with_cycle[v];
        int u1 = lca_with_cycle[u];
        cnt = 0;
        cur = 0;
        if(u1 == v1){
            int lca = update(u, v);
            cnt += h[u] + h[v] - 2 * h[lca];
            cur = get(u, v);
            ans += 2 * cur - cnt;
            if(oddEdge && get(cycle[0], cycle[cycle.size() - 1]) != cycle.size() - 1){
                cout << n - ans - 1 << endl;
            }else{
                cout << n - ans << endl;
            }
            continue;
        }
        cnt += h[v] - h[v1] + h[u] - h[u1];
        update(v, v1);
        update(u, u1);
        cur += get(v, v1);
        cur += get(u, u1);
        u = u1;
        v = v1;
        int up, down;
        bool good;
        if(h[u] > h[v]){
            good = false;
            down = cycle[(h[v] + 1) % cycle.size()];
            up = cycle[(h[v] + cycle.size() - 1) % cycle.size()];
            if(2 * (h[u] - h[v]) < cycle.size()){
                good = true;
            }else {
                if (2 * (h[u] - h[v]) > cycle.size()) {
                    good = false;
                }else{
                    good = down < up;
                }
            }
            if(good){
                cnt += h[u] - h[v];
                update(u, v);
                cur += get(u, v);
            }else{
                cnt += cycle.size() - h[u] + h[v] - 1;
                update(cycle[0], v);
                update(u, cycle[cycle.size() - 1]);
                oddEdge ^= 1;
                cur += get(cycle[0], v);
                cur += get(cycle[cycle.size() - 1], u);
            }
        }else{
            good = false;
            down = cycle[(h[v] + 1) % cycle.size()];
            up = cycle[(h[v] + cycle.size() - 1) % cycle.size()];
            if(2 * (h[v] - h[u]) < cycle.size()){
                good = true;
            }else {
                if (2 * (h[v] - h[u]) > cycle.size()) {
                    good = false;
                }else{
                    good = up < down;
                }
            }
            if(good){
                cnt += h[v] - h[u];
                update(u, v);
                cur += get(u, v);
            }else{
                cnt += cycle.size() - h[v] + h[u] - 1;
                update(cycle[0], u);
                update(v, cycle[cycle.size() - 1]);
                oddEdge ^= 1;
                cur += get(cycle[0], u);
                cur += get(cycle[cycle.size() - 1], v);
            }
        }
        ans += 2 * cur - cnt;
        if(oddEdge && get(cycle[0], cycle[cycle.size() - 1]) != cycle.size() - 1){
            cout << n - ans - 1 << endl;
        }else{
            cout << n - ans << endl;
        }
    }
    return 0;
}