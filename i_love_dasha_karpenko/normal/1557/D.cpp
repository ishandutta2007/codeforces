//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int N = 3E5+7;
vector<pair<int,int> > V[N];
const int INF = 1E9;
int dp[N],P[N],vis[N];
set<pair<pair<int,int>,int> > S;
int get(int l,int r){
    auto cur = S.lower_bound({{l,INF},INF});
    if (cur!=S.begin())
        cur = prev(cur);
    int ret = 0;
    while(cur!=S.end()){
        if (cur->first.first>r)
            break;
        if (cur->first.second>=l) {
            int val = cur->second;
            if (dp[val] > dp[ret])
                ret = val;
        }
        cur = next(cur);
    }

    return ret;
}
void update(int l,int r,int i){
    auto cur = S.lower_bound({{l,INF},INF});
    if (cur!=S.begin()){
        pair<pair<int,int>,int> val = *prev(cur);
        if (val.first.first<=l && l<=val.first.second) {
            S.erase(prev(cur));
            pair<pair<int,int>,int> val1 = val,val2 = val;
            val1.first.second = l-1; val2.first.first = l;

            if (val1.first.first <= val1.first.second)
                S.insert(val1);

            if (val2.first.first <= val2.first.second)
                S.insert(val2);
        }
    }
    //cur = S.lower_bound({{l,r},i});
    cur = S.lower_bound({{r,INF},INF});
    if (cur!=S.begin()){
        cur = prev(cur);
        pair<pair<int,int>,int> val = *cur;
        if (val.first.first<=r && r<=val.first.second) {
            S.erase(cur);
            pair<pair<int,int>,int> val1 = val,val2 = val;
            val1.first.second = r; val2.first.first = r+1;

            if (val1.first.first <= val1.first.second)
                S.insert(val1);

            if (val2.first.first <= val2.first.second)
                S.insert(val2);
        }
    }
    cur = S.lower_bound({{l,0},0});
    while(cur!=S.end()){
        if (cur->first.second>r)
            break;
        auto was = cur;
        cur = next(cur);
        S.erase(was);
    }
    //S.insert({{l,r},i});

    S.insert({{l,r},i});
}
void solve(){

    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=m;++i){
        int pos,l,r;
        cin>>pos>>l>>r;
        V[pos].push_back({l,r});
    }
    int finish = 0;
    for(int i = 1;i<=n;++i){
        dp[i] = 1;
        P[i] = i;
        for(auto to:V[i]){
            int par = get(to.first,to.second);
            if (dp[par]+1>dp[i]){
                dp[i] = dp[par]+1;
                P[i] = par;
            }
        }
        for(auto to:V[i])
            update(to.first,to.second,i);
        if (dp[i]>dp[finish])
            finish = i;
    }
    int cnt = n;
    while(1){
        vis[finish] = 1;
        --cnt;
        if (finish==P[finish])
            break;
        finish = P[finish];
    }
    cout<<cnt<<endl;
    for(int i = 1;i<=n;++i)
        if (!vis[i]) {
            cout << i << ' ';
            --cnt;
        }
    if (cnt)
        n/=0;
    cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    t = 1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}