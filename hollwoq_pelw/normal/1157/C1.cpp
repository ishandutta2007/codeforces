#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    string ans = "";
    int l = 0, r = n-1, cur = 0;
    while(l <= r){
        if (cur >= max(a[l],a[r])) break;
        if (a[r] > a[l]){
            if (cur < a[l]) {cur = a[l++]; ans += 'L';}
            else {cur = a[r--]; ans += 'R';}
        }else if (a[r] < a[l]){
            if (cur < a[r]) {cur = a[r--]; ans += 'R';}
            else {cur = a[l++]; ans += 'L';}
        }else{
            string x = ans;
            string y = ans;
            for (int i = l; i <= r; i++){
                if (i == l || (i > l && a[i] > a[i-1])) x += 'L';
            }
            for (int i = r; i >= l; i--){
                if (i == r || (i < r && a[i] > a[i+1])) y += 'R';
            }
            if(x.length() > y.length()) ans = x;
            else ans = y;
            break;
        }
    }
    cout << ans.length() << "\n" << ans;
    return 0;
}