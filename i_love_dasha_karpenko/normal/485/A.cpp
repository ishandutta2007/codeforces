//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ull,ll> upp;

#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 1E5+7;
ll vis[DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll x,m;
    cin>>x>>m;
    x%=m;
    while(1){
        if (vis[x]==1){
            cout<<"No\n";
            return 0;
        }
        vis[x] = 1;
        x = (x*2)%m;
        if (x==0){
            cout<<"Yes\n";
            return 0;
        }
    }
    return 0;
}