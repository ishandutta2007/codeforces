#include <bits/stdc++.h>
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
        ll a[4];
        cin>>a[0]>>a[1]>>a[2];
        sort(a,a+3);
        if(a[2]==a[0]+a[1]){cout<<"YES"<<endl;continue;}
        if(a[0]==a[1] && a[2]%2==0){cout<<"YES"<<endl;continue;}

        if(a[1]==a[2] && a[0]%2==0){cout<<"YES"<<endl;continue;}

        else cout<<"NO"<<endl;
    }
    return 0;
}