// #pragma GCC optimize "Ofast"
// #pragma GCC optimize "unroll-loops"
#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxN = 1e5+1;
const ll oo = 1e16;
template<typename T> struct mystack {
    T st[100];
    int size=0;
    bool empty() {return size==0;}
    void push(const T& t) {st[size++]=t;}
    void pop(){size--;}
    T& top() {return st[size-1];}
    void reset(){size=0;}
};

struct segtree {
    struct node {
        ll mn = oo, lazy = 0;
        node() {}
        node(ll val) {
            mn = val;
        }
    };
    vector<node> seg;
    int n, ptwo;
    segtree(int nn) {
        n = nn, ptwo = 1;
        while (ptwo < n) ptwo *= 2;
        seg.resize(2 * ptwo);
    }
    void updateNode(int i, ll val) {
        seg[i].mn += val;
        seg[i].lazy += val;
    }

    void pull(int i) {
        auto& v = seg[i];
        v.mn = min(seg[i * 2].mn, seg[i * 2 + 1].mn);
    }
    void push(int i) {
        if (seg[i].lazy) {
            updateNode(i * 2, seg[i].lazy);
            updateNode(i * 2 + 1, seg[i].lazy);
        }
        seg[i].lazy = 0;
    }
    mystack<int> st;
    mystack<char> state;
    int cnt=0;
    int search() {
        if (seg[1].mn > 0) return n;
        st.reset(), state.reset();
        st.push(1), state.push('0');
        while (!st.empty()) {
            auto i = st.top();
            char c = ++state.top();
            if (i >= ptwo) {
                state.pop(), st.pop();
                if (seg[i].mn == 0) {
                    return i - ptwo;
                }
            } else switch (c) {
                case '1':
                    push(i);
                    if (seg[i * 2].mn <= 0) {
                        st.push(i * 2), state.push('0');
                        break;
                    } else state.top()++;
                case '2':
                    if (seg[i * 2 + 1].mn <= 0) {
                        st.push(i * 2 + 1), state.push('0');
                        break;
                    } else state.top()++;
                default:
                    st.pop(), state.pop();
                    break;
            }
        }
        return n;
    }
    void add(int l, int r, int val) {
        add(1, 0, ptwo - 1, l, r, val);
    }
    void add(int i, int l, int r, int ql, int qr, int val) {
        if (qr < l or r < ql) return;
        if (ql <= l and r <= qr) {
            updateNode(i, val);
            return;
        }
        int mid = (l + r) / 2;
        push(i);
        add(i * 2, l, mid, ql, qr, val), add(i * 2 + 1, mid + 1, r, ql, qr, val);
        pull(i);
    }
    node& operator[](int i) { return seg[i + ptwo]; }
    void build() {
        for (int i = ptwo - 1; i >= 1; --i) {
            pull(i);
        }
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifdef DEBUG
    // freopen("shaman.in","r",stdin);
    // freopen("shaman.out","w",stdout);
    // #endif
    int n,q; cin >> n >> q;
    segtree seg(n);
    ll pref=0;
    vi a(n);
    for(int i=0;i<n;++i) {
        cin >> a[i];
        seg[i] = segtree::node(pref-a[i]);
        pref+=a[i];
    }
    seg.build();
    vi ans(q);
    for(int i=0;i<q;++i) {
        int p,x; cin >> p >> x,--p;
        int delta = x-a[p];
        if(p+1<=n-1) seg.add(p+1,seg.ptwo,delta);
        seg.add(p,p,-delta);
        a[p]=x;
        int j = seg.search();
        if(j<n) ans[i] = j+1;
        else ans[i]=-1;
    }
    for(auto i : ans) cout << i << '\n';
}