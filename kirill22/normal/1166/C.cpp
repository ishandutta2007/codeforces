#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    int ans = 0;
    for(int i = 0;i < n;i++){
        cin >> a[i];
        a[i] = abs(a[i]);
    }
    vector<int> b;
    sort(a.begin(),a.end());
    b.push_back(a[0]);
    for(int i = 1;i < n;i++){
        int k = 0;
        int x = a[i];
        int y = (a[i] + 1) / 2;
        x *= 2;
        auto res1 = lower_bound(b.begin(),b.end(),y);
        auto res2 = lower_bound(b.begin(),b.end(),x);
        if(res2 == b.end()){
                ans += i -  (res1 - b.begin()) ;
        }
        else{
                ans += res2 -res1 + 1;
        }
        b.push_back(a[i]);

    }
    cout << ans;

}