#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
using namespace std;
int main()
{
    long x1,y1,x2,y2,a,b;
    cin>>x1>>y1>>x2>>y2>>a>>b;
    if((x2-x1)%a==0 && (y2-y1)%b==0 && (abs(x2-x1)/a)%2==(abs(y2-y1)/b)%2) cout<<"YES";
    else cout<<"NO";
    return 0;
}