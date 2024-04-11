#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;
const int nmax=5e5+100;

int n, k;
main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for (int j=0; j<t; j++)
    {
        string s;
        cin>>s;
        bool g0=true, g1=true;
        for (int i=0; i<s.size(); i++)
            if (s[i]=='0') g1=false;
            else g0=false;
        if (g0) cout<<string(s.size(), '0');
        else if (g1) cout<<string(s.size(), '1');
        else
        for (int i=0; i<s.size(); i++)
            cout<<"01";
        cout<<"\n";
    }
}