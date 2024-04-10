#include <iostream>
#include<algorithm>

using namespace std;

long long k,t=-1,ind=2,m;
char c[2000][2000];

int main()
{
    cin>>k;
    for(int i=0;i<2000;i++)
        for(int j=0;j<2000;j++)
            c[i][j]='N';
    while(k>0)
    {
        t++;
        m=k%10;
        k=k/10;
        if(m==0)
            continue;
        if(t>0)
            for(int u=0;u<10;u++)
            {
                ind++;
                c[ind][1]='Y';
                c[1][ind]='Y';
            }
        for(int j=1;j<t;j++)
            for(int u=0;u<10;u++)
            {
                ind++;
                for(int v=1;v<=10;v++)
                {
                    c[ind][ind-v-u]='Y';
                    c[ind-v-u][ind]='Y';
                }
            }
        if(t>0)
            for(int u=0;u<m;u++)
            {
                ind++;
                for(int v=1;v<=10;v++)
                {
                    c[ind][ind-v-u]='Y';
                    c[ind-v-u][ind]='Y';
                }
            }
        else
            for(int u=0;u<m;u++)
            {
                ind++;
                c[ind][1]='Y';
                c[1][ind]='Y';
            }
        ind++;
        for(int u=1;u<=m;u++)
        {
            c[ind][ind-u]='Y';
            c[ind-u][ind]='Y';
        }
        for(int j=t+2;j<=11;j++)
        {
            ind++;
            c[ind][ind-1]='Y';
            c[ind-1][ind]='Y';
        }
        c[ind][2]='Y';
        c[2][ind]='Y';
    }
    cout<<ind<<endl;
    for(int i=1;i<=ind;i++)
    {
        for(int j=1;j<=ind;j++)
            cout<<c[i][j];
        cout<<endl;
    }
}