    #include <bits/stdc++.h>
    using namespace std;
     
    template <typename S, typename T>
    ostream& operator <<(ostream& out, const pair<S, T>& p) {
        out << "{" << p.first << ", " << p.second << "}";
        return out;
    }
     
    template <typename T1, typename T2, typename T3>
    ostream& operator <<(ostream& out, const tuple<T1,T2,T3>& t) {
        out << "(" << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t) << ")";
        return out;
    }
     
    template <typename T>
    ostream& operator <<(ostream& out, const vector<T>& v) {
        out << "[";
        for (int i = 0; i < (int)v.size(); i++) {
            out << v[i];
            if (i != (int)v.size()-1) out << ", ";
        }
        out << "]";
        return out;
    }
     
     
    struct Tree {
        typedef int Tdata;
     
        struct Node {
            Tdata val;
            Tdata lazy;
            
            Node() {val = 0; lazy=0;};
            Node(Tdata val) {
                this->val = val;
                this->lazy = 0;
            };
            Node(Tdata val, Tdata lazy) {
                this->val = val;
                this->lazy = lazy;
            };
        };
     
        int n;
        vector<Node> a;
        Tdata _base = 0;
     
        Tree(int size) {
            n = size;
            auto v = vector<Tdata>(size, _base);
            a.resize(n*4+1);
            fill(a.begin(), a.end(), _base);
            build(v, 1, 0, n-1);
        }
     
        Tree(vector<Tdata> &v, int size) {
            n = size;
            a.resize(n*4+1);
            fill(a.begin(), a.end(), _base);
            build(v, 1, 0, n-1);
        }
     
        void build(vector<Tdata> &v, int idx, int tl, int tr) {
            if(tl == tr) {
                a[idx] = Node{v[tl]};
            }
            else {
                int tm = (tl + tr) / 2;
                build(v, idx*2, tl, tm);
                build(v, idx*2+1, tm+1, tr);
                a[idx] = Node{a[idx*2].val + a[idx*2+1].val};
            }
        }
     
        void update(int l, int r, Tdata add) {
            _update(1, 0, n-1, l, r, add);
        }
     
        void _update(int idx, int tl, int tr, int l, int r, Tdata add) {
            if(l > r) return;
            if(l == tl && r == tr) {
                a[idx].val += (r-l+1) * add;
                a[idx].lazy += add;
            }
            else {
                push(idx, tl, tr);
                int tm = (tl + tr) / 2;
                _update(idx*2, tl, tm, l, min(r, tm), add);
                _update(idx*2+1, tm+1, tr, max(l, tm+1), r, add);
                a[idx].val = a[idx*2].val + a[idx*2+1].val;
            }
        }
     
        Tdata query(int l, int r) {
            return _query(1, 0, n-1, l, r);
        }
     
        Tdata _query(int idx, int tl, int tr, int l, int r) {
            if(l > r) return _base;
            if(l == tl && r == tr) return a[idx].val;
            push(idx, tl, tr);
            int tm = (tl+tr) / 2;
            return _query(idx*2, tl, tm, l, min(r, tm)) + _query(idx*2+1, tm+1, tr, max(l, tm+1), r);
        }
     
        void push(int idx, int l, int r) {
            int m = (l+r) / 2;
            a[idx*2].val += (m-l+1) * a[idx].lazy;
            a[idx*2].lazy += a[idx].lazy;
            a[idx*2+1].val += (r-m) * a[idx].lazy;
            a[idx*2+1].lazy += a[idx].lazy;
            a[idx].lazy = 0;
        }
    };
     
     
    void solve() {
        int n,m; cin >> n >> m;
        vector<int> a(n*m); for(int i=0; i<n*m; i++) cin >> a[i];
        unordered_map<int,int> map_idx;
        vector<int> b = a;
        sort(b.begin(), b.end());
        for(int i=0; i<n*m; i++) {
            map_idx[b[i]] = i;
        }
        for(int i=0; i<n*m; i++) {
            a[i] = map_idx[a[i]];
        }
        vector<int> cnt(n*m, 0);
        for(auto el: a) cnt[el]++;
        vector<int> sums(n*m, 0);
        sums[0] = cnt[0];
        for(int i=1; i<n*m; i++) {
            sums[i] = cnt[i] + sums[i-1];
        }
        vector<int> ptr(n*m, 0);
        vector<int> pos(n*m, 0);
        for(int i=0; i<n*m; i++) {
            if((sums[a[i]] - 1) / m != (sums[a[i]] - cnt[a[i]]) / m) {
                int x = (sums[a[i]] - cnt[a[i]]) / m;
                pos[i] = m*(x+1) - ptr[a[i]] - 1;
                ptr[a[i]]++;
                if((sums[a[i]] - cnt[a[i]] + ptr[a[i]]) % m == 0) {
                    // time to change it
                    cnt[a[i]] -= ptr[a[i]];
                    ptr[a[i]] = 0;
                }
            }
            else {
                sums[a[i]]--;
                cnt[a[i]]--;
                pos[i] = sums[a[i]];
            }
        }
        // cout << pos << endl;
        vector<int> _arr(n*m, 0);
        Tree seg = Tree{_arr, n*m};
        int tot = 0;
        for(int i=0; i<n*m; i++) {
            int x = pos[i] / m;
            tot += seg.query(x*m, pos[i]-1);
            seg.update(pos[i], pos[i], 1);
        }
        cout << tot << "\n";
    }
     
    int main() {
        ios::sync_with_stdio(0); cin.tie(0);
        int t; cin >> t; while(t--)
        solve();
    }