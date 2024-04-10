//#pragma GCC optimize("Ofast")
//#pragma GCC optimization("funroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int MOD = 1e9+7;
const int N = 2007;
pair<ll,int> A[N];
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int k;
    cin>>k;
    int n;
    cin>>n;
    vector<pair<int,int> > events;
    for(int i = 1;i<=n;++i){
        ll pos;
        string s;
        cin>>pos>>s;
        int col;
        if (s=="white")
            col = 0;
        if (s=="yellow")
            col = 1;
        if (s=="green")
            col = 2;
        if (s=="blue")
            col = 3;
        if (s=="red")
            col = 4;
        if (s=="orange")
            col = 5;
        ll x = pos;
        int depth = 0;
        while(x){
            ++depth;
            x = x>>1;
        }
        A[i] = {pos,col};
        events.push_back({depth,i});
    }
    sort(events.begin(),events.end());
    ll ans = 1;
    map<ll,ll [6]> M;
    while(!events.empty() && events.back().first==k){
        int pos = events.back().second;
        events.pop_back();
        ll ind = A[pos].first;
        int col = A[pos].second;
        memset(M[ind],0,sizeof(M[ind]));
        M[ind][col] = 1;
    }
    for(int lev = k-1;lev>=1;--lev){
        set<ll> nn;
        map<ll,ll [6]> nM;
        for(auto [ind,dp]:M){
            nn.insert(ind>>1);
        }
        vector<ll> calc;
        while(!events.empty() && events.back().first==lev){
            int pos = events.back().second;
            events.pop_back();
            ll ind = A[pos].first;
            int col = A[pos].second;
            memset(nM[ind],0,sizeof(nM[ind]));
            nM[ind][col] = 1;
            nn.erase(ind);
            calc.push_back(ind);
        }
        for(ll to:nn) {
            calc.push_back(to);
            for(int cl = 0;cl<6;++cl)
                nM[to][cl] = 1;
        }
        for(auto ind:calc){
            for(int col = 0;col<6;++col){
                ll s1 = 0,s2 = 0;
                for(int cl = 0;cl<6;++cl){
                    if ((col^cl)<2)
                        continue;
                    if (M.count((ind<<1)))
                        s1 = (s1 + M[(ind<<1)][cl])%MOD;
                    else s1 = (s1+ans)%MOD;
                    if (M.count((ind<<1)+1))
                        s2 = (s2 + M[(ind<<1)+1][cl])%MOD;
                    else s2 = (s2+ans)%MOD;
                }
                nM[ind][col] = nM[ind][col]*s1*s2%MOD;
            }
        }
        swap(M,nM);
        ans = (ans*ans)%MOD*16%MOD;
    }
    ll res = 0;
    for(int col = 0;col<6;++col){
        res = (res+M[1][col])%MOD;
    }
    cout<<res<<endl;
    return 0;
}