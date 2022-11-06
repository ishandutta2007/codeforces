#include <bits/stdc++.h>
using namespace std;
#define int long long
struct op{
    int i,j,d;
};
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pair<int,int>>arr(n+1);
    vector<pair<int,int>>arr2(n+1);
    for(int i = 1; i<=n; i++){
        int x;
        cin >> x;
        arr[i] = {x,i};
    }
    for(int i = 1; i<=n; i++){
        int x;
        cin >> x;
        arr2[i] = {x,i};
    }
    sort(arr.begin(),arr.end());
    sort(arr2.begin(),arr2.end());
    vector<int>a(n+1);
    vector<int>b(n+1);
    vector<int>ai(n+1);
    vector<int>bi(n+1);
    for(int i = 1; i<=n; i++){
        a[i] = arr[i].first;
        ai[i] = arr[i].second;
    }
    for(int i = 1; i<=n; i++){
        b[i] = arr2[i].first;
        bi[i] = arr2[i].second;
    }
    vector<int>psa(n+1);
    vector<int>psa2(n+1);
    for(int i = 1; i<=n; i++){
        psa[i] = psa[i-1]+a[i];
        psa2[i] = psa2[i-1]+b[i];
    }
    vector<int>left(n+1);
    vector<int>right(n+1);
    for(int i = 1; i<=n; i++){
        if(a[i]>b[i]){
            left[i] = 1;
        }
        if(b[i]>a[i]){
            right[i] = 1;
        }
    }
    set<pair<pair<int,int>,int>>s;
    int idx = 0;
    if(psa[n]!=psa2[n]){
        cout << "NO\n";
        return 0;
    }
    vector<op>ans;
    for(int i = 1; i<=n; i++){
        if(right[i]){
            s.insert({{a[i],b[i]},ai[i]});
        }
        else if(left[i]){
            int rq = a[i]-b[i];
            while(rq>0){
                if(s.size()==0){
                    cout << "NO\n";
                    return 0;
                }
                pair<pair<int,int>,int>p = *s.begin();
                int aa = p.first.first; int bb = p.first.second; int idx = p.second;
                s.erase(s.begin());
                if(aa+1>=a[i]){
                    cout << "NO\n";
                    return 0;
                }
                int mn = min({bb-aa,rq,(a[i]-aa)/2});
                aa+=mn;
                rq-=mn;
                ans.push_back({idx,ai[i],mn});
                if(aa<bb){
                    s.insert({{aa,bb},idx});
                }
            }
        }
    }
    assert(ans.size()<=5*n);
    cout << "YES\n";
    cout << ans.size() << "\n";
    for(auto nxt: ans){
        cout << nxt.i << " " << nxt.j << " " << nxt.d << "\n";
    }
    return 0;
}