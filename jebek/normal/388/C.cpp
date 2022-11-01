#include <iostream>
#include<algorithm>

using namespace std;

long long n,t[200],a[200][200],MAX,ind,ans1,ans2,k,b[200],p;

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>t[i];
        k+=t[i];
        for(int j=0;j<t[i];j++)
        {
            cin>>a[i][j];
        }
    }
    for(int qw=0;qw<k;qw++)
    {
        if(qw%2==0)
        {
            MAX=0;
            for(int i=0;i<n;i++)
            {
              //  cout<<b[i]<<" "<<t[i]<<endl;
                if(b[i]>=t[i])
                    continue;
                if((t[i]-b[i])%2==0)
                {
                    p=(t[i]+b[i])/2;
                    if(a[i][p]>MAX)
                    {
                        MAX=a[i][p];
                        ind=i;
                    }
                }
                else
                {
                    p=(t[i]+b[i])/2;
                    if(2*a[i][p]>MAX)
                    {
                        MAX=2*a[i][p];
                        ind=i;
                    }
                }
            }
            ans1+=a[ind][b[ind]];
            b[ind]++;
        }
        else
        {
            MAX=0;
            for(int i=0;i<n;i++)
            {
               // cout<<b[i]<<" "<<t[i]<<endl;
                if(b[i]>=t[i])
                    continue;
              //  cout<<"*";
                if((t[i]-b[i])%2==0)
                {
                    p=(t[i]+b[i])/2-1;
                    if(a[i][p]>MAX)
                    {
                        MAX=a[i][p];
                        ind=i;
                    }
                }
                else
                {
                    p=(t[i]+b[i])/2;
                    if(2*a[i][p]>MAX)
                    {
                        MAX=2*a[i][p];
                        ind=i;
                    }
                }
            }
            ans2+=a[ind][t[ind]-1];
            t[ind]--;
        }
    }
    cout<<ans1<<" "<<ans2<<endl;
}