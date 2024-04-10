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
    cin >> testcases;
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

#define ll long long
#define ld long double 
#define F first 
#define S second
#define pii pair<int, int>
#define sz(a) (int) a.size()
#define eb emplace_back
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

const ld eps = 1e-9;
const int inf = 2e9;
const ll linf = 1e18;

const int MAXN = 3e5 + 5;
const int mod = 1e9 + 7;

int n, a[MAXN], b[MAXN];
vector<int> p[MAXN];

struct node {
    int val; // value
    node () : val(inf) {} // initial 
    node (int v) : val(v) {} // assign 
    void upd(int v){val = v;} // update 
    friend node operator + (node l, node r) { // merge
        return l.val > r.val ? r : l;
    }
} st[MAXN << 2];
#define left id << 1, tl, tm
#define right id << 1 | 1, tm + 1, tr
void upd(int p, int v, int id = 1, int tl = 1, int tr = n){
    if (p > tr || p < tl) return ;
    if (tl == tr) return st[id].upd(v);
    int tm = tl + tr >> 1;
    upd(p, v, left), upd(p, v, right);
    st[id] = st[id << 1] + st[id << 1 | 1];
}
node query(int l, int r, int id = 1, int tl = 1, int tr = n){
    if (l > tr || tl > r) return node();
    if (l <= tl && tr <= r) return st[id];
    int tm = tl + tr >> 1;
    return query(l, r, left) + query(l, r, right);
}
void Hollwo_Pelw() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        p[i].clear();
    for (int i = 1; i <= n; i++){
        cin >> a[i], p[a[i]].pb(i);
    }
    for (int i = 1; i <= n; i++){
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++){
        reverse(all(p[i]));
        upd(i, p[i].empty() ? inf : p[i].back());
    }
    // cerr << query(2, 2).val << "\n";
    for (int i = 1; i <= n; i++){
        if (p[b[i]].empty()) 
            return cout << "NO\n", (void) 0;
        int pos = p[b[i]].back();
        if (query(1, b[i]).val < pos)
            return cout << "NO\n", (void) 0;
        p[b[i]].pop_back();
        upd(b[i], p[b[i]].empty() ? inf : p[b[i]].back());
    }
    cout << "YES\n";
}