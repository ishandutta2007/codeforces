#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 307;
ll A[DIM][DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll cnt[2][3];
        memset(cnt,0,sizeof(cnt));
        ll ct = 0;
        for(ll i = 1;i<=n;++i){
            for(ll j = 1;j<=n;++j){
                char ch;
                cin>>ch;
                if (ch=='.')A[i][j] = 0;
                else if (ch=='O')A[i][j] = 1;
                else A[i][j] = 2;
                if (A[i][j]==0)continue;
                ++ct;
                cnt[A[i][j]-1][(i+j)%3]++;
            }
        }
        ll flag = 0;
        for(ll i = 0;i<3;++i){
            for(ll j = 0;j<3;++j){
                if (i==j)continue;
                if (cnt[0][i]+cnt[1][j]<=ct/3){
                    for(ll a = 1;a<=n;++a){
                        for(ll b = 1;b<=n;++b){
                            if (A[a][b]==1 && (a+b)%3==i)A[a][b] = 2;
                            else if (A[a][b]==2 && (a+b)%3==j)A[a][b] = 1;
                        }
                    }
                }
                else continue;
                flag = 1;
                break;
            }
            if (flag)break;
        }
        for(ll i = 1;i<=n;++i){
            for(ll j = 1;j<=n;++j){
                if (A[i][j]==0)cout<<'.';
                if (A[i][j]==1)cout<<'O';
                if (A[i][j]==2)cout<<'X';
            }
            cout<<endl;
        }
    }

    return 0;
}