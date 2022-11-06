#include <bits/stdc++.h>
using namespace std;
#define int long long
int f(int x, int y, int z){
    int v = (x-y)*(x-y)+(x-z)*(x-z)+(y-z)*(y-z);
    return v;
}
int calc(vector<int>a, vector<int>b, vector<int>c){
    int ans = (int)9e18;
    for(int nxt: a){
        auto it = lower_bound(b.begin(),b.end(),nxt);
        if(it==b.end())break;
        int temp = *it;
        auto it2 = lower_bound(c.begin(),c.end(),temp);
        if(it2==c.end())break;
        int high = *it2;
        int mid = (nxt+high)/2;
        auto i = lower_bound(b.begin(),b.end(),mid);
        if(i!=b.begin()){
            i--;
            int v = *i;
            ans = min(ans,f(nxt,v,high));
            i++;
        }
        if(i!=b.end()){
            int v = *i;
            ans = min(ans,f(nxt,v,high));
        }
    }
    return ans;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int na,nb,nc;
        cin >> na >> nb >> nc;
        vector<int>a(na);
        vector<int>b(nb);
        vector<int>c(nc);
        for(int i = 0; i<na; i++){
            cin >> a[i];
        }
        for(int i = 0; i<nb; i++){
            cin >> b[i];
        }
        for(int i = 0; i<nc; i++){
            cin >> c[i];
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        sort(c.begin(),c.end());
        int ans = (int)9e18;
        ans = min(ans,calc(a,b,c));
        ans = min(ans,calc(a,c,b));
        ans = min(ans,calc(b,a,c));
        ans = min(ans,calc(b,c,a));
        ans = min(ans,calc(c,a,b));
        ans = min(ans,calc(c,b,a));
        cout << ans << "\n";
    }
    return 0;
}