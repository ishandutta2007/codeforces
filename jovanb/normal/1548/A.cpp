#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int tren;

const int N = 200000;

set <int> graf[N+5];

int vazi(int v){
    return graf[v].empty() || *graf[v].rbegin() < v;
}

void dodaj(int a, int b){
    if(vazi(a)) tren--;
    if(vazi(b)) tren--;
    graf[a].insert(b);
    graf[b].insert(a);
    if(vazi(a)) tren++;
    if(vazi(b)) tren++;
}

void brisi(int a, int b){
    if(vazi(a)) tren--;
    if(vazi(b)) tren--;
    graf[a].erase(b);
    graf[b].erase(a);
    if(vazi(a)) tren++;
    if(vazi(b)) tren++;
}

void solve(){
    int n, m;
    cin >> n >> m;
    tren = n;
    for(int i=1; i<=n; i++) graf[i].clear();
    for(int i=1; i<=m; i++){
        int a, b;
        cin >> a >> b;
        dodaj(a, b);
    }
    int qrs;
    cin >> qrs;
    while(qrs--){
        int typ;
        cin >> typ;
        if(typ == 1){
            int a, b;
            cin >> a >> b;
            dodaj(a, b);
        }
        else if(typ == 2){
            int a, b;
            cin >> a >> b;
            brisi(a, b);
        }
        else cout << tren << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t = 1;
    while(t--) solve();
    return 0;
}