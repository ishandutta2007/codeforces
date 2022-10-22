#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int n, l[N], r[N], dp[N], t;

int main(){
    cin >> t; while(t--){
        cin >> n;
        for (int i = 0; i <= n; i++){
            l[i] = n + 1; r[i] = 0;
        }
        for (int i = 1; i <= n; i++){
            int x; cin >> x; 
            l[x] = min(l[x], i); 
            r[x] = max(r[x], i);
        }
        int ans = 0, tot = 0, lst = 0;
        for (int i = 1; i <= n; i++){
            if (r[i]){
                dp[i] = r[lst] < l[i] ? dp[lst] + 1 : 1;
                ans = max(dp[i], ans); lst = i; tot ++;
            }
        }
        cout << tot - ans << endl;
    }
}