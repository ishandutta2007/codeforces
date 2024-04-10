/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

bool solve()
{
    int n;
    cin>>n;

    int a[n+1], b[n+1];
    for(int i=1; i<=n; i++) { cin>>a[i]; b[i]=a[i]; }
    sort(b+1, b+n+1);

    for(int i=2; i<=n; i++) if(b[i]==b[i-1]) return true;

    map<int, int> pos;
    for(int i=1; i<=n; i++) pos[b[i]]=i;

    int vis[n+1]={0}, cnt=0;
    for(int i=1; i<=n; i++)
    {
        if(vis[i]) continue;
        int j=i, tmp=1; vis[i]=1;
        while(pos[a[j]]!=i)
        {
            j=pos[a[j]];
            vis[j]=1;
            tmp++;
        }
        if(tmp%2==0) cnt++;
    }

    if(cnt%2==0) return true;
    else return false;
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