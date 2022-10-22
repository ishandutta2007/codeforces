#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1000000;

vector <int> pre[N+5];
vector <int> mat[N+5];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        string s;
        cin >> s;
        mat[i].push_back(-1);
        for(int j=1; j<=m; j++){
            if(s[j-1] == '.') mat[i].push_back(1);
            else mat[i].push_back(0);
        }
    }
    for(int i=0; i<=m; i++) pre[0].push_back(0), mat[0].push_back(-1);
    for(int i=1; i<=n; i++){
        pre[i].push_back(0);
        for(int j=1; j<=m; j++){
            if(mat[i-1][j] == 0 && mat[i][j-1] == 0){
                pre[i].push_back(1);
            }
            else pre[i].push_back(0);
            pre[i][j] += pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
        }
    }
    int qrs;
    cin >> qrs;
    while(qrs--){
        int l, r;
        cin >> l >> r;
        int x = pre[n][r] - pre[n][l];
        if(x == 0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}