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
        set<int>s;
        for(int i = 1; i<=n; i++){
            s.insert(i);
        }
        for(int i = 0; i<m; i++){
            int a,b,c;
            cin >> a >> b >> c;
            if(s.find(b)!=s.end()){
                s.erase(b);
            }
        }
        int v = *s.begin();
        for(int i = 1; i<=n; i++){
            if(i==v)continue;
            cout << i << " " << v << "\n";
        }
    }
    return 0;
}