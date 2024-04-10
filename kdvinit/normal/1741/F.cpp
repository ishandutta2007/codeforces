/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int N = 2e5 + 100;

vector<int> lpnts[N];
vector<int> rpnts[N];

int lleq(int num, int ind)
{
    int n = lpnts[ind].size();

    if(n==0) return 0;

    if(lpnts[ind][n-1]<=num) return n;

    int ans = upper_bound(lpnts[ind].begin(), lpnts[ind].end(), num) - lpnts[ind].begin();
    return ans;
}

int rleq(int num, int ind)
{
    int n = rpnts[ind].size();

    if(n==0) return 0;

    if(rpnts[ind][n-1]<=num) return n;

    int ans = upper_bound(rpnts[ind].begin(), rpnts[ind].end(), num) - rpnts[ind].begin();
    return ans;
}

int cnti(int l, int r, int ind)
{
    int ans = lleq(r, ind) - rleq(l-1, ind);
    return ans;
}

bool check(int l, int r, int ind)
{
    int c1 = cnti(l, r, 0);
    int c2 = cnti(l, r, ind);

    if(c1!=c2) return true;
    else return false;
}

void solve()
{
    int n;
    cin>>n;

    for(int i=0; i<=n; i++) { lpnts[i].clear(); rpnts[i].clear(); }

    int li[n+1], ri[n+1], ci[n+1];

    for(int i=1; i<=n; i++)
    {
        cin>>li[i]>>ri[i]>>ci[i];

        lpnts[0].push_back(li[i]);
        rpnts[0].push_back(ri[i]);

        lpnts[ci[i]].push_back(li[i]);
        rpnts[ci[i]].push_back(ri[i]);
    }

    for(int i=0; i<=n; i++)
    {
        sort(lpnts[i].begin(), lpnts[i].end());
        sort(rpnts[i].begin(), rpnts[i].end());
    }

    for(int i=1; i<=n; i++)
    {
        if(check(li[i], ri[i], ci[i])) { cout<<0<<" "; continue; }

        int cc = ci[i];
        int cur = 1e9;

        if(check(1, li[i], cc))
        {
            int l=1;
            int r=li[i];

            while(l+1!=r)
            {
                int m = (l+r)/2;
                if(check(m, li[i], cc)) l=m;
                else r=m;
            }

            int tmp = li[i]-l;
            cur = min(cur, tmp);
        }

        int mx = 1e9;
        if(check(ri[i], mx, cc))
        {
            int l=ri[i];
            int r=1e9;

            while(l+1!=r)
            {
                int m = (l+r)/2;
                if(check(ri[i], m, cc)) r=m;
                else l=m;
            }

            int tmp = r-ri[i];
            cur = min(cur, tmp);
        }

        cout<<cur<<" ";
    }

    cout<<endl;
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}