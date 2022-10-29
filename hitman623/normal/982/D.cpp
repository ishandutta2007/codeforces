#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,a[100005],len[100005],cnt=0,any;
mi mp;
set<pii> s;
stack<int> stk;
void add(int l,int r){
    if(l<=r){
        s.insert({l,r});
        cnt++;
        len[r-l+1]++;
        stk.push(r-l+1);
        any=r-l+1;
    }
}
void solve(){
    cin>>n;
    rep(i,0,n){
        cin>>a[i];
        mp[a[i]]=i;
    }
    sort(a,a+n);
    reverse(a,a+n);
    int ans=a[n-1]+1,mx=1;
    add(0,n-1);
    rep(i,0,n-1){
        pii q={mp[a[i]],n};
        auto d=s.upper_bound(q);
        d--;
        auto h=*d;
        s.erase(d);
        add(h.x,mp[a[i]]-1);
        add(mp[a[i]]+1,h.y);
        len[h.y-h.x+1]--;
        cnt--;
        while(len[any]==0){
            stk.pop();
            any=stk.top();
        }
        if(len[any]==cnt){
            if(mx<=cnt){
                mx=cnt;
                ans=a[i+1]+1;
            }
        }
    }
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}