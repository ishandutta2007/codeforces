#include <bits/stdc++.h>
using namespace std;

map <pair <int, int>, bool> exist;
int col[100005];
bool ima[100005];
int ukup[100005];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> col[i];
        ima[col[i]] = 1;
        exist[{col[i], col[i]}] = 1;
    }
    int a, b;
    while(m--){
        cin >> a >> b;
        if(!exist[{col[a], col[b]}]){
            ukup[col[a]]++;
            ukup[col[b]]++;
            exist[{col[a], col[b]}] = 1;
            exist[{col[b], col[a]}] = 1;
        }
    }
    int maxcol = 0;
    for(int i=1; i<=100000; i++){
        maxcol = max(maxcol, ukup[i]);
    }
    for(int i=1; i<=100000; i++){
        if(maxcol == ukup[i] && ima[i]){cout << i; return 0;}
    }
    return 0;
}