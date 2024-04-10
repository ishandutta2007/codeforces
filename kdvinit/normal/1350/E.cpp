/*

Mistake -
1. Define 2D array with {0} not good;
2. Loosing self confidence early;

*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    //Defining integers and arrays;
    int n,m,t;
    cin>>n>>m>>t;
    int a[n+2][m+2],cntr=0,man[n+2][m+2];
    
    //starting all arrays with required values
    for(int i=0;i<=n+1;i++)
    {
        for(int j=0;j<=m+1;j++)
        {
            a[i][j]=0;
            man[i][j]=2*(m+n);
        }
    }
    
    // Taking input 2d array cntr=num of dhongi and man=0 at dhongi(palti khor);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            char x;
            cin>>x;
            if(x=='0') a[i][j]=-1;
            else a[i][j]=1;
            if(a[i][j]==a[i-1][j])
            {
                man[i][j]=0;
                man[i-1][j]=0;
                cntr++;
            }
            if(a[i][j]==a[i][j-1])
            {
                man[i][j]=0;
                man[i][j-1]=0;
                cntr++;
            }
        }
    }
    
    // Taking into consideration the case when no one is dhongi;
    if(cntr==0)
    {
        long long int a1,b,c;
        for(int i=0;i<t;i++)
        {
            cin>>a1>>b>>c;
            cout<<(a[a1][b]+1)/2<<endl;
        }
        cout<<endl;
        return 0;
    }
    
    // Finding man=manhaten distance of non dhongi from dhongis;
    for(int v=1;v<m+n;v++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(man[i][j]==v-1)
                {
                   man[i-1][j]=min(man[i-1][j],v);
                   man[i][j-1]=min(man[i][j-1],v);
                   man[i+1][j]=min(man[i+1][j],v);
                   man[i][j+1]=min(man[i][j+1],v);
                }
            }
        }
    }

    //Input = final t test cases and there answer using manhatten;
    long long int a1,b,c;
    for(int i=0;i<t;i++)
    {
        cin>>a1>>b>>c;
        if(c<=man[a1][b] || (c-man[a1][b])%2==0) {cout<<(a[a1][b]+1)/2<<endl; continue;}
        cout<<(1-a[a1][b])/2<<endl;
    }

    return 0;
}