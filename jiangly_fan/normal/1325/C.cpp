#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100000;
int u[maxn], v[maxn], d[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1; i < n; i += 1){
        cin >> u[i] >> v[i];
        d[u[i]] += 1;
        d[v[i]] += 1;
    }
    if(count(d + 1, d + n + 1, 1) == 2)
        for(int i = 0; i < n - 1; i += 1) cout << i << "\n";
    else{
        int x = 0, y = 3;
        for(int i = 1; i < n; i += 1) if(d[u[i]] == 1 or d[v[i]] == 1){
            if(x <= 2) cout << x ++ << "\n";
            else cout << y ++ << "\n";
        }
        else cout << y ++ << "\n";
    }
    return 0;
}