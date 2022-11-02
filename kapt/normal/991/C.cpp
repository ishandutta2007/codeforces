#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int n;

bool check(int k){
    int n1 = n;
    int ans = 0;
    while (n1 > 0){
        ans += min(n1, k);
        n1 -= min(n1, k);
        n1 -= n1 / 10;
    }
    return ans * 2 >= n;
}

main(){
    cin >> n;
    int l = 0, r = n + 1;
    while (r - l > 1){
        int m = (l + r) / 2;
        // cout << l << " " << r << endl;
        if (check(m)){
            r = m;
        }
        else{
            l = m;
        }
    }
    cout << r;
    return 0;
}