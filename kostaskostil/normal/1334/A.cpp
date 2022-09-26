#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for (int i=0; i<t; i++)
    {
        int n;
        cin>>n;
        int p, c;
        cin>>p>>c;
        bool f=true;
        if (c>p) cout<<"NO\n", f=false;
        for (int i=1; i<n; i++)
        {
            int p1, c1;
            cin>>p1>>c1;
            p1-=p;
            c1-=c;
            if (f)
            if ((p1<0) or (c1<0) or (c1>p1))
            {
                cout<<"NO\n";
                f=false;
            }
            p+=p1;
            c+=c1;
        }
        if (f)
            cout<<"YES\n";
    }
    return 0;
}