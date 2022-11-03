#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main() {
    ios_base::sync_with_stdio(false);
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector<int> ans(n), a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        --a[i];
        if(a[i] == -1){
            ans[i] = 1 + min(n - 1, i + k) - max(0, i - k);
        }else{
            int rb = min(n - 1, a[i] + k);
            ans[i] = ans[a[i]] + min(n - 1, i + k) - max(i - k - 1, rb);
        }
    }
    for(int i = 0; i < n; ++i){
        if(i){
            cout << " ";
        }
        cout << ans[i];
    }
    cout << endl;



}