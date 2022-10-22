#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200009],id[200009];
bool g[200009];
bool bl(int x,int y)
{
    return a[x]+x>a[y]+y;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        for(int i=0;i<n;i++){cin>>a[i];id[i]=i;g[i]=0;}
        sort(id,id+n,bl);
        for(int i=0;i<k;i++)
        {
            int u=id[i];
            g[u]=1;
        }
        ll ans=0,cs=0;
        for(int i=0;i<n;i++)
        {
            if(g[i]==1){
                    if(a[i]+cs-(n-i-1-(k-cs-1))<0){ans+=a[i]+cs;continue;}
                    cs++;continue;}
            ans+=a[i]+cs;
        }
        cout<<ans<<endl;
    }
    return 0;

}