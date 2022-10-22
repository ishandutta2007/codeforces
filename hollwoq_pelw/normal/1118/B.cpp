#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    vector < ll > a(200100,0);
    ll n,ch=0,nech=0,ans=0;
    
    cin >>n;
    for ( int i = 1 ; i <= n ; i++ )
    {
        cin >> a[i];
        if (i%2==0) ch+=a[i];
        else nech+=a[i];
    }
    ll nechnow=0,chnow=0;
    for ( int i = 1 ; i <= n; i++ )
    {
        if (i%2==0)
        {
            ll x , y;
            x=chnow+nech-nechnow;
            y=ch+nech-x-a[i];
         //   cout << x << " " << y << endl;
            if (x == y) ans++;
        }
        if (i%2==1)
        {
            ll x , y;
            x=nechnow+ch-chnow;
            y=ch+nech-x-a[i];
         //   cout << x << " " << y << endl;
            if (x == y) ans++;
        }
    
    
    
        if (i %2==0) chnow+=a[i];
        else nechnow+=a[i];
    }
    cout << ans;
    
    return 0;
}