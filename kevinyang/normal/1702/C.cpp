#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        vector<int>a(n+1);
        for(int i = 1; i<=n; i++){
            cin >> a[i];
        }
        map<int,int>r;
        map<int,int>l;
        for(int i = 1; i<=n; i++){
            r[a[i]] = i;
        }
        for(int i = n; i>=1; i--){
            l[a[i]] = i;
        }
        while(k--){
            int a,b;
            cin >> a >> b;
            if(l[a]<=r[b]&&l[a]&&l[b]){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
    }
    return 0;
}