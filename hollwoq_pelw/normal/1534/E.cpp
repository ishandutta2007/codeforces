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
        FAST_IO("hollwo_pelw_interactive.inp", "hollwo_pelw_interactive.out");
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

int dist[N], nxt[N], n, k;

int cur[N], cnt, res;

void Hollwo_Pelw() {
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        dist[i] = 1e9;

    queue<int> q;
    q.push(n);
    while (!q.empty()) {
        int u = q.front(); q.pop();
//        cout << u << ' ' << dist[u] << endl;
        for (int i = 0; i <= k; i++) {
            int j = k - i; // i 0s, j 1s
            if (j <= n - u && i <= u) {
                int v = u - i + j;
                if (dist[v] > dist[u] + 1) {
                    dist[v] = dist[u] + 1;
                    nxt[v] = u;
                    q.push(v);
                }
            }
        }
    }
    if (dist[0] > 500)
        return cout << -1 << endl, (void) 0;
//    cout << dist[0];
    while (cnt != n) {
        // nxt = cnt + i - j
        int diff = nxt[cnt] - cnt;
        int zer = (k + diff) / 2;
        int one = (k - diff) / 2;

//        cout << cnt << ' ' << zer << ' ' << one << endl;

        cout << "? ";
        for (int i = 1; i <= n; i++) {
            if (cur[i] == 0) {
                if (zer > 0)
                    cout << i << " ", zer --, cur[i] ^= 1;
            }else {
                if (one > 0)
                    cout << i << " ", one --, cur[i] ^= 1;
            }
        }
        cout << endl;
        int x; cin >> x;
        res ^= x;
        cnt = nxt[cnt];
    }
    cout << "! " << res << endl;
}