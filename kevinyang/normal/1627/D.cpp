#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int>arr(n+1);
    for(int i = 1; i<=n; i++){
        cin >> arr[i];
    }
    vector<int>freq((int)1e6+6);
    for(int i = 1; i<=n; i++){
        freq[arr[i]] = 1;
    }
    int cnt = 0;
    for(int i = (int)1e6; i>=1; i--){
        int v = 0;
        for(int j = i; j<=(int)1e6; j+=i){
            if(freq[j])v = __gcd(v,j);
        }
        if(v==i){
            cnt++;
        }
    }
    cout << cnt-n << "\n";
    return 0;
}