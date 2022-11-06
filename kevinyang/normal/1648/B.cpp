#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n,c;
        cin >> n >> c;
        vector<int>freq(2*c+5);
        vector<int>psa(2*c+5);
        for(int i = 0; i<n; i++){
            int x;
            cin >> x;
            freq[x]++;
        }
        for(int i = 1; i<=2*c; i++){
            psa[i] = psa[i-1]+freq[i];
        }
        bool f = true;
        if(freq[1]==0){
            f = false;
        }
        for(int i = 2; i<=c; i++){
            if(freq[i])continue;
            for(int j = 1; j*i<=c; j++){
                int sum = psa[j*i+j-1]-psa[j*i-1];
                if(sum>0&&freq[j]>0){
                    f = false;
                }
            }
        }
        if(f)cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}