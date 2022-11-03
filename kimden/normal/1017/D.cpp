//D
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;




int main()
{
    ios_base::sync_with_stdio(false);
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> c(12, 0);
    vector<int> cnt(1 << 12, 0);
    const int N = 1206;
    vector<vector<int>> pref(1 << 12, vector<int>(N, 0));
    for(int i = 0; i < n; ++i){
        cin >> c[i];
    }
    string s;
    int x;
    for(int i = 0; i < m; ++i){
        cin >> s;
        x = 0;
        for(int j = 0; j < n; ++j){
            if(s[j] == '1'){
                x ^= (1 << j);
            }
        }
        ++cnt[x];
    }
    for(int xr = 0; xr < (1 << n); ++xr){
        int cost = 0;
        for(int i = 0; i < n; ++i) {
            if((xr & (1 << i)) == 0){
                cost += c[i];
            }
        }
        for(int i = 0; i < (1 << n); ++i){
            pref[i][cost] += cnt[i ^ xr];
        }
    }
    for(int i = 0; i < (1 << n); ++i){
        for(int j = 1; j < N; ++j){
            pref[i][j] += pref[i][j - 1];
        }
    }
    int k;
    for(int i = 0; i < q; ++i){
        cin >> s >> k;
        x = 0;
        for(int j = 0; j < n; ++j){
            if(s[j] == '1'){
                x ^= (1 << j);
            }
        }
        cout << pref[x][k] << endl;
    }


    return 0;
}