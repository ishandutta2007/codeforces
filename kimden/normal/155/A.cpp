#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(false);
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    int n;
    cin >> n;
    int ans = 0;
    int a, mx, mn;
    for(int i = 0; i < n; i++){
        cin >> a;
        if(i){
            if(a < mn){
                mn = a;
                ans++;
            }
            if(a > mx){
                mx = a;
                ans++;
            }
        }else{
            mx = mn = a;
        }
    }
    cout << ans << endl;
    return 0;
}