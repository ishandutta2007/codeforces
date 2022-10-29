#include <bits/stdc++.h>
#define pb push_back
#define long long long
using namespace std;
long n,m,w,c,a[300005][3]={0},ans=0,i,s=0,v[4][300005]={0};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(i=0;i<n;++i)
    {
        cin>>w>>c;
        v[w][i]=c;
    }
    for(i=1;i<=3;++i)
    {
        sort(v[i],v[i]+300005);
        reverse(v[i],v[i]+300005);
    }
    a[1][0]=v[1][0];
    a[1][1]=1;
    a[1][2]=0;
    ans=v[1][0];
    for(i=2;i<=m;++i)
    {
        if(a[i-1][0]+v[1][a[i-1][1]]>a[i-2][0]+v[2][a[i-2][2]])
        {
            a[i][0]=a[i-1][0]+v[1][a[i-1][1]];
            a[i][1]=a[i-1][1]+1;
            a[i][2]=a[i-1][2];
        }
        else
        {
            a[i][0]=a[i-2][0]+v[2][a[i-2][2]];
            a[i][1]=a[i-2][1];
            a[i][2]=a[i-2][2]+1;
        }
        ans=max(ans,a[i][0]);
    }
    for(i=0;v[3][i]!=0;++i)
    {
        s+=v[3][i];
        if(m>=3*(i+1))
        ans=max(ans,s+a[m-3*(i+1)][0]);
        else break;
    }
    cout<<ans<<endl;
    return 0;
}