#include <iostream>
using namespace std;

bool check(int inp[], int n, int strt, int m)
{
    int freq[n+1]={0},mx=0;
    for(int i=strt;i<strt+m;i++)
    {
        int x=inp[i];
        freq[x]++;
        if(freq[x]==2) return false;
        mx=max(mx,x);
    }
    if(mx==m) return true;
    else return false;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int inp[n+1],mx=0;
        for(int i=1;i<n+1;i++)
        {
            cin>>inp[i];
            mx=max(mx,inp[i]);
        }
        int cntr=0,ans[2];
        if(check(inp,n,1,n-mx) && check(inp,n,n-mx+1,mx)) ans[cntr++]=n-mx;
        if(check(inp,n,1,mx) && check(inp,n,mx+1,n-mx) && mx*2!=n) ans[cntr++]=mx;
        cout<<cntr<<endl;
        for(int i=0;i<cntr;i++) cout<<ans[i]<<" "<<n-ans[i]<<endl;
    }
    return 0;
}