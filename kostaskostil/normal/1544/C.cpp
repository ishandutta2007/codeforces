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

    int qqq;
    cin>>qqq;
    for (int iii=0; iii<qqq; iii++)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for (int& i : a) cin>>i;
        vector<int> b(n);
        for (int& i : b) cin>>i;
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        sort(b.begin(), b.end());
        reverse(b.begin(), b.end());
        for (int i=1; i<n; i++)
            a[i]+=a[i-1], b[i]+=b[i-1];
        int k = n;
        while (true)
        {
            int r = k - k/4;

            int sa = 100 * (min(r, k-n));
            if (r-(k-n) >= 1)
                sa += a[r - (k-n) - 1];
            /// 100*(k-n) + sum(r - (k - n))
            int sb = b[min(r, n) - 1];
            /// sum(r)
//            cout<<k<<" "<<sa<<" "<<sb<<"\n";
            if (sa >= sb)
                break;
            k++;
        }
        cout<<k-n<<"\n";
    }
}