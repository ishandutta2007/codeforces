#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int nmax=1e3+100;
#define int long long

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    string s;
    cin>>n>>s;
    int z=0;
    n=0;
    for (char c:s)
        if (c=='z') z++;
        else if (c=='n') n++;
    for (int i=1; i<=n; i++)
        cout<<"1 ";
    for (int i=1; i<=z; i++)
        cout<<"0 ";
}