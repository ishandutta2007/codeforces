#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
int a[102], b[102];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    ll ans = 0;
    ll cur;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            cur = 0;
            for(int k = 0; k < n; k++){
                if(k < i || k > j){
                    cur += a[k];
                } else {
                    cur += 1 - a[k];
                }
            }
            ans = max(ans, cur);
        }
    }
    cout << ans;
    return 0;
}