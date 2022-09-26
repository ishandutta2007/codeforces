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

    string s;
    cin>>s;
    int mn=1e9;
    for (int i=0; i<s.size(); i++)
        if (s[i]<=mn)
            cout<<"Mike\n", mn=s[i];
        else
            cout<<"Ann\n";
}