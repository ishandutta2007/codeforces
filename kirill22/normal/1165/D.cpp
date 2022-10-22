#include <bits/stdc++.h>
using namespace std;
#define int long long
int fi(int x){
    map<int,int> a;
    for(int i = 2;i * i <= x;i++){
        while(x % i == 0){
            a[i]++;
            x /= i;
        }
    }
    if(x > 1){
        a[x]++;
    }
    int ans = 1;
    for(auto c : a){
        ans *= (c.second + 1);
    }
    return ans;
}
signed main() {
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0;i < n;i++){
            cin >> a[i];
        }
        bool f = true;
        sort(a.begin(),a.end());
        for(int i = 0;i < n;i++){
            if((a[n - 1] * a[0]) % a[i] != 0){
                cout << -1 << endl;
                f = false;
                break;
            }

        }
        if(!f){
            continue;
        }
        if(fi(a[n - 1] * a[0]) - 2 == n){
            cout << a[n - 1] * a[0] << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
}