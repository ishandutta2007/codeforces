#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int ttt;
    cin>>ttt;
    for (int iii=0; iii<ttt; iii++)
    {
        int n;
        cin>>n;
        if (n%4 != 0)
            cout<<"NO\n";
        else
        {
            cout<<"YES\n";
            int s=0;
            for (int i=1; i<=n/2; i++)
                cout<<2*i<<" ", s+=2*i;
            for (int i=1; i<n/2; i++)
                cout<<2*i-1<<" ", s-=(2*i-1);
            cout<<s<<"\n";
        }
    }
}