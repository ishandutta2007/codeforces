#include <bits/stdc++.h>

using namespace std;
#define DIM 10008
#define INF 10E16
#define MAXN 10000007
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pairll;
typedef ll arr[DIM];

int main()
{
    //freopen("input.txt","r",stdin);
    ll n,m,x,r1 = 0,r2 = 0,a1 = 0,a2 = 0;
    cin>>n>>m;
    for (int i = 1;i<=n;i++){
        cin>>x;
        if (x%2==0)r1++;
        else r2++;
    }
    for (int i = 1;i<=m;i++){
        cin>>x;
        if (x%2==0)a1++;
        else a2++;
    }
    cout<<min(r1,a2)+min(r2,a1)<<endl;
}