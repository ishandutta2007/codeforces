#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
#define exp fgfdgd
const ll DIM = 5E5+7;
const ll INF = 1E9;
vector<ll> V[DIM],R[DIM];

ll cnt[DIM],A[DIM];
ll n,m;
ll Check(){
    for(ll i = 1;i<=n;++i){
        cnt[i] = 0;
        for(ll j = 1;j<=m;++j){
            if (A[j]!=V[i][j]){
                ++cnt[i];
            }
        }
        if (cnt[i]>2)return 0;
    }
    return 1;
}
ll solve(ll pos){
    ll val = -1;
    for(ll i = 1;i<=n;++i){
        cnt[i] = 0;
        for(ll j = 1;j<=m;++j){
            if (j==pos)continue;
            if (A[j]!=V[i][j]){
                ++cnt[i];
            }
        }
        if (cnt[i]==2){
            if (val!=-1 && val!=V[i][pos])return 0;
            val = V[i][pos];
        }
        if (cnt[i]>2)return 0;
    }
    if (val==-1){
        A[pos] = V[1][pos];
    }
    else
        A[pos] = val;
    return 1;
}
int main()
{


    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n>>m;

    for(ll i = 1;i<=n;++i){
        V[i].resize(m+1);
        for(ll j = 1;j<=m;++j){
            cin>>V[i][j];
        }
    }
    for(ll i = 1;i<=m;++i){
        A[i] = V[1][i];
    }
    ll pos = 0;
    for(ll i = 1;i<=n;++i){
        for(ll j = 1;j<=m;++j){
            if (A[j]!=V[i][j]){
                ++cnt[i];
                R[i].push_back(j);
            }
        }
        if (R[i].size()>2){
            pos = i;
        }
    }
    if (pos!=0){
        if (R[pos].size()>4){
            cout<<"No\n";
            return 0;
        }
        if (R[pos].size()==3){
            for(ll a = 0;a<=2;++a){
                for(ll b = 0;b<=2;++b){
                    //if (a==b)continue;
                    A[R[pos][a]] = V[pos][R[pos][a]];
                    if (solve(R[pos][b])){
                        cout<<"Yes\n";
                        for(ll i = 1;i<=m;++i){
                            cout<<A[i]<<' ';
                        }
                        cout<<endl;
                        return 0;
                    }
                    A[R[pos][a]] = V[1][R[pos][a]];
                    A[R[pos][b]] = V[1][R[pos][b]];
                }
            }
        }
        ll sz = 1<<R[pos].size();
        for(ll mask = 1;mask<sz;++mask){
            if (__builtin_popcount(mask)>2)continue;
            vector<ll> vv;
            for(ll bit = 0;bit<R[pos].size();++bit){
                if (mask&(1<<bit))vv.push_back(R[pos][bit]);
            }
            for(ll to:vv){
                A[to] = V[pos][to];
            }
            if (Check()){
                cout<<"Yes\n";
                for(ll i = 1;i<=m;++i){
                    cout<<A[i]<<' ';
                }
                cout<<endl;
                return 0;
            }
            for(ll to:vv){
                A[to] = V[1][to];
            }
        }
        cout<<"No\n";
    }
    else{
        cout<<"Yes\n";
        for(ll i = 1;i<=m;++i){
            cout<<A[i]<<' ';
        }
        cout<<endl;
    }
    return 0;
}