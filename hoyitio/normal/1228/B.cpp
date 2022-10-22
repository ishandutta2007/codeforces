#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9+7;
const int maxx = 1010;
int a[maxx][maxx];
int main()
{
    ll n , m , cnt = 0;
    int x;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        for(int j=1;j<=x;j++){
            a[i][j] = 1;
        }
        a[i][x+1] = -1;
    }

    int flag = 1;
    for(int i=1;i<=m;i++){
        cin>>x;
        for(int j=1;j<=x;j++){
            if(a[j][i] == -1){
                flag = 0;
                break;
            }
            a[j][i] = 1;
        }
        if(a[x+1][i] == 1){
            flag = 0;
        }
        a[x+1][i] = -1;
    }



    if(flag == 0){
        cout<<"0"<<endl;
        return 0;
    }

    int sign = 0;
    ll ans = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            //cout<<a[i][j]<<" ";
            if(a[i][j] == 0){
                sign = 1;
                ans *= 1ll*2;
                ans %= mod;
            }
        }
        //cout<<endl;
    }
    cout<<ans<<endl;
    return 0;
}