#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[300009],n;
int fr[100000009];
int go(int x)
{
    vector<int>tmp;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int u=i*x;
        int r=a[i]-u+40000000;
        fr[r]++;
        ans=max(ans,fr[r]);
        tmp.push_back(r);
    }
   for(int i=0;i<tmp.size();i++)fr[tmp[i]]=0;
   return ans;
}
int cal(int l,int r)
{
    int ans=1;
    for(int i=l;i<=r;i++)
    {
        vector<int>tmp;
        for(int j=i+1;j<=r;j++)
        {
            if((a[j]-a[i])%(j-i)==0){fr[(a[j]-a[i])/(j-i)+1000000]++;tmp.push_back((a[j]-a[i])/(j-i)+1000000);}

        }
        int res=0;
        for(int i=0;i<tmp.size();i++){res=max(res,fr[tmp[i]]);fr[tmp[i]]=0;}
        ans=max(ans,res+1);
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int ans=0;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=-400;i<=400;i++)
    ans=max(go(i),ans);
    for(int i=0;i<n;i+=250)
    {
        ans=max(cal(i,min(i+500,n-1)),ans);

    }
    ans=n-ans;
    cout<<ans<<endl;

}