/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

const int N = 100;
int n, m, a[N];

bool check(int k)
{
    int b[n+1];
    for(int i=1; i<=n; i++)
    {
        int j = a[i]%k;
        b[i]=j;
    }
    sort(b+1, b+n+1);

    for(int i=1; i<=n; i++)
    {
        int j=i;
        while(j<=n && b[j]==b[i]) j++;
        int cnt = j-i;
        i = j-1;
        if(cnt>=m) return true;
    }

    return false;
}

int solve()
{
    cin>>n;
    m=n/2;

    for(int i=1; i<=n; i++) cin>>a[i];
    sort(a+1, a+n+1);

    map<int, int> mp;
    for(int i=1; i<=n; i++)
    {
        mp[a[i]]++;
        if(mp[a[i]]>=m) return -1;
    }

    int mn = a[1];
    for(int i=1; i<=n; i++) a[i]-=mn;

    set<int> st;
    for(int i=n; i>=1; i--)
    {
        for(int j=i-1; j>=1; j--)
        {
            int dif = a[i]-a[j];
            if(dif==0) continue;
            st.insert(dif);
        }
    }

    int ans=1;
    set<int> st2;

    for(int x: st)
    {
        for(int i=2; i*i<=x; i++)
        {
            int f1 = i;
            int f2 = f2 = x/i;
            st2.insert(f1);
            st2.insert(f2);
        }
        st2.insert(x);
    }

    for(int y: st2)
    {
        if(check(y)) ans = max(ans, y);
    }

    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) cout<<solve()<<endl;
    return 0;
}