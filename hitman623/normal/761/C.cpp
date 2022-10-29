#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;

int main()
{
    long n,m,v[100][3]={0},ans=1000000009,p[9]={0},i,j,k,l,f;
    char a[100][100];
    cin>>n>>m;
    for(i=0;i<n;++i)
        cin>>a[i];
    for(i=0;i<n;++i)
    {
        for(j=0;j<m;++j)
        {
        if((a[i][j]=='*' || a[i][j]=='#' || a[i][j]=='&'))
            v[i][0]=min(v[i][0]?v[i][0]:100005,min(j+1,m-j+1));
        if(isalpha(a[i][j]))
            v[i][1]=min(v[i][1]?v[i][1]:100005,min(j+1,m-j+1));
        if(isdigit(a[i][j]))
            v[i][2]=min(min(j+1,m-j+1),v[i][2]?v[i][2]:100005);
        }
        //cout<<v[i][0]<<" "<<v[i][1]<<" "<<v[i][2]<<endl;
    }
    for(i=0;i<n;++i)
    {
        for(j=i+1;j<n;++j)
        {
            for(k=j+1;k<n;++k)
            {
               if(v[i][0]==0 || v[j][1]==0 || v[k][2]==0) p[0]=1000005;  else p[0]=v[i][0]+v[j][1]+v[k][2];
               if(v[i][0]==0 || v[j][2]==0 || v[k][1]==0) p[1]=1000005;  else p[1]=v[i][0]+v[j][2]+v[k][1];
               if(v[i][1]==0 || v[j][0]==0 || v[k][2]==0) p[2]=1000005;  else p[2]=v[i][1]+v[j][0]+v[k][2];
               if(v[i][1]==0 || v[j][2]==0 || v[k][0]==0) p[3]=1000005;  else p[3]=v[i][1]+v[j][2]+v[k][0];
               if(v[i][2]==0 || v[j][1]==0 || v[k][0]==0) p[4]=1000005;  else p[4]=v[i][2]+v[j][1]+v[k][0];
               if(v[i][2]==0 || v[j][0]==0 || v[k][1]==0) p[5]=1000005;  else p[5]=v[i][2]+v[j][0]+v[k][1];
               for(l=0;l<6;++l)
               ans=min(ans,p[l]);
            }
        }
    }
    cout<<ans-3;
    return 0;
}