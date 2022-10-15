/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n,m,k;
    cin>>n>>m>>k;

    int mx=(4*n*m - 2*n - 2*m);
    if(k>mx) { cout<<"NO"<<endl; return; }
    cout<<"YES"<<endl;

    char mov[3001][4];
    int len[3001];
    int freq[3001]={0};
    int cnt=0;

    if(m!=1) { mov[++cnt][0]='R'; len[cnt]=1; freq[cnt]=m-1; }
    if(m!=1) { mov[++cnt][0]='L'; len[cnt]=1; freq[cnt]=m-1; }

    for(int i=1;i<n;i++)
    {
        if(m!=1) { mov[++cnt][0]='D'; mov[cnt][1]='R'; mov[cnt][2]='U'; len[cnt]=3; freq[cnt]=m-1; }
        mov[++cnt][0]='D'; len[cnt]=1; freq[cnt]=1;
        if(m!=1) { mov[++cnt][0]='L'; len[cnt]=1; freq[cnt]=m-1; }
    }

    if(n!=1) { mov[++cnt][0]='U'; len[cnt]=1; freq[cnt]=n-1; }

    /*
    for(int i=1;i<=cnt;i++)
    {
        cout<<freq[i]<<" ";
        for(int j=0;j<len[i];j++) cout<<mov[i][j];
        cout<<endl;
    }
    */

    int lst=cnt;
    int tmp=k;

    for(int i=1;i<=cnt;i++)
    {
        int val=freq[i]*len[i];
        if(tmp<=val) { lst=i; break; }
        tmp-=val;
    }

    int ans=lst;
    
    int y=(tmp%len[lst]);
    int z=(tmp/len[lst]);
    
    if(y!=0) ans++;
    if(z==0) ans--;

    cout<<ans<<endl;

    for(int i=1;i<lst;i++)
    {
        cout<<freq[i]<<" ";
        for(int j=0;j<len[i];j++) cout<<mov[i][j];
        cout<<endl;
    }

    if(z!=0)
    {
        cout<<z<<" ";
        for(int j=0;j<len[lst];j++) cout<<mov[lst][j];
        cout<<endl;
    }

    if(y!=0)
    {
        cout<<1<<" ";
        for(int j=0;j<y;j++) cout<<mov[lst][j];
        cout<<endl;
    }

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}