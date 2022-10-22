#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n;
    cin >> n;
    vector<int> a(2 * n);
    n *= 2;
    for(int i =0;i < n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    int x = 0,y = 0;
    for(int i =0;i < n;i++){
        if(i < n/2){
            x+=a[i];
        }
        else{
            y+=a[i];
        }
    }
    if(x==y){
        cout << -1;
        return 0;
    }
    for(int i=0;i < n;i++){
        cout << a[i] << " ";
    }


}