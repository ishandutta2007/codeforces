#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 307;
ll A[DIM][DIM],B[DIM][DIM];
ll F1(ll x,ll y){
    if (x>2 && A[x-2][y] && A[x-1][y])return 1;
    if (A[x-1][y] && A[x+1][y])return 1;
    if (A[x+1][y] && A[x+2][y])return 1;
    return 0;
}
ll F2(ll x,ll y){
    if (y>2 && A[x][y-2] && A[x][y-1])return 1;
    if (A[x][y-1] && A[x][y+1])return 1;
    if (A[x][y+1] && A[x][y+2])return 1;
    return 0;
}

int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll ct = 0;
        for(ll i = 1;i<=n;++i){
            for(ll j = 1;j<=n;++j){

                char ch;
                cin>>ch;
                if (ch=='X'){
                    A[i][j] = B[i][j] = 1;
                    ++ct;
                }
            }
        }
        ll cnt[3];
        cnt[0] = cnt[1] = cnt[2] = 0;
        for(ll i = 1;i<=n;++i){
            for(ll j = 1;j<=n;++j){
                if (A[i][j]==0)continue;
                cnt[(i+j)%3]++;
            }
        }
        ll mi = 0;
        for(ll j = 1;j<=2;++j){
            if (cnt[j]<cnt[mi])mi = j;
        }
        ll ctt = 0;
        for(ll i = 1;i<=n;++i){
            for(ll j = 1;j<=n;++j){
                if ((i+j)%3==mi)A[i][j] = 0;
                if (A[i][j])cout<<'X';
                else if (A[i][j]==0 && B[i][j]){
                    cout<<'O';
                    ++ctt;
                }
                else cout<<'.';
                A[i][j] = B[i][j] = 0;
            }
            cout<<endl;
        }

        //cout<<ct<<' '<<ctt<<endl;
    }
    return 0;
}