#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int m;
    cin >> m;
    map<int,int>freq;
    set<int>s2;
    vector<set<pair<int,int>>>a(m+1);
    set<pair<int,pair<int,int>>>s;
    vector<vector<char>>ans(m+1);
    for(int i = 1; i<=m; i++){
        int n;
        cin >> n;
        ans[i].resize(n);
        for(int j = 0; j<n; j++){
            int x;
            cin >> x;
            ans[i][j] = 'X';
            s.insert({x,{i,j}});
            a[i].insert({x,j});
            freq[x]++;
            s2.insert(x);
        }
    }
    bool f = true;
    for(int nxt: s2){
        if(freq[nxt]%2==1){
            f = false;
        }
    }
    if(!f){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    while(s.size()){
        auto p = *s.begin();
        s.erase(p);
        int v = p.first; int i = p.second.first; int j = p.second.second;
        int old = i;
        a[i].erase({v,j});
        ans[i][j] = 'L';
        while(true){
            pair<int,pair<int,int>>temp = {v,{0,0}};
            auto p2 = *s.lower_bound(temp);
            s.erase(p2);
            int v2 = p2.first; int i2 = p2.second.first; int j2 = p2.second.second;
            a[i2].erase({v2,j2});
            ans[i2][j2] = 'R';
            if(old==i2)break;
            auto q = *a[i2].begin();

            i = i2; v = q.first; j = q.second;
            a[i].erase({v,j});
            s.erase({v,{i,j}});
            ans[i][j] = 'L';
        }
    }
    for(int i = 1; i<=m; i++){
        for(char nxt: ans[i]){
            cout << nxt;
        }
        cout << "\n";
    }
    return 0;
}