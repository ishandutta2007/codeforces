#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
int t;
cin>>t;
    while(t--)
    {
        ll a[3],m;
        cin>>a[0]>>a[1]>>a[2]>>m;
        sort(a,a+3);
        ll mx=a[0]+a[1]+a[2]-3;
        ll mn= a[2]-a[0]-a[1]-1;
        if(m>=mn&& m<=mx )cout<<"YES\n";
        else cout<<"NO\n";

    }


  return 0;
}