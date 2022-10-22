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

const int N = 2020, mod = 1e9 + 7;

char a[N][N];
int n, m;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool inb(int x, int y){
    return 1 <= x && x <= n && 1 <= y && y <= m;
}

void Hollwo_Pelw() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    int ans = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (a[i][j] == '#'){
                queue<pair<int, int>> q;
                q.emplace(i, j);
                a[i][j] = '0';
                int res = 1, cnt = 0;
                while (!q.empty()) {
                    int x = q.front().first, y = q.front().second; q.pop();
                    res = 2ll * res % mod, cnt ++;
                    for (int d = 0; d < 4; d++){
                        int nx = x + dx[d], ny = y + dy[d];
                        if (inb(nx, ny) && a[nx][ny] == '#') {
                            a[nx][ny] = '0';
                            q.emplace(nx, ny);
                        }
                    }
                }
                if (cnt == n * m) {
                    cout << (1ll * res - 1 + mod) % mod << "\n";
                    return ;
                }
                ans = 1ll * ans * res % mod;
            }
        }
    }
    cout << ans << "\n";
}