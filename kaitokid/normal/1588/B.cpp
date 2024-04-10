#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
    ll n;
    cin>>n;
    cout<<"? "<<1<<" "<<n<<endl;
    fflush(stdout);
    ll tot;
    cin>>tot;
    ll l=1,r=n;
    while(l<r)
    {
        ll mid=(l+r)/2;
        cout<<"? "<<1<<" "<<mid<<endl;
        fflush(stdout);
        ll d;
        cin>>d;
        if(d==0)l=mid+1;
        else r=mid;
    }
    ll i=l-1;
    cout<<"? "<<i+1<<" "<<n<<endl;
    fflush(stdout);
    ll d;
    cin>>d;
    d=tot-d;
    ll j=i+d+1;
    cout<<"? "<<j<<" "<<n<<endl;
    fflush(stdout);
    cin>>tot;

    cout<<"? "<<j+1<<" "<<n<<endl;
    fflush(stdout);
    cin>>d;
    d=tot-d;
    ll k=j+d;
    cout<<"! "<<i<<" "<<j<<" "<<k<<endl;
    fflush(stdout);
    }
    return 0;
}