#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std;

#define int long long

const int nmax=5e5+100;
int a[nmax];
int b[nmax];
main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;
    int n=s.size();
    int up=0, dn=0;
    for (int i=0; i<n; i++)
        if (s[i]=='(')
            up++, a[up]=i;
    for (int i=n-1; i>=0; i--)
        if (s[i]==')')
            dn++, b[dn]=i;
    if ((up==0 or dn==0) or (a[1]>b[1]))
        cout<<0<<"\n";
    else
    {
        a[up+1]=n;
        b[dn+1]=-1;
        int i=min(up, dn);
        while (a[i]>b[i])
            i--;
        cout<<"1\n"<<2*i<<"\n";
        for (int j=1; j<=i; j++)
            cout<<a[j]+1<<" ";
        for (int j=i; j>=1; j--)
            cout<<b[j]+1<<" ";
        cout<<"\n";
    }

    return 0;
}