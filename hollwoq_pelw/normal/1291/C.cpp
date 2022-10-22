#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n, m,k;
    cin >> t;
    while(t){
        t--;
        int a[3600];
        cin >> n >> m >> k;
        k = min(k, m-1);
        for (int i = 0; i < n; i ++) cin >> a[i];
        int res = -1;
        for (int x = 0; x <= k; x ++){
            int in = __INT_MAX__;
            for (int y = 0 ; y <= m-k-1 ; y++ ){
                in = min(in, max(a[x+y], a[n-m+x+y] ));
            }
            res = max(res, in);
        }
        cout << res << endl;
    }
    return 0;
}