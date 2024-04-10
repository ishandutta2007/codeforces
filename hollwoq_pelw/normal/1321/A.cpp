#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int r[n], b[n];
    for (int i = 0; i < n; i++) cin >> r[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    int cr = 0, cb = 0;
    for (int i = 0; i < n; i++){
        if (r[i] && !b[i]) cr++;
        if (!r[i] && b[i]) cb++;
    }
    if (!cr) cout << -1;
    else cout << cb/cr+1;
    return 0;
}