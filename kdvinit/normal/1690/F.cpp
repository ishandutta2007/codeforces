/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int N = 205;
bool cp[N];
vector<int> pms;

int Make_Prime()
{
    for(int i=2;i<N;i++) cp[i]=1;
    for(int i=2;i*i<N;i++)
    {
        if(cp[i]==1)
        {
            for(int j=i*i; j<N; j+=i) cp[j]=0;
        }
    }

    for(int i=2; i<N; i++) if(cp[i]==1) pms.push_back(i);
    return 0;
}
int Implement_Make_Prime=Make_Prime();

void solve()
{
    int n;
    cin>>n;

    char a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    int p[n+1];
    for(int i=1; i<=n; i++) cin>>p[i];

    int vis[n+1]={0};
    vector<int> len;

    for(int i=1; i<=n; i++)
    {
        if(vis[i]==1) continue;

        vector<int> s;
        int cur=i;
        while(1)
        {
            if(vis[cur]==1) break;
            vis[cur]=1;
            s.push_back(a[cur]);
            cur=p[cur];
        }

        int l=s.size();

        for(int k=1; k<=l; k++)
        {
            if(l%k!=0) continue;
            int pos=1;
            for(int j=0; j<l; j++)
            {
                int nxt = (j+k)%l;
                if(s[j]!=s[nxt]) { pos=0; break; }
            }
            if(pos==1) { len.push_back(k); break; }
        }
    }

    int ans=1;
    for(int p: pms)
    {
        int mx = 1;
        for(int x: len)
        {
            int cur=1;
            while(x%p==0) { x/=p; cur*=p; }
            mx=max(mx, cur);
        }
        ans*=mx;
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}