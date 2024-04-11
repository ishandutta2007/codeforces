#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;
const int nmax=5e5+100;
#define int long long

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ttt;
    cin>>ttt;
    for (int iii=0; iii<ttt; iii++){
        int n, k;
        cin>>n>>k;
        if (n%2 == k%2)
        {
            if (n<k)
                cout<<"NO\n";
            else
            {
                cout<<"YES\n";
                for (int i=1; i<k; i++)
                    cout<<1<<" ";
                cout<<n-k+1<<"\n";
            }
        }
        else
        {
            if (n%2 != 0)
                cout<<"NO\n";
            else
            {
                if (n<2*k)
                    cout<<"NO\n";
                else
                {
                    cout<<"YES\n";
                    for (int i=1; i<k; i++)
                        cout<<2<<" ";
                    cout<<n-2*k+2<<"\n";
                }
            }
        }

    }

    return 0;
}