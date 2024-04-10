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

const int N = 2020;

int vis[N], dist[N][N], ok[N], n;

void ask(int x){
    cout << "? " << x << endl;
    for (int i = 1; i <= n; i++)
        cin >> dist[x][i];
}


vector<pair<int, int>> edges;
queue<int> q;

void solve(int d) {
    if (d == 0) {
        for (int i = 1; i <= n; i++)
            if (dist[1][i] == 1)
                edges.emplace_back(1, i);
    }
    for (int i = 2; i <= n; i++){
        if (dist[1][i] % 2 == d) {
            ask(i);
            for (int j = 1; j <= n; j++)
                if (dist[i][j] == 1)
                    edges.emplace_back(i, j);
        }
    }
}

int cnt[2];

void Hollwo_Pelw() {
    cin >> n;
    ask(1);

    for (int i = 2; i <= n; i++)
        cnt[dist[1][i] & 1] ++;

    if (cnt[1] >= cnt[0])
        solve(0);
    else
        solve(1);

    cout << "!" << endl;
    for (auto uv : edges)
        cout << uv.first << " " << uv.second << endl;
}