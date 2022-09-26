#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

typedef long long ll;
#define int ll

using namespace std;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ___;
    cin>>___;
    for (int _ = 0; _<___; _++)
    {
        int n, m;
        cin>>n>>m;
        vector<int> k(n);
        vector<int> c(m);
        for (int& i:k) cin>>i;
        for (int& i:c) cin>>i;
        sort(k.begin(), k.end());

        int s=0;
        for (int i:k)
            s+=c[i-1];
        int ans=s;
        int nt=0;
        for (int j = n-1; j>=0; j--)
        {
            if ((nt==m) or (k[j]-1 < nt))
                break;

            s-=c[k[j]-1];
            s+=c[nt];
            nt++;
            ans=min(ans, s);
        }
        cout<<ans<<"\n";
    }
}