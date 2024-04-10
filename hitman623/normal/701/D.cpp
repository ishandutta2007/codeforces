#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define ml map < long , long >
#define mll map < pll , long >
#define x first
#define y second
#define vl vector < long >
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
long n,k,i,t;
double l,v1,v2;
long check(double mid)
{
    long d=n,cur;
    double x=(v2*l-mid*v1*v2)/(v2-v1),tim=(2*x*(t-1))/(v1+v2)+x/v2;
    return tim<=mid;
}
int main()
{
    io
    cin>>n>>l>>v1>>v2>>k;
    t=(n/k)+!!(n%k);
    double lo=0,hi=1e9,mid;
    cout<<fixed<<setprecision(10);
    for(i=0;i<80;++i)
    {
        mid=(lo+hi)/2;
        if(check(mid))
        hi=mid;
        else lo=mid;
    }
    cout<<mid;
    return 0;
}