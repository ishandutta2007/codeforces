#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    int i = 0, ans = 0;
    while(i < n){
        if (a[i] == 0) i ++;
        else{
            int x = a[i];
            for (int t = i; t < n; t ++){
                if (a[t] % x == 0){
                    a[t] = 0;
                }
            }
            ans ++;
        }
    }
    cout << ans;
    
    return 0;
}