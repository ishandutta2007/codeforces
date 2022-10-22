#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 200000;
const int LOG = 18;

int soln[N+5][LOG+1];

int bit[LOG+1][4*N+5];

void bit_add(int w, int x){
    int g = (1 << (w + 1));
    while(x <= g){
        bit[w][x]++;
        x += x & -x;
    }
}

int bit_get(int w, int x){
    int res = 0;
    while(x){
        res += bit[w][x];
        x -= x & -x;
    }
    return res;
}

int cnt[N+5];

vector <pair <int, int>> vec[N+5];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        cnt[x]++;
    }
    int qrs;
    cin >> qrs;
    for(int i=1; i<=qrs; i++){
        int l, r;
        cin >> l >> r;
        vec[l - 1].push_back({l, i});
        vec[r].push_back({l, i});
    }
    for(int i=1; i<=m; i++){
        while(cnt[i]--){
            for(int j=0; j<=LOG; j++){
                bit_add(j, 1 + i%(1 << (j + 1)));
            }
        }
        for(auto c : vec[i]){
            for(int j=0; j<=LOG; j++){
                int g = (1 << (j + 1));
                int l = (1 << j);
                int r = (1 << (j + 1)) - 1;
                l += c.first;
                r += c.first;
                l %= g;
                r %= g;
                if(l <= r){
                    soln[c.second][j] += bit_get(j, l - 1 + 1);
                    soln[c.second][j] += bit_get(j, r + 1);
                }
                else{
                    soln[c.second][j] += bit_get(j, l - 1 + 1);
                    soln[c.second][j] += bit_get(j, g);
                    soln[c.second][j] += bit_get(j, r + 1);
                }
            }
        }
    }
    for(int i=1; i<=qrs; i++){
        bool x0 = 1;
        for(int j=0; j<=LOG; j++){
            x0 &= (soln[i][j]%2 == 0);
        }
        if(x0) cout << "B";
        else cout << "A";
    }
    cout << "\n";
    return 0;
}