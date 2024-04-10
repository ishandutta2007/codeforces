#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x),end(x)
int main() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> b(n);
    int ans=0,total=0;
    for(auto& i : b) cin >> i,ans+=i;
    
    map<char,int> cnt;
    for(int i=0;i<n/2;++i) {
        if(s[i]==s[n-1-i]) {
            cnt[s[i]]++;
            total++;
            ans-=min(b[i],b[n-1-i]);
        }
    }
    pair<int,char> worst = {-1,'a'};
    for(auto [c,cc] : cnt) {
        worst = max(worst,{cc,c});
    }
    if(worst.first*2>total) {
        vector<int> v;
        for(int i=0;i<n/2;++i) {
            if(s[i]!=s[n-i-1] and s[i]!=worst.second and s[n-1-i]!=worst.second) {
                v.push_back(min(b[i],b[n-1-i]));
            }
        }
        sort(all(v));
        v.resize(worst.first*2-total);
        ans-=accumulate(all(v),0);
    }
    cout << ans;
    


}