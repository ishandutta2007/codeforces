#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
       int n,m;
       cin>>n>>m;
       if((n<2)||(m<2))cout<<"1 1"<<endl;
        else cout<<2<<" "<<2<<endl;
    }
    return 0;
}