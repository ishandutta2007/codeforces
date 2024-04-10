//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const ll DIM = 2E5+7;
const ll DIMM = sqrt(DIM)+100;
pair<ll,ll> A[DIM];
ll M[DIMM][DIMM];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll m,n;
        cin>>m>>n;
        for(ll i = 1;i<=n;++i) {
            cin >> A[i].first;
            A[i].second = i;
        }
        sort(A+1,A+1+n,greater<pair<ll,ll> >());
        ll len = 1;
        while(len*len-(len/2)*(len/2)<m || len*(len-len/2)<A[1].first)
            ++len;
        vector<pair<ll,ll> > v[3];
        for(ll i = 1;i<=len;++i){
            for(ll j = 1;j<=len;++j){
                if (i%2==0 && j%2==0)
                    continue;
                if (j%2 && i%2)
                    v[0].push_back({i,j});
                if (i%2 && j%2==0)
                    v[1].push_back({i,j});
                if (j%2 && i%2==0)
                    v[2].push_back({i,j});
            }
        }
        for(ll i = 1;i<=n;++i){
            ll cr = 1;
            if (v[cr].empty())++cr;

            while(A[i].first && !v[cr].empty()){
                --A[i].first;
                M[v[cr].back().first][v[cr].back().second] = A[i].second;
                v[cr].pop_back();
            }
        }
        for(ll i = 1;i<=n;++i){
            while(A[i].first){
                --A[i].first;
                M[v[0].back().first][v[0].back().second] = A[i].second;
                v[0].pop_back();
            }
        }
        cout<<len<<endl;
        for(ll i = 1;i<=len;++i) {
            for (ll j = 1;j<=len;++j) {
                cout << M[i][j] << ' ';
                M[i][j] = 0;
            }
            cout<<endl;
        }
    }


    return 0;
}