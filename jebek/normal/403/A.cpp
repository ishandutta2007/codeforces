#include <iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int t,n,m,k;
bool mark[30][30];

int main()
{
    cin>>t;
    for(int qw=0;qw<t;qw++)
    {
        memset(mark,false,sizeof mark);
        cin>>n>>m;
        k=n;
        while(k-5>=5)
        {
            for(int i=k-4;i<=k;i++)
                for(int j=i+1;j<=k;j++)
                {
                    mark[i][j]=true;
                    mark[j][i]=true;
                }
            k-=5;
        }
        if(k==5)
        {
            for(int i=k-4;i<=k;i++)
                for(int j=i+1;j<=k;j++)
                {
                    mark[i][j]=true;
                    mark[j][i]=true;
                }
        }
        if(k==6)
        {
            for(int i=k-5;i<=k;i++)
                for(int j=i+1;j<=k;j++)
                {
                    mark[i][j]=true;
                    mark[j][i]=true;
                }
            mark[1][2]=false;
            mark[2][1]=false;
            mark[3][4]=false;
            mark[4][3]=false;
            mark[5][6]=false;
            mark[6][5]=false;
        }
        if(k==7)
        {
            for(int i=1;i<=3;i++)
                for(int j=4;j<=7;j++)
                {
                    mark[i][j]=true;
                    mark[j][i]=true;
                }
            mark[7][4]=true;
            mark[4][7]=true;
            mark[5][6]=true;
            mark[6][5]=true;
        }
        if(k==8)
        {
            for(int i=1;i<=4;i++)
                for(int j=5;j<=8;j++)
                {
                    mark[i][j]=true;
                    mark[j][i]=true;
                }
        }
        if(k==9)
        {
            for(int i=1;i<=3;i++)
                for(int j=2;j<=3;j++)
                {
                    mark[i][j]=true;
                    mark[j][i]=true;
                }
            for(int i=4;i<=6;i++)
                for(int j=5;j<=6;j++)
                {
                    mark[i][j]=true;
                    mark[j][i]=true;
                }
            for(int i=7;i<=9;i++)
                for(int j=8;j<=9;j++)
                {
                    mark[i][j]=true;
                    mark[j][i]=true;
                }
            k=1;
            for(int i=0;i<3;i++)
                for(int j=1;j<3;j++)
                {
                    mark[i*3+k][j*3+k]=true;
                    mark[j*3+k][i*3+k]=true;
                }
            k=2;
            for(int i=0;i<3;i++)
                for(int j=1;j<3;j++)
                {
                    mark[i*3+k][j*3+k]=true;
                    mark[j*3+k][i*3+k]=true;
                }
            k=3;
            for(int i=0;i<3;i++)
                for(int j=1;j<3;j++)
                {
                    mark[i*3+k][j*3+k]=true;
                    mark[j*3+k][i*3+k]=true;
                }
        }
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
            {
                if(mark[i][j])
                {
                    cout<<i<<" "<<j<<endl;
                    continue;
                }
                if(m>0)
                {
                    cout<<i<<" "<<j<<endl;
                    m--;
                }
            }
    }
}