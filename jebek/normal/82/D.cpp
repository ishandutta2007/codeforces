#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int>v;
int n,a[2000],dp[2000][2000],ans,ind,par[2000][2000];

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    if(n==1)
    {
        cout<<a[0]<<endl<<1<<endl;
        return 0;
    }
    if(n==2)
    {
        cout<<max(a[0],a[1])<<endl<<1<<" "<<2<<endl;
        return 0;
    }
    dp[2][0]=max(a[1],a[2]);
    dp[2][1]=max(a[0],a[2]);
    dp[2][2]=max(a[1],a[0]);
    for(int i=4;i<n;i+=2)
    {
        dp[i][i]=dp[i][i-1]=2000000000;
        for(int j=0;j<i-1;j++)
        {
            dp[i][j]=dp[i-2][j]+max(a[i],a[i-1]);
            par[i][j]=j;
            if(dp[i][i]>dp[i-2][j]+max(a[j],a[i-1]))
            {
                dp[i][i]=dp[i-2][j]+max(a[j],a[i-1]);
                par[i][i]=j;
            }
            if(dp[i][i-1]>dp[i-2][j]+max(a[j],a[i]))
            {
                dp[i][i-1]=dp[i-2][j]+max(a[j],a[i]);
                par[i][i-1]=j;
            }
        }
    }
    if(n%2==0)
    {
        ans=2000000000;
        for(int i=0;i<n-1;i++)
        {
            if(dp[n-2][i]+max(a[i],a[n-1])<ans)
            {
                ans=dp[n-2][i]+max(a[i],a[n-1]);
                ind=i;
            }
        }
        cout<<ans<<endl;
        v.push_back(n-1);
        v.push_back(ind);
        for(int i=n-2;i>0;i-=2)
        {
            if(ind==par[i][ind])
            {
                v.push_back(i);
                v.push_back(i-1);
            }
            else if(ind==i)
            {
                v.push_back(i-1);
                v.push_back(par[i][ind]);
            }
            else
            {
                v.push_back(i);
                v.push_back(par[i][ind]);
            }
            ind=par[i][ind];
        }
    }
    else
    {
        ans=2000000000;
        for(int i=0;i<n;i++)
            if(dp[n-1][i]+a[i]<ans)
            {
                ans=dp[n-1][i]+a[i];
                ind=i;
            }
        cout<<ans<<endl;
        v.push_back(ind);
        for(int i=n-1;i>0;i-=2)
        {
            if(ind==par[i][ind])
            {
                v.push_back(i);
                v.push_back(i-1);
            }
            else if(ind==i)
            {
                v.push_back(i-1);
                v.push_back(par[i][ind]);
            }
            else
            {
                v.push_back(i);
                v.push_back(par[i][ind]);
            }
            ind=par[i][ind];
        }
    }
    reverse(v.begin(),v.end());
    for(int i=0;i<v.size()-1;i++)
    {
        if(i%2==0)
            cout<<v[i]+1<<" ";
        else
            cout<<v[i]+1<<endl;
    }
    cout<<v.back()+1<<endl;
}