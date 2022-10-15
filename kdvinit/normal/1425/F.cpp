/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

int query(int l, int r)
{
    cout<<"? "<<l<<" "<<r<<endl;
    int ans; cin>>ans; return ans;
}

/*
6
1 4 4 6 7 8
*/

void solve()
{
    int n; cin>>n;

    int a[n+1];
    for(int i=2; i<=n; i++) a[i] = query(1, i);
    a[1] = a[n]-query(2, n);

    for(int i=n; i>1; i--) a[i]-=a[i-1];

    cout<<"! ";
    for(int i=1; i<=n; i++) cout<<a[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    solve();
    return 0;
}