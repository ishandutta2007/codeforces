#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main() {
    ios_base::sync_with_stdio(false);
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    int n, c;
    cin >> n >> c;
    vector<int> t(n);
    int ans = 0;
    for(int i = 0; i < n; ++i){
        cin >> t[i];
        if(i && t[i] - t[i - 1] > c){
            ans = 1;
        }else{
            ++ans;
        }
    }
    cout << ans << endl;
}