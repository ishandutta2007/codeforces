#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const ld PI = 4*atan(1);
int main()
{
    ld d,h,v,e;
    cin>>d>>h>>v>>e;
    ld rate = v/(PI*(d/2)*(d/2)) - e;
    if(rate <= 1e-4){
        cout<<"NO";
        return 0;
    }
    cout<<"YES\n";
    cout<<setprecision(10)<<fixed<<(h/rate);

}