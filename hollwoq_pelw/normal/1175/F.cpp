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

const int N = 3e5 + 5;

int n, lg[N], a[N], lst[N], cur[N];

template<typename T, T(*merge)(T, T) > struct rmq {
    T st[N][20];
    rmq () {}
    rmq (int n, T * arr) {
        for (int i = 1; i <= n; i++){
            st[i][0] = arr[i];
        }
        for (int j = 1; j < 20; j++){
            for (int i = 1; i + (1 << j) <= n + 1; i++){
                st[i][j] = merge(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    
    void init(int n, T * arr){
        for (int i = 1; i <= n; i++){
            st[i][0] = arr[i];
        }
        for (int j = 1; j < 20; j++){
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
    return x > y ? x : y;
}

rmq<int, max> st;

void Hollwo_Pelw() {
    cin >> n, lg[0] = -1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        lst[i] = max(lst[i - 1], cur[a[i]] + 1);
        cur[a[i]] = i, lg[i] = lg[i >> 1] + 1;
    }
    st.init(n, a);
    int ans = 0;
    for (int i = n; i; i--){
        for (int j = i; j >= lst[i];) {
            int _max = st.query(j, i);
            if (_max == i - j + 1)
                ans ++, j --;
            else
                j = i - _max + 1;
        }
    }
    cout << ans;
}