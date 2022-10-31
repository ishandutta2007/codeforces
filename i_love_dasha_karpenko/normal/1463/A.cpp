#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
#define po(x) (1ll<<x)

int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll a[3];
        cin>>a[0]>>a[1]>>a[2];
        sort(a,a+3);
        ll dif = a[1]-a[0];
        ll g = dif/6;
        a[2]-=g;
        a[1]-=g;
        a[0]-=g;
        a[1]-=dif;
        ll tonxt = dif%6;
        dif = a[2]-a[1];
        g = (dif+tonxt)/6;
        a[2]-=g;
        a[1]-=g;
        a[0]-=g;
        a[2]-=dif;
        if (a[0]<0 || a[1]<0 || a[2]<0){
            cout<<"No\n";
            continue;
        }
        if (a[0]==0 && (tonxt+dif)%6==0){
            cout<<"Yes\n";
            continue;
        }
        tonxt = (6-(tonxt+dif)%6);
        if (tonxt%3!=0){
            cout<<"No\n";
            continue;
        }

        a[0]-=tonxt/3+1;
        a[1] = a[2] = a[0];
        if (a[0]%3!=0 || a[0]<0)cout<<"No\n";
        else cout<<"Yes\n";
    }
    return 0;
}