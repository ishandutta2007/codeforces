#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;
const int nmax=5e5+100;
#define int long long

int a[nmax];
main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ttt;
    cin>>ttt;
    for (int iii=0; iii<ttt; iii++){
        int n1, n2, n3;
        cin>>n1>>n2>>n3;
        if (n2==0)
        {
            if (n1!=0)
                for (int i=0; i<=n1; i++)
                    cout<<'0';
            else
                for (int i=0; i<=n3; i++)
                    cout<<'1';
            cout<<"\n";
            continue;
        }
        for (int i=1; i<=n1+1; i++)
            cout<<'0';
        for (int i=1; i<n2; i++)
            cout<<char('0' + i%2);
        if (n2%2)
            cout<<'1';
        for (int i=1; i<=n3; i++)
            cout<<'1';
        if (n2%2==0)
            cout<<'0';
        cout<<"\n";
    }

    return 0;
}