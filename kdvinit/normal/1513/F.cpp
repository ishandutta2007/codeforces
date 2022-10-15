#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 1;
int n;

vector<int> X, Y;
vector< array<int, 2> > XX, YY;

int a[N], b[N];

int32_t main()
{
    cin>>n;

    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++) cin>>b[i];

    int ans = 0;
    for(int i=1; i<=n; i++)
    {
        ans += abs(a[i] - b[i]);
        if(a[i]<=b[i])
        {
            X.push_back(i);
            XX.push_back( {a[i], b[i]} );
        }
        else
        {
            Y.push_back(i);
            YY.push_back( {b[i], a[i]} );
        }
    }

    if(X.size()==0 || Y.size()==0) { cout<<ans<<endl; return 0; }

    sort(XX.begin(), XX.end());
    sort(YY.begin(), YY.end());

    int mx=0;
    vector<int> Xl, Yl;
    for(int i=0; i<XX.size(); i++)
    {
        Xl.push_back(XX[i][0]);
        mx = max(mx, XX[i][1]);
        XX[i][1]=mx;
    }

    mx=0;
    for(int i=0; i<YY.size(); i++)
    {
        Yl.push_back(YY[i][0]);
        mx = max(mx, YY[i][1]);
        YY[i][1]=mx;
    }

    int sub=0;

    for(auto i: X)
    {
        int l = a[i], r = b[i];
        if( l < *Yl.begin() ) continue;
        int i2 = upper_bound(Yl.begin(), Yl.end(), l)  - Yl.begin();
        i2--;
        int r2 = YY[i2][1];
        //cout<<l<<" "<<r<<" "<<i2<<" "<<r2<<endl;

        r2 = min(r2, r);
        sub = max(sub, r2-l);
    }

    for(auto i: Y)
    {
        int l = b[i], r = a[i];
        if( l < *Xl.begin() ) continue;
        int i2 = upper_bound(Xl.begin(), Xl.end(), l) - Xl.begin();
        i2--;
        int r2 = XX[i2][1];
        //cout<<l<<" "<<r<<" "<<i2<<" "<<r2<<endl;

        r2 = min(r2, r);
        sub = max(sub, r2-l);
    }

    //cout<<ans<<" "<<sub<<endl;

    ans -= 2*(sub);
    cout<<ans<<endl;

    return 0;
}