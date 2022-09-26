#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int nmax=2e5+100;
#define int long long

int n;
int a[nmax];

vector<int> check(int t)
{
    vector<int> ans;
    for (int i=1; i<=n; i++)
    {
        if ( (a[i]%t != 0) or ((a[i]/t)%2==0) )
            ans.pb(a[i]);
    }
    return ans;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    vector<int> mn(nmax, 0);
    int t=1;
    while (t<1e18)
    {
        vector<int> nt=check(t);
        t*=2;
        if (nt.size()<mn.size())
            mn=nt;
    }
    cout<<mn.size()<<"\n";
    for (int i:mn)
        cout<<i<<" ";
    cout<<"\n";
}