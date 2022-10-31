//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define x1 dfgfg
#define y1 dfgdfg


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll x;
        cin>>x;
        ll cur = 1,res = 0;
        while(x){
            if (x<cur*(cur+1)/2)break;
            x-=cur*(cur+1)/2;
            ++res;
            cur = cur*2+1;
        }
        cout<<res<<endl;
    }
    return 0;
}