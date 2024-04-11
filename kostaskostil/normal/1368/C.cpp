#include<bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

#define int long long

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    cout<<3*n+4<<"\n";
    cout<<"0 0\n0 1\n";
    for (int i=1; i<=n; i++)
        cout<<i<<" "<<i-1<<"\n"<<i<<" "<<i<<"\n"<<i<<" "<<i+1<<"\n";
    cout<<n+1<<" "<<n<<"\n"<<n+1<<" "<<n+1<<"\n";
}