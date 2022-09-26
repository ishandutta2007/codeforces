#include<bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

#define int long long

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ttt=0;
    cin>>ttt;
    for (int iii=0; iii<ttt; iii++)
    {
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;
        int x=x2-x1;
        int y=y2-y1;
        if (x>y)
            swap(x, y);
        int ans=x*(x+1)/2;
        cout<<2*ans - (x) + x*(y-x) + 1<<"\n";
    }
}