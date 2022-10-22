#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin >> n;
    int a[n], s = 0;
    for (int i = 0; i < n; i ++){
        cin >> a[i];
        s += a[i];
    }
    sort(a,a+n);
    int k = 0, t = 0;
    for (int i = n-1; i >= 0; i --){
        if (k <= s/2){
            k += a[i];
            t ++;
        }else {
            break;
        }
    }
    cout << t;
}