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

const int N = 505;

int n, m, a[N], b[N], dp[N], tr[N], ans[N];

void Hollwo_Pelw() {
    cin >> n; 
    for (int i = 1; i <= n; i++) 
        cin >> a[i];
    cin >> m; 
    for (int i = 1; i <= m; i++) 
        cin >> b[i];

    for (int i = 1; i <= n; i++){
        int k = 0;
        for (int j = 1; j <= m; j++){
            if (a[i] == b[j])
                dp[j] = dp[k] + 1, tr[j] = k;
            if (a[i] > b[j] && dp[j] > dp[k])
                k = j;
            // cout << dp[j] << " \n"[j == m];
        }
    }
    int i = max_element(dp, dp + m + 1) - dp, t = dp[i], res = dp[i];

    cout << res << "\n";
    while (t) {
        ans[t --] = b[i];
        i = tr[i];
    }
    for (int i = 1; i <= res; i++)
        cout << ans[i] << " ";
}