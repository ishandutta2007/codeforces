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
    // cin >> testcases;
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

const int N = 2e5 + 5;

int lg[N], n, a[N];

template<typename T, T(*merge)(T, T) > struct rmq {
    T st[N][18];
    rmq () {}
    rmq (int n) {
        for (int i = 1; i <= n; i++){
            st[i][0] = i;
        }
        for (int j = 1; j < 18; j++){
            for (int i = 1; i + (1 << j) <= n + 1; i++){
                st[i][j] = merge(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    
    void init(int n){
        for (int i = 1; i <= n; i++){
            st[i][0] = i;
        }
        for (int j = 1; j < 18; j++){
            for (int i = 1; i + (1 << j) <= n + 1; i++){
                st[i][j] = merge(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    
    T query(int L, int R){
        if (L > R) return T(0);
        int j = lg[R - L + 1];
        return merge(st[L][j], st[R - (1 << j) + 1][j]);
    }
};

#define max __max__

int max(int x, int y){
    return a[x] > a[y] ? x : y;
}

rmq<int, max> st;
long long ans;

bool vis[N];

void solve (int l, int r, bool keep) {
    if (l > r) return ;
    int m = st.query(l, r);

    // cout << "solve " << l << ' ' << r << "\n";

    int val = a[m];
    if (m - l > r - m) {
        solve(m + 1, r, 0);
        solve(l, m - 1, 1);
        for (int i = m + 1; i <= r; i++)
            if (vis[val - a[i]]) ans ++;
        for (int i = m + 1; i <= r; i++)
            vis[a[i]] = 1;
    } else {
        solve(l, m - 1, 0);
        solve(m + 1, r, 1);
        for (int i = l; i <= m - 1; i++)
            if (vis[val - a[i]]) ans ++;
        for (int i = l; i <= m - 1; i++)
            vis[a[i]] = 1;
    }
    vis[a[m]] = 1;
    if (!keep)
        for (int i = l; i <= r; i++)
            vis[a[i]] = 0;
}

void Hollwo_Pelw() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 2; i <= n; i++)
        lg[i] = lg[i >> 1] + 1;

    st.init(n);
    solve(1, n, 1);
    cout << ans;
}