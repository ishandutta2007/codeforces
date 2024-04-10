#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n;
    cin >> n;
    int ans = 0;
    vector<int> a(n);
    map<int,int> b;
    for(int i = 0;i < n;i++){
        cin >> a[i];
        vector<int> z;
        b[a[i]]++;
        for(auto c : b){
            z.push_back(c.second);
        }
        sort(z.begin(),z.end());
        if(z[0] == 1){
            bool f = true;
            for(int u = 1;u < z.size() - 1;u++){
                if(z[u] != z[u + 1]){
                    f = false;
                }
            }
            if(f){
                ans = i + 1;
            }
        }

        int m = z.size();
        z[m - 1]--;
        sort(z.begin(),z.end());
        if(z[0] == z[m - 1]){
            ans = i + 1;
        }

    }
    cout << ans;
}