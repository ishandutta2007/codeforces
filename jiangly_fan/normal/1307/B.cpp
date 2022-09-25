#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100;
int a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, x, am = 0, ok = 0;
        cin >> n >> x;
        for(int a; n; n -= 1){
            cin >> a;
            am = max(a, am);
            if(a == x) ok = 1;
        }
        if(ok) cout << "1\n";
        else cout << max(2, (x + am - 1) / am) << "\n";
    }
    return 0;
}