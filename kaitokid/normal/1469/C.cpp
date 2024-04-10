#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
ios::sync_with_stdio(0);
int t,n,k;

cin>>t;
while(t--)
{
    cin>>n>>k;
    int x,mn,mx;
    cin>>x;
    mn=mx=x;
    bool ans=true;
    for(int i=1;i<n-1;i++)
    {
        cin>>x;
        mn=max(mn-k+1,x);
        mx=min(mx+k-1,x+k-1);
         if(mx<mn)ans=false;
            }

         cin>>x;
         if(ans&&mx>=mn&&x>=mn-k+1&&x<=mx+k-1)cout<<"YES\n";
         else cout<<"NO\n";


}
    return 0;
}