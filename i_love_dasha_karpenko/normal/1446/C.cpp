#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x1 dfds
#define y1 dsfdsfe
#define endl '\n'
const ll INF = 1E17;
const ll DIM = 2E5+7;
const ll LOG = 32;
ll T[DIM*(LOG+7)][2],po[LOG+7],A[DIM],ptr = 1;
ll cnt[DIM*(LOG+7)];
void add(ll v,ll level,ll pos){
    ++cnt[v];
    if (level==0)return;
    ll x = ((A[pos]&po[level])!=0ll);
    if (T[v][x]==0){
        T[v][x]=++ptr;
    }
    add(T[v][x],level-1,pos);
}
ll res = 0;
ll solve(ll v,ll level){
    if (v==0)return 0;
    if (level==0){
        return cnt[v];
    }

    ll c1 = solve(T[v][0],level-1);
    ll c2 = solve(T[v][1],level-1);
    ll d = min(c1-1,c2-1);
    d = max(0ll,d);
    res+=d;
    return c1+c2-d;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    po[0] = 1;
    for(ll i = 1;i<LOG+7;++i)po[i] = po[i-1]*2;
    ll n;
    cin>>n;
    for(ll i = 1;i<=n;++i){
        cin>>A[i];

        add(1,LOG,i);
    }

    solve(1,LOG);
    cout<<res<<endl;
    return 0;
}