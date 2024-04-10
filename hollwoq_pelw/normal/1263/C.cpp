#include <bits/stdc++.h>
using namespace std;

int n;
set<int> s;
void solve(){
    cin >> n;
    s.clear();
    for (int a = 1; a <= sqrt(n); a ++){
        s.insert(n/a);
        s.insert(a);
    }
    cout << s.size()+1 << "\n" << 0;
    for (auto t: s) cout << ' ' << t;
    cout << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}