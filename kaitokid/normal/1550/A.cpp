#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll s;
        ll x=0,d=1,sum=0;
        cin>>s;
        while(sum<s)
        {
            sum+=d;
            x++;
            d+=2;
        }
        cout<<x<<endl;
    }
    return 0;
}