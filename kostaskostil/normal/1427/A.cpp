#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

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
        int n;
        cin>>n;
        vector<int> a(n);
        int s=0;
        for (int& i:a) cin>>i, s+=i;
        if (s==0)
        {
            cout<<"NO\n";
        }
        else
        {
            cout<<"YES\n";
            sort(a.begin(), a.end());
            if (s>0)
                reverse(a.begin(), a.end());
            for (int i:a)
                cout<<i<<" ";
            cout<<"\n";
        }

    }
}