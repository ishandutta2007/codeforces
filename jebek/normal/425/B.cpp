#include <iostream>
#include<algorithm>

using namespace std;

int n,m,t,q,x,a[300][300],k,ans=20,f;
bool mark;

void dp()
{
    for(int u=0;u<(1<<(n*m));u++)
    {
       // if(u==1791)
        //    for(int i=0;i<n;i++){
          //      for(int j=0;j<m;j++)
           //         cout<<a[i][j]<<" ";
            //    cout<<endl;
            //}
        t=0;
        q=u;
        mark=true;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(q%2==0)
                {
                    a[i][j]=1-a[i][j];
                    t++;
                }
                q=q/2;
            }
        if(t>k)
        {
            q=u;
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++)
                {
                    if(q%2==0)
                        a[i][j]=1-a[i][j];
                    q=q/2;
                }
            continue;
        }
        for(int i=1;i<n;i++)
        {
            x=0;
            for(int j=0;j<m;j++)
            {
                if(a[i][j]!=a[0][j])
                    x++;
            }
            if(x!=0 && x!=m)
            {
            //    if(u==1791)
              //      cout<<x<<endl;
                mark=false;
                break;
            }
        }
        if(mark==false)
         {
            q=u;
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++)
                {
                    if(q%2==0)
                        a[i][j]=1-a[i][j];
                    q=q/2;
                }
            continue;
        }
        ans=min(ans,t);
       // cout<<t<<" "<<u<<endl;
        q=u;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(q%2==0)
                    a[i][j]=1-a[i][j];
                q=q/2;
            }
    }
}

int main()
{
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>a[i][j];
    if(n>=m)
    {
        if(n>k)
        {
            for(int u=0;u<=k;u++)
            {
                f=0;
                for(int i=0;i<n;i++)
                {
                    x=0;
                    for(int j=0;j<m;j++)
                        if(a[u][j]!=a[i][j])
                            x++;
                    x=min(x,m-x);
                    f+=x;
                }
                ans=min(ans,f);
            }
        }
        else if(2*n<k)
        {
            dp();
        }
        else
        {
            for(int u=0;u<n;u++)
            {
                f=0;
                for(int i=0;i<n;i++)
                {
                    x=0;
                    for(int j=0;j<m;j++)
                        if(a[u][j]!=a[i][j])
                            x++;
                    x=min(x,m-x);
                    f+=x;
                }
                ans=min(ans,f);
                for(int v=0;v<m;v++)
                {
                    f=0;
                    a[u][v]=1-a[u][v];
                    for(int i=0;i<n;i++)
                    {
                        x=0;
                        for(int j=0;j<m;j++)
                            if(a[u][j]!=a[i][j])
                                x++;
                        x=min(x,m-x);
                        f+=x;
                    }
                    ans=min(ans,f+1);
                    a[u][v]=1-a[u][v];
                }
            }
        }
    }
    else
    {
        if(m>k)
        {
            for(int u=0;u<=k;u++)
            {
                f=0;
                for(int i=0;i<m;i++)
                {
                    x=0;
                    for(int j=0;j<n;j++)
                        if(a[j][u]!=a[j][i])
                            x++;
                    x=min(x,n-x);
                    f+=x;
                }
                ans=min(ans,f);
            }
        }
        else if(2*m<k)
        {
            dp();
        }
        else
        {
            for(int u=0;u<m;u++)
            {
                f=0;
                for(int i=0;i<m;i++)
                {
                    x=0;
                    for(int j=0;j<n;j++)
                        if(a[j][u]!=a[j][i])
                            x++;
                    x=min(x,n-x);
                    f+=x;
                }
                ans=min(ans,f);
                for(int v=0;v<n;v++)
                {
                    f=0;
                    a[v][u]=1-a[v][u];
                    for(int i=0;i<m;i++)
                    {
                        x=0;
                        for(int j=0;j<n;j++)
                            if(a[j][u]!=a[j][i])
                                x++;
                        x=min(x,n-x);
                        f+=x;
                    }
                    ans=min(ans,f+1);
                    a[v][u]=1-a[v][u];
                }
            }
        }
    }
    if(ans<=k)
        cout<<ans<<endl;
    else
        cout<<-1<<endl;
}