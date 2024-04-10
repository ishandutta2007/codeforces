
#include <bits/stdc++.h>

using namespace std;
#define DIM 150007
#define INF 10E16
#define MAXN 400007
#define LG 25
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pairll;
typedef ll arr[DIM];
ll n,b,a;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("cowland.in","r",stdin);
    //freopen("cowland.out","w",stdout);

    cin>>n>>a>>b;
    ll mxb = b;
    int i,flag = 0;
    for (i = 1;i<=n;i++){
            ll x; cin>>x;
            if (x==1 && b!=mxb){
                if (a>0){
                    b++;
                    a--;
                }
                else if (b>0){
                    b--;
                }
                else{
                        flag = 1;
                    break;
                }
            }
            else{
                if (b>0){
                    b--;
                }
                else if (a>0){
                    a--;
                }
                else{
                        flag = 1;
                    break;
                }
            }
    }
    cout<<i-1<<endl;
}