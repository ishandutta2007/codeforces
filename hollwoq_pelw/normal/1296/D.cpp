#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b,k,h;
    cin >> n >> a >> b >> k;
    
    int ans[n];
    
    for (int i = 0; i < n; i++){
        cin >> h;
        h%=(a+b);
        if (!h) h = a+b;
        ans[i] = h/a+(h%a>0)-1;
    }
    sort(ans, ans+n);
    int res = 0;
    for (int i = 0; i < n; i++){
        if (k >= ans[i]){
            k -= ans[i];
            res ++;
        }else{
            break;
        }
    }
    cout << res;
    
    return 0;
}