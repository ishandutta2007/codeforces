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
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int main()
{
    io
    long cnt=0,m;
    double n,a,t,b;
    cin>>n>>a;
    if(n==3) {cout<<1<<" "<<2<<" "<<3;exit(0);}
    t=180/n;
    m=a/t;
    if(abs((double)m*t-a)>abs((double)m*t+t-a)) m++;
    if(m==0) m++;
    cout<<2<<" "<<1<<" "<<min(2+m,(long)n);
    return 0;
}