#include <bits/stdc++.h>
using namespace std;
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        vector<int>a(n);
        for(int i = 0; i<n; i++){
            cin >> a[i];
        }
        vector<vector<char>>arr(n,vector<char>(m));
        for(int i = 0; i<n; i++){
            string s;
            cin >> s;
            for(int j = 0; j<m; j++){
                arr[i][j] = s[j];
            }
        }
        int ans = -(int)1e18; vector<int>perm(m);
        for(int i = 0; i<(1<<n); i++){
            vector<vector<int>>val(n,vector<int>(m));
            for(int j = 0; j<n; j++){
                for(int a = 0; a<m; a++){
                    if(arr[j][a]=='1'){
                        if(i&(1<<j)){
                            val[j][a] = 1;
                        }
                        else{
                            val[j][a] = -1;
                        }
                    }
                }
            }
            vector<int>sum(m);
            for(int j = 0; j<m; j++){
                for(int a = 0; a<n; a++){
                    sum[j]+=val[a][j];
                }
            }
            int total = 0;
            for(int j = 0; j<n; j++){
                if(i&(1<<j)){
                    total-=a[j];
                }
                else{
                    total+=a[j];
                }
            }
            vector<pair<int,int>>p(m);
            for(int j = 0; j<m; j++){
                p[j] = {sum[j],j};
            }
            sort(p.begin(),p.end());
            for(int j = 0; j<m; j++){
                total+=(j+1)*p[j].first;
            }
            if(total>ans){
                for(int j = 0; j<m; j++){
                    perm[p[j].second] = j+1;
                }
                ans = total;
            }
        }
        for(int j = 0; j<m; j++){
            cout << perm[j] << " ";
        }
        cout << "\n";
    }
    return 0;
}