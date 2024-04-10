/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

vector<int> pos[31];

int lst(int j, int i)
{
    int n = pos[j].size();
    if(n<i) return 0;
    return pos[j][n-i];
}

int mxr(int n, int l)
{
    int mx = l;
    for(int j=1; j<=30; j++)
    {
        int lft = pos[j].size();
        if(n%2==1) lft--;

        if(lft%2==1) mx = max(mx, lst(j, 2)+1);
        else mx = max(mx, lst(j, 1)+1);

        n/=2;
    }
    return mx;
}

bool check(int n)
{
    for(int j=1; j<=30; j++)
    {
        if(n%2==1)
        {
            if(pos[j].size()%2==0) return false;
        }
        n/=2;
    }

    return true;
}

void solve()
{
    int n, q;
    cin>>n>>q;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    int l, r;
    cin>>l>>r;

    for(int i=1; i<=30; i++) pos[i].clear();

    for(int i=l; i<=r; i++)
    {
        int x = a[i];
        for(int j=1; j<=30; j++)
        {
            if(x%2==1) pos[j].push_back(i);
            x/=2;
        }
    }

    int ans = mxr(0, l)-l;
    int al=l, ar=l+ans-1;

    int cs=0, cx=0;
    for(int i=l; i<=r; i++)
    {
        cs+=a[i];
        cx^=a[i];
        if(cs!=cx) break;
        if(!check(cs)) break;

        int cur = mxr(cs, l)-i-1;
        if(cur<0) continue;
        int y = mxr(cs, l);
        //cout<<i<<" ==> "<<y<<endl;

        if(cur<ans)
        {
            ans=cur;
            al=i+1;
            ar=al+cur-1;
        }
    }

    if(ans==0)
    {
        ans=1;
        al=l;
        ar=l;
    }

    cout<<al<<" "<<ar<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}