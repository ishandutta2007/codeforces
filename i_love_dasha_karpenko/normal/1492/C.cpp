#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
#define exp fgfdgd
const ll DIM = 2E5+7;
const ll INF = 1E9;
ll A[DIM],B[DIM],mi[DIM],mx[DIM];
ll gi(char ch){
    return ch-'a'+1;
}
const ll base = 26;
vector<ll> V[DIM];
int main()
{


    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m;
    cin>>m>>n;
    for(ll i = 1;i<=m;++i){
        char ch;
        cin>>ch;
        B[i] = gi(ch);
         V[B[i]].push_back(i);
    }
    for(ll i = 1;i<=n;++i){
        char ch;
        cin>>ch;
        A[i] = gi(ch);

    }
    for(ll i = 1;i<=base;++i){
        reverse(V[i].begin(),V[i].end());
    }
    for(ll i = 1;i<=n;++i){
        while(V[A[i]].back()<=mi[i-1])V[A[i]].pop_back();
        mi[i] = V[A[i]].back();
        V[A[i]].pop_back();
    }
    for(ll i = 1;i<=base;++i){
        V[i].clear();
    }
    for(ll i = 1;i<=m;++i){
        V[B[i]].push_back(i);
    }
    mx[n+1] = INF;
    for(ll i = n;i>=1;--i){
        while(V[A[i]].back()>=mx[i+1])
            V[A[i]].pop_back();
        mx[i] = V[A[i]].back();
        V[A[i]].pop_back();
    }
    ll res = 0;
    for(ll i = 1;i<n;++i){
        res = max(res,mx[i+1]-mi[i]);
    }
    cout<<res<<endl;
    return 0;
}