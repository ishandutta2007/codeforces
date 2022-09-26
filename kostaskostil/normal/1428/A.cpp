#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

const int nmax=500500;
typedef long long ll;
#define int ll

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ___;
    cin>>___;
    for (int _=0; _<___; _++)
    {
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;
        if ((x1==x2) or (y1==y2))
            cout<<abs(x1-x2)+abs(y1-y2)<<"\n";
        else
            cout<<abs(x1-x2)+abs(y1-y2)+2<<"\n";
    }
}