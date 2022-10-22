#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    int x = 1;
    for(int i = 0;i < n;i++){
        if(a[i] >= x){
            x++;
        }
    }
    cout << x - 1;

}