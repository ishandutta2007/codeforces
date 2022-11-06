#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int>a;
    map<int,int>hm;
    for(int i = 0; i<20; i++){
        a.push_back((1<<i));
        hm[(1<<i)] = i;    
    }
    while(n--){
        int x;
        cin >> x;
        if(x==0){
            cout << "0 ";
            continue;
        }
        int ans = (int)1e9;
        for(int i = 0; i<20; i++){
            int v = x+i;
            int cnt = 15;
            while(v%2==0){
                v/=2;
                cnt--;
            }
            ans = min(ans,cnt+i);
        }
        cout << ans << " ";
    }
    cout << "\n";
    return 0;
}