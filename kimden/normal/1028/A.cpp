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
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    int l = -1, r = -1;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(l == -1 && a[i][j] == 'B'){
                l = j;
            }
            if(r == -1 && l != -1 && a[i][j] == 'W'){
                r = j - 1;
            }
        }
        if(l != -1 && r == -1){
            r = m - 1;
        }
        if(l != -1){
            break;
        }
    }
    int t = -1, d = -1;
    for(int i = 0; i < n; ++i){
        if(t == -1 && a[i][l] == 'B'){
            t = i;
        }
        if(t != -1 && d == -1 && a[i][l] == 'W'){
            d = i - 1;
        }
    }
    if(t != -1 && d == -1){
        d = n - 1;
    }
    cout << ((t + d) / 2 + 1) << " " << ((l + r) / 2 + 1) << endl;



    return 0;
}