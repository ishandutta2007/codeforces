#include <iostream>
#include<algorithm>

using namespace std;

const int MAXN=3000;
long long n,m,ans,ans1;
char c[MAXN][MAXN];
int mark1[MAXN][MAXN],mark2[MAXN][MAXN],mark3[MAXN][MAXN],mark4[MAXN][MAXN];

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>c[i][j];
    for(int i=0;i<n;i++)
    {
        int j=0;
        while(j<m && c[i][j]=='.')
            mark1[i][j++]=1;
        if(i!=0 && i!=n-1 && j==m)
            ans++;
        j=m-1;
        while(j>-1 && c[i][j]=='.')
            mark2[i][j--]=1;
    }
   // cout<<ans<<endl;
    for(int j=0;j<m;j++)
    {
        int i=0;
        while(i<n && c[i][j]=='.')
            mark3[i++][j]=1;
        if(j!=0 && j!=m-1 && i==n)
            ans++;
        i=n-1;
        while(i>-1 && c[i][j]=='.')
            mark4[i--][j]=1;
    }
    for(int i=1;i<n-1;i++)
        for(int j=1;j<m-1;j++)
            ans+=(mark1[i][j]+mark2[i][j])*(mark3[i][j]+mark4[i][j]);
    for(int i=1;i<n-1;i++)
        for(int j=1;j<m-1;j++)
            if(c[i][j]=='.')
            {
                int x=j;
                ans1=0;
                while(x<m-1 && c[i][x]=='.')
                {
                    ans+=ans1*(mark3[i][x]+mark4[i][x]);
                    ans1+=mark3[i][x]+mark4[i][x];
                    x++;
                }
                j=max(j,x);
            }
    for(int j=1;j<m-1;j++)
        for(int i=1;i<n-1;i++)
            if(c[i][j]=='.')
            {
                int x=i;
                ans1=0;
                while(x<n-1 && c[x][j]=='.')
                {
                    ans+=ans1*(mark1[x][j]+mark2[x][j]);
                    ans1+=mark1[x][j]+mark2[x][j];
                    x++;
                }
                i=max(i,x);
            }
    for(int i=1;i<n-1;i++)
        for(int j=1;j<m-2;j++)
            if(c[i][j]=='.' && c[i][j+1]=='.')
                ans-=mark3[i][j]*mark3[i][j+1]+mark4[i][j]*mark4[i][j+1];
    for(int i=1;i<n-2;i++)
        for(int j=1;j<m-1;j++)
            if(c[i][j]=='.' && c[i+1][j]=='.')
                ans-=mark1[i][j]*mark1[i+1][j]+mark2[i][j]*mark2[i+1][j];
    cout<<ans<<endl;
}