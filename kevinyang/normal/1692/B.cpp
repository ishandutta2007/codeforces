#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>freq(1e4+5);
        for(int i = 0; i<n; i++){
            int x;
            cin >> x;
            freq[x]++;
        }
        int odd = 0;
        int even = 0;
        for(int i = 1; i<=10000; i++){
            if(freq[i]==0)continue;
            if(freq[i]%2==0)even++;
            else odd++;
        }
        cout << odd+even/2*2 << "\n";
    }
    return 0;
}