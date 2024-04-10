#include <bits/stdc++.h>

using namespace std;
#define INF 1000000000000000007
#define DIM 107
typedef long long ll;
typedef pair<ll,ll> pairll;
typedef ll arr[DIM];

ll n,h,m;
arr A;
int main()
{
    cin>>n>>h>>m;
    for (int i = 1;i<=n;i++)A[i]=h;
    for (int i = 1;i<=m;i++){
        ll x,r,l;
        cin>>l>>r>>x;
        for (int j = l;j<=r;j++)A[j]=min(A[j],x);
    }
    ll res = 0;
    for (int i = 1;i<=n;i++)res+=A[i]*A[i];
    cout<<res<<endl;
}