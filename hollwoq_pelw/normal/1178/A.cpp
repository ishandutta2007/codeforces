#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int s=0,k=0;
    cin >> n;
    int a[n];
    vector<int> ans;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (i == 0 || a[i]*2 <= a[0]){
            ans.push_back(i+1);
            s += a[i];
        }
        k += a[i];
    }
    //cout << s << ' ' << k << endl;
    if (k >= 2*s) return cout << "0", 0;
    else{
        cout << ans.size() << endl;
        for (auto k: ans) cout << k << ' ';
    }
    return 0;
}