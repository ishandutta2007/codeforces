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

const int N = 80, inf = 2e9;

int n, k, dp[N][N], tr[N][N];

struct minion {
    int a, b, id;
    bool operator < (const minion &oth) const {
        if (b != oth.b)
            return b < oth.b;
        return a < oth.a;
    }
} p[N];

void Hollwo_Pelw() {
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> p[i].a >> p[i].b, p[i].id = i + 1;
    sort(p, p + n);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            dp[i][j] = -inf;
    dp[0][0] = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= k; j++){
            if (dp[i][j] < 0) continue ;
            if (dp[i + 1][j] < dp[i][j] + p[i].b * (k - 1))
                dp[i + 1][j] = dp[i][j] + p[i].b * (k - 1), tr[i + 1][j] = j;
            if (dp[i + 1][j + 1] < dp[i][j] + p[i].a + p[i].b * j)
                dp[i + 1][j + 1] = dp[i][j] + p[i].a + p[i].b * j, tr[i + 1][j + 1] = j;
        }
    }
    vector<int> add, del;
    int cur = k;
    for (int i = n; i; i--)
        (tr[i][cur] == cur ? del : add).push_back(p[i - 1].id), cur = tr[i][cur];

    cout << add.size() + del.size() * 2 << "\n";
    reverse(add.begin(), add.end());
    reverse(del.begin(), del.end());
    for (int i = 0; i < k - 1; i++)
        cout << add[i] << " ";
    for (auto i : del)  
        cout << i << " " << -i << " ";
    cout << add.back() << "\n";
}