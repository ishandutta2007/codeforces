#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, s = 0, k;
        cin >> n >> m;
        for (int i = 0; i < n; i++){
            cin >> k;
            s += k;
        }
        cout << min(m, s) << endl;
    }
}