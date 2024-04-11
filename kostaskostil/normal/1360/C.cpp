#include<bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
#define int ll

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ttt=0;
    cin>>ttt;
    for (int iii=0; iii<ttt; iii++)
    {
        int n;
        set<int> s;
        cin>>n;
        vector<int> v(n);
        int ev=0;
        for (int& i:v)
            cin>>i, s.insert(i);
        for (int i:v)
            if (i%2==0)
                ev++;
        bool ok=(ev%2==0);
        if (!ok)
        {
            for (int i:v)
            if (s.count(i+1))
            ok=true;
        }
        if (ok)
            cout<<"YES\n";
        else cout<<"NO\n";
    }
}