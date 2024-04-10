/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int n,m;

bool check_reverse(string a, string b)
{
    for(int i=0;i<m;i++)
    {
        if(a[i]!=b[m-1-i]) return false;
    }
    return true;
}

void solve()
{
    cin>>n>>m;

    char a[n][m];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++) cin>>a[i][j];
    }

    char ans[n*m+1];
    int cnt=0;
    int used[n]={0};

    for(int i=0;i<n;i++)
    {
        if(used[i]==1) continue;
        for(int j=i+1;j<n;j++)
        {
            if(check_reverse(a[i],a[j])==1)
            {
                used[i]=1;
                used[j]=1;
                for(int k=0;k<m;k++)
                {
                    ans[cnt++]=a[i][k];
                }
                break;
            }
        }
    }

    int lst=cnt;
    for(int i=0;i<n;i++)
    {
        if(used[i]==1) continue;
        if(check_reverse(a[i],a[i])==1)
        {
            for(int k=0;k<m;k++)
            {
                ans[cnt++]=a[i][k];
            }
            break;
        }
    }

    while(lst>0)
    {
        lst--;
        ans[cnt++]=ans[lst];
    }

    cout<<cnt<<endl;
    for(int i=0;i<cnt;i++)
    {
        cout<<ans[i];
    }
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}