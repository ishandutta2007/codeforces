#include <bits/stdc++.h>
using namespace std;

int n, m, c, ans;
int main(){
    cin >> n;
    int a[n+1];
    a[n] = -1;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        m = max(m,a[i]);
    }
    for (int i = 0; i <= n; i++){
        if (a[i] == m) ++c;
        else{
            ans = max(ans,c);
            c = 0;
        }
    }
    cout << ans;
    return 0;
}