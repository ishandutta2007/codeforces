#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define x1 fgdfgdg
const ll DIM = 1E6+7;
const ll INF = 1E18;
const ll LOG = 25;
ll A[DIM],pref[DIM];
vector<pair<ll,ll> > T;
vector<ll> dp;
void add(ll v,ll pos,ll depth){
    if (depth==0)return;
    if (A[pos]==0 && T[v].first==-1){
        T.push_back({-1,-1});
        T[v].first = T.size()-1;
    }
    if (A[pos]==1 && T[v].second==-1){
        T.push_back({-1,-1});
        T[v].second = T.size()-1;
    }
    if (A[pos]==0){
        add(T[v].first,pos+1,depth-1);
    }
    else {
        add(T[v].second,pos+1,depth-1);
    }
}

void solve(ll v){
    //cout<<v<<' ';
    dp[v] = INF;

    if (T[v].first!=-1){
        solve(T[v].first);
        dp[v] = min(dp[v],dp[T[v].first]+1);
    }
    else{
        dp[v] = 1;
    }
    if (T[v].second!=-1){
        solve(T[v].second);
        dp[v] = min(dp[v],dp[T[v].second]+1);
    }
    else{
        dp[v] = 1;
    }
    //if (T[v].first==T[v].second)dp[v] = 0;
    dp[v] = min(dp[v],INF);
}
void print(ll v,ll left,ll depth){
    if (depth==0)return;
    if (T[v].second==-1){
        while(depth--){
            cout<<'0';
        }
        return;
    }
    else{
        if (dp[T[v].second]+1<=left){
            cout<<'0';
            print(T[v].second,left-1,depth-1);
        }
        else if (T[v].first!=-1) {
            cout << '1';
            print(T[v].first, left-1,depth-1);
        }
        else{
            cout<<'1';
            while(--depth)cout<<'0';
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll q;
    cin>>q;
    while(q--){
        ll n,k;
        cin>>n>>k;
        for(ll i = 1;i<=n;++i){
            char ch;
            cin>>ch;
            A[i] = ch-'0';
            pref[i] = pref[i-1];
            if (A[i]==0)pref[i]++;
        }

        ll base = k;
        k = min(k,LOG);
        T.push_back({-1,-1});
        for(ll i = base-k+1;i<=n-k+1;++i){
            ll sum = pref[i-1]-pref[max(0ll,i-(base-k)-1)];
            if (sum==0)
            add(0,i,k);
        }
        dp.resize(T.size());
        solve(0);
        if (dp[0]>k)cout<<"NO\n";
        else{
            cout<<"YES\n";
            for(ll i = 1;i<=base-k;++i)cout<<'0';
            print(0,k,k);
            cout<<endl;
        }
        //cout<<lg<<endl;
        T.clear();
        dp.clear();
    }
    return 0;
}