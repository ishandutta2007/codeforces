#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int mod=998244353;
const int mod=1e9+7;
#define inf 0x3f3f3f3f
// #define DEBUG
inline void add(int &x,int y){x+=y;if(x>=mod)x-=mod;}
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
int main()
{
    #ifdef DEBUG
    freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    #endif
    // ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    vector<ll>a;
    a.push_back(0);
    a.push_back(2);
    a.push_back(6);
    int x=1,y=1,z=1;
    while(a.back()<1000000000)
    {
        a.emplace_back();
        if(x>y) swap(x,y);
        if(x>z) swap(x,z);
        int n=a.size()-1;
        a[n]=a[n-1]+(y+z)*2;
        ++x;
    }
    int t;
    cin>>t;
    while(t--)
    {
        int n;cin>>n;
        cout<<lower_bound(a.begin(),a.end(),n)-a.begin()+1<<'\n';
    }
}