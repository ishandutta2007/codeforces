#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t){
        t--;
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a,a+n);
        bool bol = false;
        for (int i = 0; i < n-1; i++){
            if (a[i+1]-a[i] == 1){
                bol = true;
            }
        }
        if (bol) cout << 2 << endl;
        else cout << 1 << endl;
    }
    return 0;
    
}