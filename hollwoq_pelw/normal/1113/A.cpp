#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,v;
    cin >> n >> v;
    int ans = 0, cap = 0;
    for(int i = 1; i < n; i++){
        //cout << ans << ' ' << cap << endl;
        ans += min(n-i-cap, v-cap)*i;
        cap += min(n-i-cap, v-cap) - 1;
    }
    cout << ans;
    return 0;
}