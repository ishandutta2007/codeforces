
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ld eps=1e-12;
const int N=500010;
const ll mod=998244353;
#define ADD(a,b) a+=b;if (a>=mod) a-=mod
#define endl '\n'
int a[N];
int dp[N];
int L[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    vector<pair<int,pair<int,int> > >v;
    for (int i=1;i<=n;i++){
        for (auto &cur:v){
            cur.first=__gcd(cur.first,a[i]);
        }
        v.push_back({a[i],{i,i}});
        vector<pair<int,pair<int,int> > >u;
        for (int j=0;j<v.size();j++){
            int t=j;
            while (t<v.size() && v[t].first==v[j].first) t++;
            t--;
            u.push_back({v[j].first,{v[j].second.first,v[t].second.second}});
            j=t;
        }
        v=u;
        L[i]=L[i-1];
        for (auto cur:v){
            int l=cur.second.first;
            int r=cur.second.second;
            int pos=i-cur.first+1;
            if (pos>=l && pos<=r){
//                if (i==2) cout<<pos<<" "<<l<<" "<<r<<endl;
                L[i]=max(L[i],pos);
            }
        }
    }
//    for (int i=1;i<=n;i++) cout<<L[i]<<" ";
//    cout<<endl;
    dp[0]=0;

    for (int i=1;i<=n;i++){
        if (!L[i]) dp[i]=0;
        else dp[i]=dp[L[i]-1]+1;
    }

//
//
//
    for (int i=1;i<=n;i++) cout<<dp[i]<<" ";
    cout<<endl;


}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}

/**
5 1 1
1 4 5 2 3
2 1 3
**/