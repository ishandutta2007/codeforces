#include <bits/stdc++.h>

using namespace std;

struct Tree{
    vector<int> tree;
    vector<int> add;
    vector<int> ar;
    Tree(){}
    Tree(vector<int> _ar){
        ar = _ar;
        tree.resize(4 * ar.size());
        add.resize(4 * ar.size());
        build(0, 0, ar.size());
    }

    void build(int pos, int l, int r){
        if(r - l == 1){
            tree[pos] = ar[l];
            return;
        }
        build(2 * pos + 1, l, (l + r) / 2);
        build(2 * pos + 2, (l + r) / 2, r);
        tree[pos] = max(tree[2 * pos + 1], tree[2 * pos + 2]);
    }

    void push(int pos, int l, int r){
        if(add[pos] == 0) return;
        if(r - l == 1){
            tree[pos] += add[pos];
            add[pos] = 0;
            return;
        }
        add[2 * pos + 1] += add[pos];
        add[2 * pos + 2] += add[pos];
        tree[pos] += add[pos];
        add[pos] = 0;
    }

    void add_seg(int pos, int l, int r, int vl, int vr, int delta){
        push(pos, l, r);
        if(vl >= r || l >= vr) return;
        if(vl <= l && r <= vr){
            add[pos] += delta;
            push(pos, l ,r);
            return;
        }
        add_seg(2 * pos + 1, l, (l + r) / 2, vl, vr, delta);
        add_seg(2 * pos + 2, (l + r) / 2, r, vl, vr, delta);
        tree[pos] = max(tree[2 * pos + 1], tree[2 * pos + 2]);
    }

    int get_max(int pos, int l, int r, int vl, int vr){
        push(pos, l, r);
        if(vl >= r || l >= vr) return -(1e9);
        if(vl <= l && r <= vr){
            return tree[pos];
        }
        return max(get_max(2 * pos + 1, l, (l + r) / 2, vl, vr), get_max(2 * pos + 2, (l + r) / 2, r, vl, vr));
    }

};

const int INF = 1e9;


int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<pair<int, int>> b(m);
    vector<vector<pair<int, int>>> beg(n);
    vector<vector<pair<int, int>>> fin(n + 1);
    for(int i = 0; i < m; i++){
        cin >> b[i].first >> b[i].second;
        b[i].first--; b[i].second--;
        beg[b[i].first].push_back(b[i]);
        fin[b[i].second + 1].push_back(b[i]);
    }
    int ans = -INF;
    int cur = -1;
    Tree tree = Tree(a);
    for(int i = 0; i < n; i++){
        for(auto f : beg[i]){
            tree.add_seg(0, 0, n, f.first, f.second + 1, -1);
        }
        for(auto f : fin[i]){
            tree.add_seg(0, 0, n, f.first, f.second + 1, 1);
        }
        int h = tree.get_max(0, 0, n, 0, n);
        int f = tree.get_max(0, 0, n, i, i + 1);
        if(h - f > ans){
            ans = h - f;
            cur = i;
        }
    }
    vector<int> an;
    for(int i = 0; i < m; i++){
        if(b[i].first <= cur && cur <= b[i].second){
            an.push_back(i + 1);
        }
    }
    cout << ans << endl;
    cout << an.size() << endl;
    for(int i : an) cout << i << " ";
    cout << endl;
    return 0;
}