#include <bits/stdc++.h>

using namespace std;
#define DIM 507
#define INF 1000000007
#define MAXN 10007
typedef int ll;
typedef pair<ll,ll> pairll;
typedef long double ld;
typedef ll arr[DIM];
struct painted{ll x1,x2,y1,y2;};
ll n,m;
ll A[DIM][DIM];
int main()
{
    //freopen("paintbarn.in","r",stdin);
    //freopen("paintbarn.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    ll x;
    for (int i = 1;i<=n;i++){
        for (int j = 1;j<=m;j++){
            cin>>A[i][j];
        }
    }
    ll a = 0;
    for (int i = 1;i<=n;i++){
        a^=A[i][1];
    }
    ll strok=1,pos=1,ff = 0;
    if (a==0){
        for (int i = 1;i<=n;i++){
            ll flag = 0;
            for (int j = 1;j<=m;j++){
                if (A[i][j]!=A[i][1]){
                    strok = i; pos = j;
                    flag = 1;
                    ff = 1;
                    break;
                }
            }
            if (flag)break;
        }
    }
    else ff = 1;
    if (ff == 0){

        cout<<"NIE"<<endl;
        return 0;
    }
    cout<<"TAK"<<endl;
    for (int i = 1;i<=n;i++){
        if (i==strok)cout<<pos<<' ';
        else{
            cout<<1<<' ';
        }
    }
}