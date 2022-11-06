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
        int mn = (int)1e18;
        int mx = 0;
        int a = (int)1e18;
        int b = (int)1e18;
        int ab = (int)1e18;
        set<pair<int,int>>s;
        set<int>s2;
        for(int i = 0; i<n; i++){
            int l,r,w;
            cin >> l >> r >> w;
            mn = min(mn,l);
            mx = max(mx,r);
            if(s.find({mn,mx})==s.end()){
                ab = (int)1e18;
            }
            if(s2.find(mn)==s2.end()){
                a = (int)1e18;
            }
            if(s2.find(mx)==s2.end()){
                b = (int)1e18;
            }
            s2.insert(l); s2.insert(r);
            s.insert({l,r});
            if(l==mn&&r==mx){
                ab = min(ab,w);
            }
            if(l==mn){
                a = min(a,w);
            }
            if(r==mx){
                b = min(b,w);
            }
            
            cout << min(ab,a+b) << "\n";
        }
        
    }
    return 0;
}