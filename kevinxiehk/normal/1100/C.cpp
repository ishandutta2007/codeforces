#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define int long long
#define PI (long double)3.1415926535897
using namespace std;
long double n,r;
long double angle;
void solve(){
    cin>>n>>r;
    angle=(PI*2)/n;
    long double t=1-cos(angle);
    long double a=4-2*t;
    long double b=-4*t*r;
    long double c=-2*t*r*r;
    cout<<fixed<<setprecision(10)<<((b*-1)+sqrt(b*b-(long double)(4)*c*a))/((long double)2*a)<<endl;
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;

    //cin>>t;
    t=1;

    while(t--)solve();
    return 0;
}