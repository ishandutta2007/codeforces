#include <bits/stdc++.h>
using namespace std;

main(){
    int n, x;
    cin >> n;
    set <int> ans;
    for (int i = 0; i < n; ++i){
        cin >> x;
        if (x != 0){
            ans.insert(x);
        }
    }
    cout << ans.size();
    return 0;
}