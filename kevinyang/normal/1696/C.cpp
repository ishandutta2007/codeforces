#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        vector<int>a(n+1);
        for(int i = 1; i<=n; i++){
            cin >> a[i];
        }
        int k;
        cin >> k;
        vector<int>b(k+1);
        for(int i = 1; i<=k; i++){
            cin >> b[i];
        }
        vector<pair<int,int>>c;
        vector<pair<int,int>>d;
        c.push_back({1,1});
        d.push_back({1,1});
        for(int i = 1; i<=n; i++){
            int cnt = 0;
            int old = a[i];
            while(a[i]%m==0){
                cnt++;
                a[i]/=m;
            }
            if(c.back().first==a[i]){
                c[c.size()-1].second+=old/a[i];
            }
            else{
                c.push_back({a[i],old/a[i]});
            }
        }
        for(int i = 1; i<=k; i++){
            int cnt = 0;
            int old = b[i];
            while(b[i]%m==0){
                cnt++;
                b[i]/=m;
            }
            if(d.back().first==b[i]){
                d[d.size()-1].second+=old/b[i];
            }
            else{
                d.push_back({b[i],old/b[i]});
            }
        }
        if(c==d){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }
    return 0;
}