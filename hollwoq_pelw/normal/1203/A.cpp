#include <bits/stdc++.h>
using namespace std;
int main(){
    int q;
    cin >> q;
    while(q){
        q--;
        int n;
        cin >> n;
        int a[n];
        bool t = true;
        for (int i = 0; i < n; i++){
            cin >> a[i];
            if (i > 0){
                int x = abs(a[i]-a[i-1]);
                if (x != 1 && x != n-1) t = false;
            }
        }
        if (t) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}