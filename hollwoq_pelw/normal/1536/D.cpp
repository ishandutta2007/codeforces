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

const int N = 2e5 + 5;

int n, a[N];

void Hollwo_Pelw() {
    set<int> st;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    st.insert(-2e9);
    st.insert(+2e9);
    st.insert(a[1]);
    for (int i = 2; i <= n; i++){
        st.insert(a[i]);
        auto it = st.lower_bound(a[i]);
        if (*prev(it) == a[i - 1] || *it == a[i - 1] || *next(it) == a[i - 1])
            continue ;
        cout << "NO\n";
        return ;
    }
    cout << "YES\n";
}