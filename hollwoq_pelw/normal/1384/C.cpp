#include <bits/stdc++.h>
using namespace std;
int n, t, ans;
string a, b;
int P[26];

int find(int x){
    return x == P[x] ? x : find(P[x]);
}

void join(int x, int y){
    x = find(x);
    y = find(y);
    if (x == y) return;
    P[x] = P[y];
    ans --;
}

void solve(){
    cin >> n >> a >> b;
    for (int i = 0; i < 26; i++) P[i] = i;
    ans = 20;
    for (int i = 0; i < n; i++){
        if (a[i] > b[i]){
            cout << -1 << endl;
            return;
        }
        join(a[i]-'a', b[i]-'a');
    }
    cout << 20-ans << endl;
}

int main(){
    cin >> t; while(t--){
        solve();
    }
}