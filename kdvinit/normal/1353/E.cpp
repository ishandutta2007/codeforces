#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        //cout<<endl<<"------------------------------------------------"<<endl;
        int n,k;
        cin>>n>>k;
        int a[n+k],sum=0,ans=n,m;
        if(n%k==0) m=n/k;
        else m=n/k+1;
        for(int i=n;i<n+k;i++) a[i]=2;
        for(int i=0;i<n;i++)
        {
            char x;
            cin>>x;
            if(x=='1') a[i]=1;
            else a[i]=0;
            sum+=a[i];
        }
        if(sum==0 || sum==1) {cout<<0<<endl; continue;}
        if(k==1 && sum==n) {cout<<0<<endl; continue;}
        for(int i=0;i<k;i++)
        {
            //cout<<endl<<i<<" - "<<endl;
            int cnt=0,cntr=0,strt=0,j,mn=0,mx=-n,val[m+1],mnval[m+1];
            mnval[0]=0;
            val[0]=0;
            for(j=i;j<n;j+=k)
            {
                //cout<<a[j];
                if(a[j]==1) strt++;
                cnt++;
                if(strt==0)
                {
                    cnt=0;
                    continue;
                }
                if(a[j]!=a[j+k])
                {
                    cntr++;
                    if(cntr%2==1) val[cntr]=val[cntr-1]+cnt;
                    else val[cntr]=val[cntr-1]-cnt;
                    cnt=0;
                    mnval[cntr]=min(mnval[cntr-1],val[cntr]);
                }
            }
            if(a[j-k]==0) cntr--;

            for(int i1=cntr;i1>0;i1--)
            {
                ans=min(ans,sum+mnval[i1]-val[i1]);
            }

            //for(j=1;j<=cntr;j++) cout<<val[j]<<" ";
            /*
            for(int i1=0;i1<cntr;i1+=2)
            {
                for(int j1=i1+1;j1<=cntr;j1+=2)
                {
                    int tmpans=val[i1]+sum-val[j1];
                    ans=min(ans,tmpans);
                }
            }
            */
        }
        cout<<ans<<endl;
    }
    return 0;
}