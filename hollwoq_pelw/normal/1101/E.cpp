#include <bits/stdc++.h>
using namespace std;
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int x = 0, y = 0;
    int q; cin >> q;
    while(q--){
        char s;
        int a, b;
        cin >> s >> a >> b;
        if (a > b) swap(a, b);
        if (s == '?'){
            if (x <= a && y <= b) cout << "YES\n";
            else cout << "NO\n";
        }else{
            x = max(x, a);
            y = max(y, b);
        }
    }
    return 0;
}