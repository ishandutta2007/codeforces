/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

bool check_sorted(int a[], int n)
{
    for(int i=1; i<=n; i++)
    {
        if(a[i]!=i) return false;
    }
    return true;
}

bool check_same(int a[], int b[], int n)
{
    for(int i=1; i<=n; i++)
    {
        if(a[i]!=b[i]) return false;
    }
    return true;
}

int get_value(int strt, int a[], int n)
{
    int b[2*n+1];
    for(int i=1; i<=2*n; i++) b[i]=a[i];

    if(check_sorted(a, 2*n)) return 0;

    int moves=0;
    int cur=strt;

    while(1)
    {
        if(cur==1)
        {
            for(int i=1; i<=2*n; i+=2)
            {
                swap(a[i], a[i+1]);
            }
            moves++;
        }
        else
        {
            for(int i=1; i<=n; i++)
            {
                swap(a[i], a[i+n]);
            }
            moves++;
        }

        if(cur==1) cur=2;
        else cur=1;

        if(check_same(a, b, 2*n)) return -1;
        if(check_sorted(a, 2*n)) return moves;
    }
}

void solve()
{
    int n;
    cin>>n;

    int a[2*n+1], c[2*n+1];
    for(int i=1; i<=2*n; i++) { cin>>a[i]; c[i]=a[i]; }

    int ans1 = get_value(1, a, n);
    int ans2 = get_value(2, c, n);

    int ans = min(ans1, ans2);
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}