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
        vector<int>arr(n+1);
        vector<int>sorted;
        sorted.push_back(0);
        for(int i = 1; i<=n; i++){
            cin >> arr[i];
            sorted.push_back(arr[i]);
        }
        sort(sorted.begin(),sorted.end());
        for(int i = 1; i<=n; i++){
            arr[i] = lower_bound(sorted.begin(),sorted.end(),arr[i])-sorted.begin();
        }
        vector<int>freq(n+1);
        for(int i = 1; i<=n; i++){
            freq[arr[i]]++;
        }
        int a = 1; int b = 0;
        for(int i = 1; i<=n; i++){
            if(freq[i]==1)a++;
            else if(freq[i]>=2)b++;
        }
        cout << b+a/2 << "\n";
    }
    return 0;
}