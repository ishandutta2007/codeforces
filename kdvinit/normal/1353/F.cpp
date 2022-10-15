#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
        int n,m;
        cin>>n>>m;
        long long int a[n][m],oper[n][m],diff,temp,ans=1000000000000000000,cntr=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++) cin>>a[i][j];
        }

        for(int i1=0;i1<n;i1++)
        {
            for(int j1=0;j1<m;j1++)
            {
                temp=a[i1][j1]-i1-j1;
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<m;j++)
                    {
                        diff=a[i][j]-temp-i-j;
                        if(diff<0) {oper[i][j]=1000000000000000000; continue;}
                        if(i==0 && j==0) { oper[i][j]=diff; continue;}
                        //if(i==0 && oper[i][j-1]==-1) { oper[i][j]=-1; continue;}
                        //if(j==0 && oper[i-1][j]==-1) { oper[i][j]=-1; continue;}
                        if(i==0) {oper[i][j]=diff+oper[i][j-1]; continue;}
                        if(j==0) {oper[i][j]=diff+oper[i-1][j]; continue;}
                        //if(oper[i-1][j]==-1 && oper[i][j-1]==-1) { oper[i][j]=-1; continue;}
                        //if(oper[i-1][j]=-1) {oper[i][j]=oper[i][j-1]; continue;}
                        //if(oper[i][j-1]=-1) {oper[i][j]=oper[i-1][j]; continue;}
                        oper[i][j]=diff+min(oper[i-1][j],oper[i][j-1]);
                    }
                }
                /*
                if(oper[n-1][m-1]==1000000000000000) continue;
                if(cntr==0)
                {
                    ans=oper[n-1][m-1];
                    cntr++;
                }
                */
                if(oper[n-1][m-1]<ans) ans=oper[n-1][m-1];
            }
        }
        cout<<ans<<endl;
        t--;
    }
    return 0;
}