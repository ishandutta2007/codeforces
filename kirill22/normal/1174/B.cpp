#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n;
    cin >> n;
    vector<int> a(n);
    int x = 0;
    for(int i = 0;i < n;i++){
        cin >> a[i];
        if(a[i] % 2 == 0){
            x++;
        }
    }
    int y = n - x;
    if(x != 0 && y != 0){
        sort(a.begin(),a.end());
        for(int i=0;i < n;i++){
            cout << a[i] << " ";
        }
        return 0;
    }
    for(int i=0;i<n;i++){
        cout<<a[i] << " ";
    }



}