/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int N = 1e4;
int a[N][6], n;

bool check(int d1, int d2)
{
    int o1=0, o2=0, m=(n/2);
    for(int i=1; i<=n; i++)
    {
        if(a[i][d1]==0 && a[i][d2]==0) return false;
        if(a[i][d1]==0 && a[i][d2]==1) o2++;
        if(a[i][d1]==1 && a[i][d2]==0) o1++;
    }

    if(o1>m || o2>m) return false;
    return true;
}

bool solve()
{
    cin>>n;
    for(int i=1; i<=n; i++) for(int j=1; j<=5; j++) cin>>a[i][j];
    for(int i=1; i<=5; i++) for(int j=i+1; j<=5; j++) if(check(i, j)) return true;
    return false;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--)
    {
        if(solve()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}