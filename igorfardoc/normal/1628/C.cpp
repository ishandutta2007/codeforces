#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vvi a;
int n;

int calc() {
    vvi here(n, vi(n, 0));
    int res = 0;
    int bef = 0;
    for(int i = 0; i < n - 1; i++) {
        here[i + 1][i] = bef ^ a[i][i];
        bef = here[i + 1][i];
        res ^= here[i + 1][i];
    }
    for(int i = 2; i < n - 1; i++) {
        for(int j = 0; j < i - 1; j++) {
            if((i + j) % 2 == 1) continue;
            int here1 = a[i][j] ^ a[j][i];
            here1 ^= here[i][j + 1];
            here1 ^= here[i - 1][j];
            if(j != 0) {
                here1 ^= here[i][j - 1];
            }
            here[i + 1][j] = here1;
            res ^= here[i + 1][j];
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        a.assign(n, vi(n));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
        int res = calc();
        for(int i = 0; i < n; i++) {
            reverse(a[i].begin(), a[i].end());
        }
        res ^= calc();
        cout << res << '\n';
    }
}