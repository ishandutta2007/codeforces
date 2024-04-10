#include <bits/stdc++.h>
using namespace std;
#define DIM 107
typedef long long ll;
typedef ll arr[DIM];
ll n,r = 0;
arr A;
int main() {

    //freopen("input.txt","r",stdin);
    //freopen("dishes.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n;
    ll x;
    for (ll i = 1;i<=n;i++){
        cin>>A[i];
        if (i==1)continue;
        if (A[i]+A[i-1]==5){
            cout<<"Infinite"<<endl;
            return 0;
        }
        if (A[i]!=1){
            r+=A[i]+1;
        }
        else{
            r+=A[i-1]+1;
        }
        if (A[i]==2 && A[i-2]==3)r--;
    }
    cout<<"Finite"<<endl<<r<<endl;
}