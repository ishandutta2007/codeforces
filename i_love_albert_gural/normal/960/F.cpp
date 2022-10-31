#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

template<typename T> struct seg_tree {
    int S;

    T zero;
    vector<T> value;

    seg_tree<T>(int _S, T _zero = T()) {
        S = _S, zero = _zero;
        value.resize(2*S+1, zero);
    }

    void set_leaves(vector<T> &leaves) {
        copy(leaves.begin(), leaves.end(), value.begin() + S);

        for (int i = S - 1; i > 0; i--) 
            value[i] = value[2 * i] + value[2 * i + 1];
    }

    void upd(int i, T v) {
        i += S;
        value[i] = v;
        while(i>1){
            i/=2;
            value[i] = value[2*i] + value[2*i+1];
        }
    }

    T query(int i, int j) {
        T res_left = zero, res_right = zero;
        for(i += S, j += S; i <= j; i /= 2, j /= 2){
            if((i&1) == 1) res_left = res_left + value[i++];
            if((j&1) == 0) res_right = value[j--] + res_right;
        }
        return res_left + res_right;
    }
};

struct imax {
    int val;
    imax(int _val = 0) {
        val = _val;
    }
    imax operator+(const imax &o) const {
        return imax(max(val, o.val));
    }
};

int find_length(seg_tree<imax> &st, vi &ws, int w) {
    auto it = lower_bound(all(ws), w);
    if (it == ws.begin()) return 0;
    return st.query(0, it - ws.begin() - 1).val;
}

void update_if_better(seg_tree<imax> &st, vi &ws, int w, int l) {
    int wi = lower_bound(all(ws), w) - ws.begin();
    //assert(ws[wi] == w);
    int cv = st.query(wi, wi).val;
    if (cv < l) {
        st.upd(wi, l);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, M;
    cin >> N >> M;

    vi a(M), b(M), w(M);
    vvi ws(N);

    for (int i = 0; i < M; i++) {
        cin >> a[i] >> b[i] >> w[i];
        a[i]--, b[i]--;
        ws[b[i]].push_back(w[i]);
    }

    vector<seg_tree<imax>> trees;
    for (int i = 0; i < N; i++) {
        sort(all(ws[i]));
        ws[i].erase(unique(all(ws[i])), ws[i].end());
        trees.push_back(seg_tree<imax>(ws[i].size()));
    }

    int ans = 0;
    for (int i = 0; i < M; i++) {
        int l = find_length(trees[a[i]], ws[a[i]], w[i]) + 1;
        ans = max(ans, l);
        update_if_better(trees[b[i]], ws[b[i]], w[i], l);
    }

    cout << ans << endl;
    return 0;
}