#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    if(k > (n-1)/2){
        cout << "-1\n";
        return;
    }
    cout << "1 ";
    int x = 0;
    int i = 2;
    for(; x < k; i+=2){
        cout << i+1 << " " << i << " ";
        x++;
    }
    for(; i<=n; i++) cout << i << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}