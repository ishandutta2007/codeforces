#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        int a[n],b[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        sort(a,a+n);
        sort(b,b+n);
        for (auto s:a)cout << s << ' ';
        cout << endl;
        for (auto s:b)cout << s << ' ';
        cout << endl;
        
    }
    return 0;
}