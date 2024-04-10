#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const ll DIM = 500+7;
ll cnt[DIM][DIM],A[DIM][DIM],n,col[DIM][DIM];
ll Ch(ll i,ll j){
    if (i<1 || i>n || j<1 || j>n || i-j<0 || A[i][j])
        return 0;
    return 1;
}
queue<pair<ll,ll> > Q;
void Calc(ll i,ll j){
    if (i<1 || i>n || j<1 || j>n || i-j<0 || A[i][j]==0)return;
    ll prev = cnt[i][j];
    cnt[i][j] = Ch(i-1,j)+Ch(i+1,j)+Ch(i,j-1)+Ch(i,j+1);
    if (cnt[i][j]!=prev && cnt[i][j]==1 && A[i][j]>1)Q.push({i,j});
}
void Mod(ll i,ll j){
    Calc(i+1,j);
    Calc(i-1,j);
    Calc(i,j-1);
    Calc(i,j+1);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(ll i = 1;i<=n;++i){
        cin>>A[i][i];
        col[i][i] = A[i][i];
    }

    for(ll i = 1;i<=n;++i){
        for(ll j = 1;j<=n;++j){
            Calc(i,j);
        }
    }
    while(!Q.empty()){
        auto [x,y] = Q.front();
        Q.pop();
        ll cl = col[x][y];
        ll val = A[x][y];
        if (Ch(x-1,y))
            x--;
        else if (Ch(x+1,y))
            ++x;
        else if (Ch(x,y-1))
            --y;
        else
            ++y;
        A[x][y] = val-1;
        col[x][y] = cl;
        Calc(x,y);
        Mod(x,y);
    }
    for(ll i = 1;i<=n;++i){
        for(ll j = 1;j<=n;++j) {
            if (i-j<0)
                continue;
            if (col[i][j]==0){
                cout<<"-1\n";
                return 0;
            }
        }
    }
    for(ll i = 1;i<=n;++i){
        for(ll j = 1;j<=n;++j){
            if (i-j<0)
                continue;
            cout<<col[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}