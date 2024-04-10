#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1000000;

int res_row[N+5];
int res_col[N+5];
int last[N+5];

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i=0; i<=n*m; i++) res_row[i] = res_col[i] = 0;
    string s;
    cin >> s;
    last[0] = -1;
    if(s[0] == '1') last[0] = 0;
    for(int i=1; i<n*m; i++){
        last[i] = last[i-1];
        if(s[i] == '1') last[i] = i;
    }
    for(int md=0; md<m; md++){
        for(int i=md; i<n*m; i+=m){
            if(s[i] == '1'){
                res_col[i]++;
                break;
            }
        }
    }
    for(int i=1; i<n*m; i++) res_col[i] += res_col[i-1];
    for(int i=0; i<m; i++){
        if(last[i] > -1) res_row[i] = 1;
    }
    for(int i=m; i<n*m; i++){
        res_row[i] = res_row[i-m];
        if(last[i] > i - m) res_row[i]++;
    }
    for(int i=0; i<n*m; i++) cout << res_row[i] + res_col[i] << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}