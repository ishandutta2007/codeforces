//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define x1 dfgfg
#define y1 dfgdfg
const ll DIM = 500+7;
const ll INF = 1E9;
ll A[DIM][DIM];
void solve(){
    ll n,m;
    cin>>n>>m;
    for(ll i = 1;i<=n;++i){
        for(ll j = 1;j<=m;++j){
            char ch;
            cin>>ch;
            if (ch=='X')A[i][j] = 1;
            else A[i][j] = 0;
        }
    }
    ll start = 1;
    if ((n-start)%3==2)++start;
    for(ll i = start;i<=n;i+=3){
        ll flag = 0,f = 0,f1 = 0,ch = 0;
        for(ll j = 1;j<=m;++j){
            A[i][j] = 1;
            if (flag==0 && A[i+2][j] && !A[i+1][j]){
                A[i+1][j] = 1;
                flag = 1;
            }
            if (A[i+1][j])f = 1;
            if (A[i+2][j])f1 = 1;
        }
        if (flag)continue;
        if (f){
            for(ll j = 1;j<=m;++j){
                if (A[i+1][j]){
                    if (i+2<=n)
                    A[i+2][j] = 1;
                    break;
                }
            }
        }
        else{
            if (i+2<=n)
            A[i+1][1] = A[i+2][1] = 1;
        }
    }
    for(ll i = 1;i<=n;++i){
        for(ll j = 1;j<=m;++j){
            if (A[i][j])cout<<'X';
            else cout<<'.';
            A[i][j] = 0;
        }
        cout<<endl;

    }

    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;

    while(t--)
        solve();
    return 0;
}