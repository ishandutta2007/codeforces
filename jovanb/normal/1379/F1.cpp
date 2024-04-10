#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 400000;

map <pair <int, int>, bool> bg;
map <pair <int, int>, bool> bd;

int maxk[N+5], mink[N+5];

int bitmn[N+5], bitmx[N+5];

void bitmx_upd(int x, int k){
    while(x <= N){
        bitmx[x] = min(bitmx[x], k);
        x += x & -x;
    }
}

void bitmn_upd(int x, int k){
    while(x <= N){
        bitmn[x] = max(bitmn[x], k);
        x += x & -x;
    }
}

int bitmx_mn(int x){
    int mn = 2*N + 5;
    while(x){
        mn = min(mn, bitmx[x]);
        x -= x & -x;
    }
    return mn;
}

int bitmn_mx(int x){
    int mx = 0;
    while(x){
        mx = max(mx, bitmn[x]);
        x -= x & -x;
    }
    return mx;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);

    int n, m, qrs;
    cin >> n >> m >> qrs;
    bool dne = 0;
    for(int i=1; i<=N; i++) bitmx[i] = 2*N;
    for(int i=1; i<=n; i++) maxk[i] = m;
    for(int tt=1; tt<=qrs; tt++){
        int ih, jh;
        cin >> ih >> jh;
        if(dne){
            cout << "NO\n";
            continue;
        }
        int i = (ih + 1)/2;
        int j = (jh + 1)/2;
        if(ih%2 == 1) bg[{i, j}] = 1;
        else bd[{i, j}] = 1;
        if(bg.count({i, j}) && bd.count({i, j})){
            dne = 1;
            cout << "NO\n";
            continue;
        }
        if(ih%2 == 1){
            maxk[i] = min(maxk[i], j - 1);
            if(bitmn_mx(n - i + 1) > maxk[i]){
                dne = 1;
                cout << "NO\n";
                continue;
            }
            bitmx_upd(i, maxk[i]);
        }
        else{
            mink[i] = max(mink[i], j);
            if(bitmx_mn(i) < mink[i]){
                dne = 1;
                cout << "NO\n";
                continue;
            }
            bitmn_upd(n - i + 1, mink[i]);
        }
        cout << "YES\n";
    }
    return 0;
}

/*
2 1 2
4 4
1 1
*/