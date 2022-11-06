#include <bits/stdc++.h>
using namespace std;
#define int long long
int f(vector<pair<int,int>>a){
    if(a.size()==0)return 0;
    int l = a[0].first; int r = 0;
    for(pair<int,int>nxt: a){
        r = max(r,nxt.second);
    }
    int ans = r-l+1;
    int cnt = 0;
    int mx = 0;
    for(int i = 0; i<a.size(); i++){
        if(i+1==a.size()||a[i+1].first>mx){
            mx = max(mx,a[i].second);
            cnt++;
        }
    }
    return max(ans-cnt-1,0LL);
}
bool comp(pair<int,int>a, pair<int,int>b){
    return a.second<b.second;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int>arr(n+1);
    vector<int>left(n+1);
    vector<int>right(n+1);
    for(int i = 1; i<=n; i++){
        cin >> arr[i];
        right[arr[i]] = i;
    }
    for(int i = n; i>=1; i--){
        left[arr[i]] = i;
    }
    int ans = 0;
    vector<pair<int,int>>vals;
    set<int>s;
    for(int i = 1; i<=n; i++){
        if(left[arr[i]]==right[arr[i]]){
            if(s.size()){
                continue;
            }
        }
        if(left[arr[i]]==i){
            if(s.size()&&(*--s.end())>right[arr[i]]){
                continue;
            }
            s.insert(right[arr[i]]);
            vals.push_back({left[arr[i]],right[arr[i]]});
        }
        if(right[arr[i]]==i){
            if(s.find(i)!=s.end()){
                s.erase(i);
            }
        }
    }
    
    sort(vals.begin(),vals.end(),comp);
    s.clear();
    int mx = 0;
    vector<pair<int,int>>vec;
    if(vals.size()){
        for(pair<int,int>nxt: vals){
            if(nxt.first<mx){
                vec.push_back(nxt);
                mx = max(mx,nxt.second);
            }
            else{
                mx = max(mx,nxt.second);
                ans+=f(vec);
                vec.clear();
                vec.push_back(nxt);
                //cout << ans << "\n";
            }
        }
    }
    ans+=f(vec);
    cout << ans << "\n";
    return 0;
}