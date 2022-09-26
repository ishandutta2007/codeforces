#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;
const int nmax=5e5+100;

int n;
int a[nmax];
main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ttt;
    cin>>ttt;
    for (int iii=0; iii<ttt; iii++)
    {
        int a, b, x, y;
        cin>>x>>y>>a>>b;
        x=abs(x), y=abs(y);
        cout<<min(2*a, b)*min(x, y)+a*max(x, y)-a*min(x, y)<<"\n";
    }
}