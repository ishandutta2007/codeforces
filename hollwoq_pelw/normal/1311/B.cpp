#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,m,t;
    cin >> n >> m;
    set<int> p;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++){
        cin >> t;
        p.insert(t);
    }
    bool flag = true;
    while(flag){
        flag = false;
        for (int i = 0; i < n-1; i++){
            if (a[i] > a[i+1]){
                flag = true;
                if (!p.count(i+1)){
                    cout << "NO" << endl;
                    return;
                }else{
                    int k = a[i];
                    a[i] = a[i+1];
                    a[i+1] = k;
                }
            }
        }
    }
    //for (int i = 0; i < n; i++) 
    cout << "YES" << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}