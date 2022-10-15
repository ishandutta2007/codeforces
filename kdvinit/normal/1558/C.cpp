/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e4;
int a[N];
int n;

int fnd(int x)
{
    for(int i=1; i<=n; i++) if(a[i]==x) return i;
}

int rev(int len)
{
    int m = len/2;
    for(int i=1; i<=m; i++)
    {
        swap(a[len+1-i], a[i]);
    }
}

void solve()
{
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];

    for(int i=1; i<=n; i++)
    {
        if(a[i]%2 != i%2) { cout<<-1<<endl; return; }
    }

    vector<int> ans;
    for(int i=n; i>1; i-=2)
    {
        int x = fnd(i);
        ans.push_back(x);
        rev(x);

        x=fnd(i-1);
        ans.push_back(x-1);
        rev(x-1);

        ans.push_back(i);
        rev(i);

        x = fnd(i);
        ans.push_back(x);
        rev(x);

        ans.push_back(i);
        rev(i);
    }

    cout<<ans.size()<<endl;
    for(int x: ans) cout<<x<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}